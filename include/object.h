/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:31:17 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 21:42:35 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef enum e_object_type
{
	E_WALL,
	E_COLLECTIBLE,
	E_EMPTY_SPACE,
	E_EXIT,
	E_PLAYER,
	E_ENEMY
}	t_object_type;

typedef struct s_tile
{
	t_point			point;
	t_object_type	object;
}	t_tile;

typedef struct s_wall
{
	ssize_t			count;
	t_source_mlx	source;
}	t_wall;

typedef struct s_collectible
{
	ssize_t			count;
	ssize_t			collected;
	t_source_mlx	source;
}	t_collectible;

typedef struct s_empty_space
{
	ssize_t			count;
	t_source_mlx	source;
}	t_empty_space;

typedef struct s_floor
{
	ssize_t	width;
	ssize_t	height;
}	t_floor;

typedef enum e_exit_status
{
	HIDDEN,
	APPEAR
}	t_exit_status;

typedef struct s_exit
{
	ssize_t			count;
	t_source_mlx	hidden;
	t_source_mlx	appear;
	t_exit_status	status;
}	t_exit;

#endif