/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:40:12 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/21 01:08:31 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
	// printf("map status: %d\n", status);
}
