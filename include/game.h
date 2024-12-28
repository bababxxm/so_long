/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:06:05 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/23 04:38:26 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_file
{
	int		fd;
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
	t_file			file;
	t_map			map;
	t_player		player;
	t_game_status	status;
}	t_game;

#endif