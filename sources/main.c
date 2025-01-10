/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:14:45 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/10 20:39:22 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	gameplay(t_game *game)
{
	init_mlx(game);
	init_assets(game->mlx, &game->source);
	render_map(game->mlx, &game->source, &game->map);
	mlx_key_hook(game->mlx, &ft_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

static void	init(t_game *game)
{
	init_data(game);
	read_file(&game->map, &game->file);
	init_grid(&game->map, game->file.read);
	validate_map(&game->map, &game->player);
	validate_gameplay(game, &game->map, &game->player);
}

static void	parser(t_game *game, int argc, char *argv[])
{
	if (argc < 2 || ft_is_invalid_argv(argc, argv))
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	game->file.path = argv[1];
	game->file.fd = open(argv[1], O_RDONLY);
	if (game->file.fd < 0)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	close(game->file.fd);
	while (*argv[1] && *argv[1] != '.')
		argv[1]++;
	if (ft_strncmp(argv[1], ".ber", -1))
		ft_exit(ERROR_MSG, EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	parser(&game, argc, argv);
	init(&game);
	gameplay(&game);
	clear(&game, EXIT_SUCCESS);
}
