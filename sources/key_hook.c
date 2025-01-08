/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:33:09 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/08 19:58:55 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	is_movable(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->width || y > map->height)
		return (false);
	if (map->grid[y][x] == WALL)
		return (false);
	return (true);
}

static void	move_player(t_game *game, int x, int y, mlx_image_t *player_image)
{
	mlx_t		*mlx;
	t_map		*map;
	t_player	*player;
	t_source	*source;
	t_point		target;

	mlx = game->mlx;
	map = &game->map;
	player = &game->player;
	source = &game->source;
	target = player->current;
	target.x += x;
	target.y += y;
	if (is_movable(map, target.x, target.y))
	{
		if (map->grid[player->current.y][player->current.x] == EXIT)
		{
			if (map->object.exit_status == HIDDEN)
				mlx_image_to_window(mlx, source->exit_hidden.image,
					player->current.x * GRID_SIZE, player->current.y * GRID_SIZE);
			else if (map->object.exit_status == APPEAR)
				mlx_image_to_window(mlx, source->exit_appear.image,
					player->current.x * GRID_SIZE, player->current.y * GRID_SIZE);
		}
		else
			mlx_image_to_window(mlx, source->empty_space.image,
				player->current.x * GRID_SIZE, player->current.y * GRID_SIZE);
		if (map->grid[player->current.y][player->current.x] == COLLECTBLE)
		{
			map->grid[player->current.y][player->current.x] = EMPTY_SPACE;
			player->collected++;
		}
		if (player->collected == map->object.count.collectible)
		{
			map->object.exit_status = APPEAR;
			mlx_image_to_window(mlx, source->exit_appear.image,
					map->object.exit_point.x * GRID_SIZE, map->object.exit_point.y * GRID_SIZE);
		}
		mlx_image_to_window(mlx, player_image,
			target.x * GRID_SIZE, target.y * GRID_SIZE);
		// if (map->object.exit_status == APPEAR &&)
		player->moves++;
		player->current = target;
		printf("%zd\n", game->player.moves);
		// printf("collect %zd\n", game->player.collected);
		// printf("total %zd\n", map->object.count.collectible);
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	
	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(game, 0, -1, game->source.player_up.image);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(game, 0, 1, game->source.player_down.image);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player(game, -1, 0, game->source.player_left.image);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player(game, 1, 0, game->source.player_right.image);
	}
}

