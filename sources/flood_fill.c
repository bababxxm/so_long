/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:37:59 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/10 20:50:39 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**ft_matrix_dup(char **mtx)
{
	int		idx;
	int		size;
	int		len;
	char	**res;

	if (!mtx)
		return (NULL);
	size = 0;
	while (mtx[size])
		size++;
	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		len = ft_strlen(mtx[idx]);
		res[idx] = malloc(sizeof(char) * (len + 1));
		if (!res[idx])
			return (ft_split_free(res), NULL);
		ft_strlcpy(res[idx], mtx[idx], len + 1);
		idx++;
	}
	res[idx] = NULL;
	return (res);
}

void	flood_fill(t_map *map, t_count *count, int row, int col)
{
	if (row < 0 || col < 0 || row >= map->height || col >= map->width)
		return ;
	if (map->tab[row][col] == 'F' || map->tab[row][col] == WALL)
		return ;
	if (map->tab[row][col] == COLLECTBLE)
		count->collectible++;
	if (map->tab[row][col] == EXIT)
		count->exit++;
	if (map->tab[row][col] == PLAYER)
		count->player++;
	map->tab[row][col] = 'F';
	flood_fill(map, count, row - 1, col);
	flood_fill(map, count, row + 1, col);
	flood_fill(map, count, row, col - 1);
	flood_fill(map, count, row, col + 1);
}

void	validate_gameplay(t_game *game, t_map *map, t_player *player)
{
	t_count	count;

	count.collectible = 0;
	count.exit = 0;
	count.player = 0;
	if (map->status != VALID_MAP)
		clear(game, EXIT_FAILURE);
	map->tab = ft_matrix_dup(map->grid);
	flood_fill(map, &count, player->current.y, player->current.x);
	if (!(map->object.count.collectible == count.collectible
			&& count.exit == 1 && count.player == 1))
		map->status = OBJECT_BLOCKED;
	ft_split_free(map->tab);
}
