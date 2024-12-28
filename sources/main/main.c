/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:33:48 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/25 19:52:50 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	so_long(t_game *game)
{
	game->status = READY;
	window_init(game);
	gameplay(game);
}

void	init(t_game *game, void *path)
{
	game->status = LOADING;
	ft_bzero(game, sizeof(game));
	map_setup(game, path);
	validate_map(game);
	game_setup(game);
}

void	parser(int argc, char *argv[])
{
	if (argc < 2 || ft_is_invalid_argv(argc, argv))
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	// bad_extension(argv[1]);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	parser(argc, argv);
	init(&game, argv[1]);
	so_long(&game);
}
