/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:49:19 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/21 01:18:57 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	count_map_objects(t_count_objects *count, t_map *map)
{
	t_point	point;

	point.y = 0;
	while (point.y < map->height)
	{
		point.x = 0;
		while (point.x < map->width)
		{
			// printf("[%d][%d]: %c\n", point.y, point.x, map->grid[point.y][point.x]);
			if (map->grid[point.y][point.x] == EMPTY_SPACE)
				count->empty_space++;
			else if (map->grid[point.y][point.x] == WALL)
				count->wall++;
			else if (map->grid[point.y][point.x] == COLLECTBLE)
				count->collectible++;
			else if (map->grid[point.y][point.x] == EXIT)
				count->exit++;
			else if (map->grid[point.y][point.x] == PLAYER)
				count->player++;
			count->total++;
			point.x++;
		}
		point.y++;
	}
	printf("empty_space: %d\nwall: %d\ncollectible: %d\nexit: %d\nplayer: %d\ntotal: %d\n", count->empty_space, count->wall, count->collectible, count->exit, count->player, count->total);
}

static void	validate_map_objects(t_count_objects *count, t_map *map)
{
	if (count->exit > EXIT_MAXIMUM || count->player > PLAYER_MAXIMUM)
		set_map_status(map, EXCESSIVE_OBJECT);
	else if (count->collectible < COLLECTBLE_MINIMUM)
		set_map_status(map, MISSING_OBJECT);
	else if (count->wall < WALL_MINIMUM)
		set_map_status(map, INCORRECT_BORDER);
	// printf("wall minimum: %d\n", WALL_MINIMUM);
}

void	validate_map(t_map *map)
{
	t_count_objects	count;

	printf("[ validate map ]\n---------------------------------------------\n");
	ft_memset(&count, 0, sizeof(count));
	count_map_objects(&count, map);
	validate_map_objects(&count, map);
	printf("---------------------------------------------\n");
}