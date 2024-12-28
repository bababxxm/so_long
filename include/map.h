/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:30:53 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 21:42:54 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_object
{
	t_empty_space	empty_space;
	t_wall			wall;
	t_collectible	collectible;
	t_exit			exit;
	ssize_t			total;
}	t_object;

typedef enum e_map_status
{
	UNDEFINED_PARAMETER,
	NON_RECTANGULAR,
	INCORRECT_BORDER,
	MISSING_OBJECT,
	EXCESSIVE_OBJECT,
	PLAYER_TRAPPED,
	EXIT_BLOCKED,
	COLLECTIBLE_BLOCKED,
	VALID_MAP
}	t_map_status;

typedef struct s_map
{
	char			**grid;
	ssize_t			width;
	ssize_t			height;
	t_object		object;
	t_floor			floor;
	t_map_status	status;
}	t_map;

#endif