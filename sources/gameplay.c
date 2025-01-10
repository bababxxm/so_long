/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:01:27 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/10 15:25:04 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	is_movable(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->width || y > map->height)
		return (false);
	if (map->grid[y][x] == WALL)
		return (false);
	return (true);
}

void	handle_object(t_game *game, t_map *map, t_player *player)
{
	t_point	target;
	t_point	current;

	target = player->target;
	current = player->current;
	if (map->grid[current.y][current.x] == EXIT)
		render_image(game->mlx, game->source.exit_hidden.image, current);
	else if (map->grid[player->current.y][player->current.x] != EXIT)
		render_image(game->mlx, game->source.empty_space.image, current);
	if (map->grid[target.y][target.x] == COLLECTBLE)
	{
		map->grid[target.y][target.x] = EMPTY_SPACE;
		player->collected++;
	}
	if (player->collected == map->object.count.collectible)
	{
		map->object.exit_status = APPEAR;
		render_image(game->mlx, game->source.exit_appear.image,
			map->object.exit_point);
	}
}

void	handle_player(t_game *game, t_player *player, mlx_image_t *direction)
{
	render_image(game->mlx, direction, player->target);
	player->moves++;
	player->current = player->target;
	ft_putnbr_fd(game->player.moves, 1);
	ft_putchar_fd('\n', 1);
	if (game->map.object.exit_status == APPEAR
		&& game->player.current.x == game->map.object.exit_point.x
		&& game->player.current.y == game->map.object.exit_point.y)
	{
		printf("You've won!\n");
		mlx_close_window(game->mlx);
	}
}

void	move_player(t_game *game, int x, int y, mlx_image_t *direction)
{
	game->player.target = game->player.current;
	game->player.target.x += x;
	game->player.target.y += y;
	if (!is_movable(&game->map, game->player.target.x, game->player.target.y))
	{
		render_image(game->mlx, direction, game->player.current);
		return ;
	}
	handle_object(game, &game->map, &game->player);
	handle_player(game, &game->player, direction);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(game, 0, -1, game->source.player_up.image);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(game, 0, 1, game->source.player_down.image);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player(game, -1, 0, game->source.player_left.image);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player(game, 1, 0, game->source.player_right.image);
	}
}
