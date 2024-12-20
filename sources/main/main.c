/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:33:48 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/21 00:21:13 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// void	clear_program(t_game *game)
// {
// }

// void	so_long(t_game *game)
// {
// 	run();
// }

void	init(t_game *game, void *path)
{
	ft_memset(game, 0, sizeof(game));
	map_setup(&game->map, path);
	validate_map(&game->map);
	// process_MLX();
}

void	parser(int argc, char *argv[])
{
	if (argc < 2 || ft_is_invalid_argv(argc, argv))
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	// verify_fd(argv[1]); // only file names, fd, bla bla
	// verify_map(); // check ?  nah in init
	// verify_objects(); could be? nah
	// verify_gameplay(); nah? three below should be in init
}

int	main(int argc, char *argv[])
{
	t_game	game;

	parser(argc, argv);
	init(&game, argv[1]);
	// so_long(&game);
	// clear_program(&game);
	// exit(EXIT_SUCCESS);
}
