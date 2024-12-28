/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:31:03 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 21:42:11 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef enum e_player_state
{
	ALIVE,
	DEAD
}	t_player_state;

typedef struct s_player_position
{
	t_point		start;
	t_point		current;
	t_direction	facing;
}	t_player_position;

typedef struct s_player_path
{
	t_tile	up;
	t_tile	down;
	t_tile	left;
	t_tile	right;
}	t_player_path;

typedef struct s_player_move
{
	ssize_t		count;
	t_point		target;
	t_point		previous;
	t_direction	direction;
}	t_player_move;

typedef struct s_player_source
{
	t_source_mlx	up;
	t_source_mlx	down;
	t_source_mlx	left;
	t_source_mlx	right;
}	t_player_source;

typedef struct s_player
{
	ssize_t				count;
	t_collectible		collectible;
	t_player_position	position;
	t_player_path		path;
	t_player_move		move;
	t_player_state		state;
	t_player_source		moving;
	t_player_source		standing;
}	t_player;

#endif