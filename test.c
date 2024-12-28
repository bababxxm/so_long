/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:28:56 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/24 16:33:51 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(3096, 512, "test", false);
	mlx_loop(mlx);
}