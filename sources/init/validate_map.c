/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:49:19 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/24 17:18:22 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	count_map_objects(t_map *map, t_player *player)
{
	t_point	point;

	point.y = -1;
	while (++point.y < map->height)
	{
		point.x = -1;
		while (++point.x < map->width)
		{
			if (map->grid[point.y][point.x] == EMPTY_SPACE)
				map->object.empty_space.count++;
			else if (map->grid[point.y][point.x] == WALL)
				map->object.wall.count++;
			else if (map->grid[point.y][point.x] == COLLECTBLE)
				map->object.collectible.count++;
			else if (map->grid[point.y][point.x] == EXIT)
				map->object.exit.count++;
			else if (map->grid[point.y][point.x] == PLAYER)
				player->count++;
			map->object.total++;
		}
	}
	printf("empty_space: %zu\nwall: %zu\ncollectible: %zu \
		\nexit: %zu\nplayer: %zu\ntotal: %zu\n", map->object.empty_space.count, \
		map->object.wall.count, map->object.collectible.count, map->object.exit.count, \
		player->count, map->object.total);
}

static void	validate_map_structure(t_map *map, t_player *player)
{
	t_point	point;

	point.y = -1;
	while (++point.y < map->height)
	{
		point.x = -1;
		while (++point.x < map->width)
		{
			if ((point.y == 0 || point.y == map->height - 1)
				&& map->grid[point.y][point.x] != WALL)
				perror(INCORRECT_BORDER_MSG);
			if ((point.x == 0 || point.x == map->width - 1)
				&& map->grid[point.y][point.x] != WALL)
				perror(INCORRECT_BORDER_MSG);
			if (map->grid[point.y][point.x] == PLAYER)
				player->position.start = point;
			if (is_undefined_parameter(map->grid[point.y][point.x]))
				perror(UNDEFINED_PARAMETER_MSG);
		}
	}
}

static void	validate_map_objects(t_map *map, t_player *player)
{
	if (map->object.exit.count > EXIT_MAXIMUM
		|| player->count > PLAYER_MAXIMUM)
		perror(EXCESSIVE_OBJECT_MSG);
	else if (map->object.collectible.count < OBJECT_MINIMUM
		|| map->object.exit.count < OBJECT_MINIMUM
		|| player->count < OBJECT_MINIMUM)
		perror(MISSING_OBJECT_MSG);
	else if (map->object.wall.count < WALL_MINIMUM)
		perror(INCORRECT_BORDER_MSG);
}

void	initialize_object_count(t_map *map, t_player *player)
{
	map->object.empty_space.count = 0;
	map->object.wall.count = 0;
	map->object.collectible.count = 0;
	map->object.exit.count = 0;
	player->count = 0;
}

void	validate_map(t_game *game)
{
	printf("[ validate map ]\n---------------------------------------------\n");
	initialize_object_count(&game->map, &game->player);
	count_map_objects(&game->map, &game->player);
	validate_map_objects(&game->map, &game->player);
	validate_map_structure(&game->map, &game->player);
	printf("---------------------------------------------\n");
}
