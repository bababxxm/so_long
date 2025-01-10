/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:46:16 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/10 20:38:31 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_source_mlx
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;
}	t_source_mlx;

typedef enum e_exit_status
{
	HIDDEN,
	APPEAR
}	t_exit_status;

typedef struct s_count
{
	ssize_t	empty_space;
	ssize_t	wall;
	ssize_t	collectible;
	ssize_t	exit;
	ssize_t	player;
}	t_count;

typedef struct s_source
{
	t_source_mlx	empty_space;
	t_source_mlx	wall;
	t_source_mlx	collectible;
	t_source_mlx	exit_hidden;
	t_source_mlx	exit_appear;
	t_source_mlx	player_up;
	t_source_mlx	player_down;
	t_source_mlx	player_left;
	t_source_mlx	player_right;
}	t_source;

typedef struct s_object
{
	t_count			count;
	t_point			exit_point;
	t_exit_status	exit_status;
}	t_object;

typedef enum e_map_status
{
	UNDEFINED_PARAMETER,
	NON_RECTANGULAR,
	INCORRECT_BORDER,
	MISSING_OBJECT,
	EXCESSIVE_OBJECT,
	OBJECT_BLOCKED,
	VALID_MAP
}	t_map_status;

typedef struct s_map
{
	char			**grid;
	char			**tab;
	ssize_t			width;
	ssize_t			height;
	t_object		object;
	t_map_status	status;
}	t_map;

#endif