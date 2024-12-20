/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:06:05 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/20 02:23:26 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

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
	t_map			map;
	t_player		player;
	t_game_status	status;
}	t_game;

#endif