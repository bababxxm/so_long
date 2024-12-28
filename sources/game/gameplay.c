/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:28:57 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 21:59:24 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	game_loop_hook(void *param)
{
	t_game	*game;

	game = param;
}

static void	game_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(game, game->player.standing.up.image, UP);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(game, game->player.standing.down.image, DOWN);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player(game, game->player.standing.left.image, LEFT);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player(game, game->player.standing.right.image, RIGHT);
	}
}

static void	game_close_hook(void *param)
{
	t_game	*game;

	if (!param)
		return ;
	game = param;
}

void	gameplay(t_game *game)
{
	mlx_loop_hook(game->mlx, &game_loop_hook, game);
	mlx_key_hook(game->mlx, &game_key_hook, game);
	mlx_close_hook(game->mlx, &game_close_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}