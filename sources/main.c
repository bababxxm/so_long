/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:14:45 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/08 20:03:41 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_long(t_game *game)
{
	game->player.moves = 0;
	game->player.collected = 0;
	game->map.object.exit_status = HIDDEN;
	mlx_loop_hook(game->mlx, &ft_loop_hook, game);
	mlx_key_hook(game->mlx, &ft_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

void	init(t_game *game)
{
	read_file(&game->map, &game->file);
	initialize_map_data(&game->map);
	init_grid(&game->map, game->file.read);
	validate_map(&game->map, &game->player);
	init_mlx(game);
	init_assets(game->mlx, &game->source);
	render_map(game->mlx, &game->source, &game->map);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	parser(&game, argc, argv);
	init(&game);
	so_long(&game);
	// clear(&game);
}
