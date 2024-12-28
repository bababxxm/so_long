/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:17:41 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 23:32:51 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	check_move(t_game *game, t_direction direction)
{
	game->player.move.target = game->player.position.current;
	if (direction == UP)
		game->player.move.target.y -= 1;
	else if (direction == DOWN)
		game->player.move.target.y += 1;
	else if (direction == LEFT)
		game->player.move.target.x -= 1;
	else if (direction == RIGHT)
		game->player.move.target.x += 1;
	if (game->player.move.target.x < 0 
		|| game->player.move.target.y < 0
		|| game->player.move.target.x > game->map.width - 1
		|| game->player.move.target.y > game->map.height - 1
		|| game->map.grid[game->player.move.target.y] \
		[game->player.move.target.x] == WALL)
		return ;
	game->player.position.current.x = game->player.move.target.x;
	game->player.position.current.y = game->player.move.target.y;
	game->player.move.count++;
}

void	move_player(t_game *game, mlx_image_t *image, t_direction direction)
{
	check_move(game, direction);
	reset_player_stage(game->mlx, &game->player);
	image->instances->enabled = true;
	image->instances->x = game->player.position.current.x * GRID_SIZE;
	image->instances->y = game->player.position.current.y * GRID_SIZE;
	printf("moves: %zd\n", game->player.move.count);
	if (game->map.grid[game->player.move.target.y] \
		[game->player.move.target.x] == COLLECTBLE)
	{
		game->player.collectible.collected++;
		printf("collected: %zd\n", game->player.collectible.collected);
		game->map.grid[game->player.move.target.y] \
		[game->player.move.target.x] = EMPTY_SPACE;
		mlx_image_to_window(game->mlx, game->map.object.empty_space.source.image,
			game->player.position.current.x * GRID_SIZE, 
			game->player.position.current.y * GRID_SIZE);
		image->instances->enabled = false;
		mlx_image_to_window(game->mlx, game->player.standing.down.image,
			game->player.position.current.x * GRID_SIZE, 
			game->player.position.current.y * GRID_SIZE);
		game->player.standing.down.image->instances->enabled = true;
	}
}
