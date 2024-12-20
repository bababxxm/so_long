/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:31:03 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/19 18:38:36 by sklaokli         ###   ########.fr       */
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

typedef struct s_path
{
	t_tile	up;
	t_tile	down;
	t_tile	left;
	t_tile	right;
}	t_path;

typedef struct s_player_move
{
	t_point			previous;
	t_tile			target;
	t_direction		direction;
	unsigned int	count;
}	t_player_move;

typedef struct s_player
{
	t_object_type		player;
	t_player_position	position;
	t_path				path;
	t_player_move		move;
	t_player_state		state;
}	t_player;

#endif