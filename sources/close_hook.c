/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:37:38 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/08 20:04:16 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_close_hook(void *param)
{
	t_game	*game;

	if (!param)
		return ;
	game = param;
	mlx_terminate(game->mlx);
}