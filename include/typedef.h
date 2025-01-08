/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:39:15 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/08 19:51:43 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

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

typedef enum e_exit_status
{
	HIDDEN,
	APPEAR
}	t_exit_status;

typedef struct s_player
{
	t_point	current;
	t_point	target;
	ssize_t	moves;
	ssize_t	collected;
}	t_player;

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

typedef struct s_map
{
	char		**grid;
	ssize_t		width;
	ssize_t		height;
	t_object	object;
}	t_map;

typedef struct s_file
{
	int		fd;
	void	*path;
	char	*line;
	t_list	*read;
}	t_file;

typedef enum e_game_status
{
	LOADING,
	ERROR,
	READY,
	RUNNING,
	CLOSED,
	FINISHED
}	t_game_status;

typedef struct s_game
{
	mlx_t			*mlx;
	t_source		source;
	t_file			file;
	t_map			map;
	t_player		player;
	t_game_status	status;
}	t_game;

#endif