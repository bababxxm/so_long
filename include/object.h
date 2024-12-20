/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:31:17 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/19 18:45:16 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef enum e_object_type
{
	WALL,
	COLLECTIBLE,
	EMPTY_SPACE,
	EXIT,
	PLAYER,
	ENEMY
}	t_object_type;

typedef struct s_floor
{
	unsigned int	width;
	unsigned int	height;
}	t_floor;

typedef struct s_wall
{
	unsigned int	count;
}	t_wall;

typedef struct s_collectibles
{
	unsigned int	count;
	unsigned int	total;
}	t_collectible;

typedef enum e_exit_status
{
	HIDDEN,
	APPEAR
}	t_exit_status;

typedef struct s_exit
{
	t_point			point;
	t_exit_status	status;
}	t_exit;

#endif