/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:40:12 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/24 00:16:00 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	is_undefined_parameter(char grid_tile)
{
	if (grid_tile == EMPTY_SPACE)
		return (false);
	else if (grid_tile == WALL)
		return (false);
	else if (grid_tile == COLLECTBLE)
		return (false);
	else if (grid_tile == EXIT)
		return (false);
	else if (grid_tile == PLAYER)
		return (false);
	return (true);
}

void	set_map_status(t_map *map, t_map_status status)
{
	if (status == INCORRECT_BORDER)
		map->status = INCORRECT_BORDER;
	else if (status == NON_RECTANGULAR)
		map->status = NON_RECTANGULAR;
	else if (status == MISSING_OBJECT)
		map->status = MISSING_OBJECT;
	else if (status == EXCESSIVE_OBJECT)
		map->status = EXCESSIVE_OBJECT;
	else if (status == PLAYER_TRAPPED)
		map->status = PLAYER_TRAPPED;
	else if (status == EXIT_BLOCKED)
		map->status = EXIT_BLOCKED;
	else if (status == COLLECTIBLE_BLOCKED)
		map->status = COLLECTIBLE_BLOCKED;
	else if (status == VALID_MAP)
		map->status = VALID_MAP;
}

void	boardcast_map_status(t_map_status status)
{
	if (status == INCORRECT_BORDER)
		printf("map status: %s\n", INCORRECT_BORDER_MSG);
	else if (status == NON_RECTANGULAR)
		printf("map status: %s\n", NON_RECTANGULAR_MSG);
	else if (status == MISSING_OBJECT)
		printf("map status: %s\n", MISSING_OBJECT_MSG);
	else if (status == EXCESSIVE_OBJECT)
		printf("map status: %s\n", EXCESSIVE_OBJECT_MSG);
	else if (status == PLAYER_TRAPPED)
		printf("map status: %s\n", PLAYER_TRAPPED_MSG);
	else if (status == EXIT_BLOCKED)
		printf("map status: %s\n", EXIT_BLOCKED_MSG);
	else if (status == COLLECTIBLE_BLOCKED)
		printf("map status: %s\n", COLLECTIBLE_BLOCKED_MSG);
	else if (status == VALID_MAP)
		printf("map status: %s\n", VALID_MAP_MSG);
}
