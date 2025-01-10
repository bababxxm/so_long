/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:42:58 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/10 21:16:06 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_map(mlx_t *mlx, t_source *source, t_map *map)
{
	t_point	point;

	point.y = -1;
	while (++point.y < map->height)
	{
		point.x = -1;
		while (++point.x < map->width)
		{
			render_image(mlx, source->empty_space.image, point);
			if (map->grid[point.y][point.x] == WALL)
				render_image(mlx, source->wall.image, point);
			else if (map->grid[point.y][point.x] == COLLECTBLE)
				render_image(mlx, source->collectible.image, point);
			else if (map->grid[point.y][point.x] == EXIT)
				render_image(mlx, source->exit_hidden.image, point);
			else if (map->grid[point.y][point.x] == PLAYER)
				render_image(mlx, source->player_down.image, point);
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
	mlx_delete_texture(source->texture);
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
	if (game->map.width > 121)
		clear(game, EXIT_FAILURE);
	if (game->map.height > 65)
		clear(game, EXIT_FAILURE);
	game->mlx = mlx_init(game->map.width * GRID_SIZE,
			game->map.height * GRID_SIZE, GAME, false);
	if (!game->mlx)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	mlx_set_window_pos(game->mlx, 0, 0);
}
