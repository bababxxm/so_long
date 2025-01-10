/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:14:55 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/10 20:49:17 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_objects(t_map *map, int x, int y)
{
	if (map->grid[y][x] == EMPTY_SPACE)
		map->object.count.empty_space++;
	else if (map->grid[y][x] == WALL)
		map->object.count.wall++;
	else if (map->grid[y][x] == COLLECTBLE)
		map->object.count.collectible++;
	else if (map->grid[y][x] == EXIT)
		map->object.count.exit++;
	else if (map->grid[y][x] == PLAYER)
		map->object.count.player++;
	else if (map->grid[y][x] != EMPTY_SPACE
		&& map->grid[y][x] != WALL
		&& map->grid[y][x] != COLLECTBLE
		&& map->grid[y][x] != EXIT
		&& map->grid[y][x] != PLAYER)
		map->status = UNDEFINED_PARAMETER;
}

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
		map->status = EXCESSIVE_OBJECT;
	else if (map->object.count.collectible < 1)
		map->status = MISSING_OBJECT;
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
			map->status = NON_RECTANGULAR;
	}
	map->height = count_height(file->read);
	close(file->fd);
}

void	init_data(t_game *game)
{
	game->file.read = NULL;
	game->player.moves = 0;
	game->player.collected = 0;
	game->map.tab = NULL;
	game->map.grid = NULL;
	game->map.status = VALID_MAP;
	game->map.object.exit_status = HIDDEN;
	game->map.object.count.empty_space = 0;
	game->map.object.count.wall = 0;
	game->map.object.count.collectible = 0;
	game->map.object.count.exit = 0;
	game->map.object.count.player = 0;
}
