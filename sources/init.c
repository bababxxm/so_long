/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:14:55 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/08 19:52:37 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// init_data

void	render_map(mlx_t *mlx, t_source *source, t_map *map)
{
	t_point	point;

	point.y = -1;
	while (++point.y < map->height)
	{
		point.x = -1;
		while (++point.x < map->width)
		{
			mlx_image_to_window(mlx, source->empty_space.image,
					point.x * GRID_SIZE, point.y * GRID_SIZE);
			if (map->grid[point.y][point.x] == WALL)
				mlx_image_to_window(mlx, source->wall.image,
					point.x * GRID_SIZE, point.y * GRID_SIZE);
			else if (map->grid[point.y][point.x] == COLLECTBLE)
				mlx_image_to_window(mlx, source->collectible.image,
					point.x * GRID_SIZE, point.y * GRID_SIZE);
			else if (map->grid[point.y][point.x] == EXIT)
				mlx_image_to_window(mlx, source->exit_hidden.image,
					point.x * GRID_SIZE, point.y * GRID_SIZE);
			else if (map->grid[point.y][point.x] == PLAYER)
				mlx_image_to_window(mlx, source->player_down.image,
					point.x * GRID_SIZE, point.y * GRID_SIZE);
		}
	}
}

void	init_image(mlx_t *mlx, t_source_mlx *source, void *path)
{
	source->texture = mlx_load_png(path);
	if (!source->texture)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	source->image = mlx_texture_to_image(mlx, source->texture);
	if (!source->image)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
}

void	init_assets(mlx_t *mlx, t_source *source)
{
	init_image(mlx, &source->empty_space, EMPTY_SPACE_SOURCE);
	init_image(mlx, &source->wall, WALL_SOURCE);
	init_image(mlx, &source->collectible, COLLECTIBLE_SOURCE);
	init_image(mlx, &source->exit_hidden, EXIT_HIDDEN_SOURCE);
	init_image(mlx, &source->exit_appear, EXIT_APPEAR_SOURCE);
	init_image(mlx, &source->player_up, PLAYER_UP_SOURCE);
	init_image(mlx, &source->player_down, PLAYER_DOWN_SOURCE);
	init_image(mlx, &source->player_left, PLAYER_LEFT_SOURCE);
	init_image(mlx, &source->player_right, PLAYER_RIGHT_SOURCE);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init(game->map.width * GRID_SIZE,
			game->map.height * GRID_SIZE, GAME, true);
	if (!game->mlx)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	mlx_set_window_limit(game->mlx, 0, WINDOW_MAX_WIDTH, 0, WINDOW_MAX_HEIGHT);
	mlx_set_window_pos(game->mlx, 0, 0);
}

// init_map

void	validate_map(t_map *map, t_player *player)
{
	t_point	point;

	point.y = -1;
	while (++point.y < map->height)
	{
		point.x = -1;
		while (++point.x < map->width)
		{
			count_objects(map, point.x, point.y);
			if ((point.y == 0 || point.y == map->height - 1)
				&& map->grid[point.y][point.x] != WALL)
				ft_exit(ERROR_MSG, EXIT_FAILURE);
			if ((point.x == 0 || point.x == map->width - 1)
				&& map->grid[point.y][point.x] != WALL)
				ft_exit(ERROR_MSG, EXIT_FAILURE);
			if (map->grid[point.y][point.x] == PLAYER)
				player->current = point;
			if (map->grid[point.y][point.x] == EXIT)
				map->object.exit_point = point;
		}
	}
	if (map->object.count.exit != 1 || map->object.count.player != 1)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	else if (map->object.count.collectible < 1)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	// printf("empty_space: %zd\nwall: %zd\ncollectible: %zd\nexit: %zd\nplayer: %zd\n", 
	// 		map->object.count.empty_space,
	// 		map->object.count.wall,
	// 		map->object.count.collectible,
	// 		map->object.count.exit,
	// 		map->object.count.player);
}

void	init_grid(t_map *map, t_list *read)
{
	int	i;

	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	i = -1;
	while (++i < map->height)
	{
		map->grid[i] = split_line(read->content);
		if (!map->grid[i])
			ft_exit(ERROR_MSG, EXIT_FAILURE);
		free(read->content);
		read = read->next;
	}
	map->grid[i] = NULL;
	// i = -1;
	// while (map->grid[++i])
	// 	printf("grid[%d]:\t%s\n", i, map->grid[i]);
}

void	read_file(t_map *map, t_file *file)
{
	file->fd = open(file->path, O_RDONLY);
	if (!file->fd)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	file->line = get_next_line(file->fd);
	if (!file->line)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	file->read = NULL;
	map->width = count_width(file->line);
	while (file->line)
	{
		ft_lstadd_back(&file->read, ft_lstnew(file->line));
		file->line = get_next_line(file->fd);
		if (!file->line)
			break ;
		if (map->width != count_width(file->line)) 
			ft_exit(ERROR_MSG, EXIT_FAILURE);
	}
	map->height = count_height(file->read);
	// printf("width: %zd height: %zd\n", map->width, map->height);
	close(file->fd);
}

void	initialize_map_data(t_map *map)
{
	map->grid = NULL;
	map->object.exit_status = HIDDEN;
	map->object.count.empty_space = 0;
	map->object.count.wall = 0;
	map->object.count.collectible = 0;
	map->object.count.exit = 0;
	map->object.count.player = 0;
}
