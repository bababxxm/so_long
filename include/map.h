/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:30:53 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/20 23:55:38 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_direction;

typedef enum e_map_status
{
	NON_RECTANGULAR,
	INCORRECT_BORDER,
	MISSING_OBJECT,
	EXCESSIVE_OBJECT,
	PLAYER_TRAPPED,
	EXIT_BLOCKED,
	COLLECTIBLE_BLOCKED,
	VALID_MAP,
}	t_map_status;

typedef struct s_tile
{
	t_point			point;
	t_object_type	object;
}	t_tile;

typedef struct s_map_objects
{
	t_exit			exit;
	t_floor			floor;
	t_collectible	collectible;
}	t_map_objects;

typedef struct s_map
{
	char			**grid;
	unsigned int	width;
	unsigned int	height;
	t_map_status	status;
	t_map_objects	objects;
}	t_map;

#endif