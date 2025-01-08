/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:37:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/08 20:06:32 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_loop_hook(void *param)
{
	t_game	*game;

	game = param;
	if (game->map.object.exit_status == APPEAR
		&& game->player.current.x == game->map.object.exit_point.x
		&& game->player.current.y == game->map.object.exit_point.y)
	mlx_close_window(game->mlx);
}