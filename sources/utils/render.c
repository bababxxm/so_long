/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:39:55 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 23:23:52 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	render_image(mlx_t *mlx, mlx_image_t *image, t_point point, int32_t depth)
{
	mlx_image_to_window(mlx, image, point.x * GRID_SIZE, point.y * GRID_SIZE);
	// mlx_set_instance_depth(image->instances, depth);
}

static void	render_exit(mlx_t *mlx, t_exit *exit, t_point point, int32_t depth)
{
	render_image(mlx, exit->hidden.image, point, depth);
	render_image(mlx, exit->appear.image, point, depth);
}

static void	render_player(mlx_t *mlx, t_player *player, t_point point, int32_t depth)
{
	render_image(mlx, player->standing.down.image, point, depth);
	render_image(mlx, player->standing.up.image, point, depth);
	render_image(mlx, player->standing.left.image, point, depth);
	render_image(mlx, player->standing.right.image, point, depth);
	render_image(mlx, player->moving.up.image, point, depth);
	render_image(mlx, player->moving.down.image, point, depth);
	render_image(mlx, player->moving.left.image, point, depth);
	render_image(mlx, player->moving.right.image, point, depth);
}

void	render_map(mlx_t *mlx, t_player *player, t_map *map)
{
	t_point	point;

	point.y = -1;
	while (++point.y < map->height)
	{
		point.x = -1;
		while (++point.x < map->width)
		{
			render_image(mlx, map->object.empty_space.source.image, point, 1);
			if (map->grid[point.y][point.x] == WALL)
			{
				render_image(mlx, map->object.wall.source.image, point, 1);
				printf("wall %d %d\n", point.x, point.y);
			}
			if (map->grid[point.y][point.x] == COLLECTBLE)
			{
				render_image(mlx, map->object.collectible.source.image, point, 1);
				printf("collectible %d %d\n", point.x, point.y);
			}
			if (map->grid[point.y][point.x] == EXIT)
			{
				render_exit(mlx, &map->object.exit, point, 1);
				printf("exit %d %d\n", point.x, point.y);
			}
			if (map->grid[point.y][point.x] == PLAYER)
			{
				render_player(mlx, player, point, 1);
				printf("player %d %d\n", point.x, point.y);
			}
				printf("============================\n");
			
		}
	}
}	
