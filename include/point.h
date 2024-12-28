/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:43:18 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 21:42:24 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_direction;

typedef struct s_point
{
	ssize_t	x;
	ssize_t	y;
}	t_point;

typedef struct s_source_mlx
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;
}	t_source_mlx;

#endif