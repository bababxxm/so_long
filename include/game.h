/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:39:15 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/10 20:31:38 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_file
{
	int		fd;
	void	*path;
	char	*line;
	t_list	*read;
}	t_file;

typedef struct s_game
{
	mlx_t		*mlx;
	t_source	source;
	t_file		file;
	t_map		map;
	t_player	player;
}	t_game;

#endif