/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:07:31 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 18:39:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	setup_exit_stage(mlx_t *mlx, t_exit *exit)
{
	exit->hidden.image->instances->enabled = true;
	exit->appear.image->instances->enabled = false;
}

static void	setup_player_stage(mlx_t *mlx, t_player *player)
{
	player->standing.down.image->instances->enabled = true;
	player->standing.up.image->instances->enabled = false;
	player->standing.left.image->instances->enabled = false;
	player->standing.right.image->instances->enabled = false;
	player->moving.up.image->instances->enabled = false;
	player->moving.down.image->instances->enabled = false;
	player->moving.left.image->instances->enabled = false;
	player->moving.right.image->instances->enabled = false;
}

void	window_init(t_game *game)
{
	printf("[ window init ]\n---------------------------------------------\n");
	render_map(game->mlx, &game->player, &game->map);
	setup_exit_stage(game->mlx, &game->map.object.exit);
	setup_player_stage(game->mlx, &game->player);
	// mlx_put_string(game->mlx, "moves", 10, 10);
	printf("---------------------------------------------\n");
}