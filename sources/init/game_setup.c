/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 04:06:53 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 19:20:47 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	load_assets(mlx_t *mlx, t_object *object, t_player *player)
{
	setup_assets(mlx, &object->empty_space.source, EMPTY_SPACE_SOURCE);
	setup_assets(mlx, &object->wall.source, WALL_SOURCE);
	setup_assets(mlx, &object->collectible.source, COLLECTIBLE_SOURCE);
	setup_assets(mlx, &object->exit.hidden, EXIT_HIDDEN_SOURCE);
	setup_assets(mlx, &object->exit.appear, EXIT_APPEAR_SOURCE);
	setup_assets(mlx, &player->standing.up, STANDING_UP_SOURCE);
	setup_assets(mlx, &player->standing.down, STANDING_DOWN_SOURCE);
	setup_assets(mlx, &player->standing.left, STANDING_LEFT_SOURCE);
	setup_assets(mlx, &player->standing.right, STANDING_RIGHT_SOURCE);
	setup_assets(mlx, &player->moving.up, MOVING_UP_SOURCE);
	setup_assets(mlx, &player->moving.down, MOVING_DOWN_SOURCE);
	setup_assets(mlx, &player->moving.left, MOVING_LEFT_SOURCE);
	setup_assets(mlx, &player->moving.right, MOVING_RIGHT_SOURCE);
}

static void	setup_game_stage(t_map *map, t_player *player)
{
	player->state = ALIVE;
	player->move.count = 0;
	player->position.facing = DOWN;
	map->object.exit.status = HIDDEN;
	map->floor.width = map->width;
	map->floor.height = map->height;
	map->object.collectible.collected = 0;
	player->collectible = map->object.collectible;
	player->position.current = player->position.start;
	player->move.previous = player->position.start;
}

static void	game_mlx_init(t_game *game)
{
	game->mlx = mlx_init(game->map.width * GRID_SIZE,
			game->map.height * GRID_SIZE, GAME, true);
	if (!game->mlx)
		perror(MLX_INITIALIZATION_FAILED_MSG);
	mlx_set_window_limit(game->mlx, 0, WINDOW_MAX_WIDTH, 0, WINDOW_MAX_HEIGHT);
	mlx_set_window_pos(game->mlx, 0, 0);
}

void	game_setup(t_game *game)
{
	printf("[ game setup ]\n---------------------------------------------\n");
	game_mlx_init(game);
	setup_game_stage(&game->map, &game->player);
	load_assets(game->mlx, &game->map.object, &game->player);
	// printf("%p\n", game->map.object.empty_space.source.texture);
	// game->map.object.empty_space.source.texture = mlx_load_png("/home/sklaokli/42/cursus/cadet/Rank02/so_long/01/sources/init/empty_space.png");
	// game->map.object.empty_space.source.texture = mlx_load_png(EMPTY_SPACE_SOURCE);
	// printf("%p\n", game->map.object.empty_space.source.texture);
	// game->map.object.empty_space.source.image = mlx_texture_to_image(game->mlx, game->map.object.empty_space.source.texture);
	// mlx_image_to_window(game->mlx, game->map.object.empty_space.source.image, 0, 0);
	// mlx_image_to_window(game->mlx, game->map.object.collectible.source.image, 0, 1);
	// mlx_loop(game->mlx);
	printf("---------------------------------------------\n");
}
