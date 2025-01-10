/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:46:18 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/10 00:50:53 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_direction;

typedef struct s_point
{
	ssize_t	x;
	ssize_t	y;
}	t_point;

typedef struct s_player
{
	t_point	current;
	t_point	target;
	ssize_t	moves;
	ssize_t	collected;
}	t_player;

#endif