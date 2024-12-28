/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:14:39 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 19:22:38 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	setup_path(t_map *map, t_tile *path)
{
	if (map->grid[path->point.y][path->point.x] == WALL)
		path->object = E_WALL;
	else if (map->grid[path->point.y][path->point.x] == COLLECTBLE)
		path->object = E_COLLECTIBLE;
	else if (map->grid[path->point.y][path->point.x] == EMPTY_SPACE)
		path->object = E_EMPTY_SPACE;
	else if (map->grid[path->point.y][path->point.x] == EXIT)
		path->object = E_EXIT;
	// else if (map->grid[path->point.y][path->point.x] == ENEMY)
	// 	path->object = E_ENEMY;
}

void	reset_player_stage(mlx_t *mlx, t_player *player)
{
	player->standing.down.image->instances->enabled = false;
	player->standing.up.image->instances->enabled = false;
	player->standing.left.image->instances->enabled = false;
	player->standing.right.image->instances->enabled = false;
	player->moving.up.image->instances->enabled = false;
	player->moving.down.image->instances->enabled = false;
	player->moving.left.image->instances->enabled = false;
	player->moving.right.image->instances->enabled = false;
}

void	setup_player_path(t_map *map, t_player *player)
{
	player->path.up.point.y = player->position.current.y - 1;
	player->path.down.point.y = player->position.current.y + 1;
	player->path.left.point.x = player->position.current.x - 1;
	player->path.right.point.x = player->position.current.x + 1;
	setup_path(map, &player->path.up);
	setup_path(map, &player->path.down);
	setup_path(map, &player->path.left);
	setup_path(map, &player->path.right);
}

void	setup_assets(mlx_t *mlx, t_source_mlx *source, void *path)
{
	printf("%s\n", (char *)path);
	source->texture = mlx_load_png(path);
	if (!source->texture)
		perror(MLX_INVALID_SOURCE_MSG);
	source->image = mlx_texture_to_image(mlx, source->texture);
	if (!source->image)
		perror(MLX_INITIALIZATION_FAILED_MSG);
}