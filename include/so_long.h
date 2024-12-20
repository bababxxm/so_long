/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:29:46 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/21 01:22:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "point.h"
# include "object.h"
# include "map.h"
# include "player.h"
# include "game.h"

# include "../libraries/libft/includes/libft.h"
# include "../libraries/get_next_line/includes/get_next_line.h"

# define ERROR_MSG "Error"

# define EXIT_MAXIMUM 1
# define PLAYER_MAXIMUM 1
# define COLLECTBLE_MINIMUM 1
# define WALL_MINIMUM (map->width * 2) + (2 * (map->height - 2))

# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct s_file
{
	int		fd;
	char	*line;
	t_list	*read;
}	t_file;

typedef struct s_count_objects
{
	unsigned int	empty_space;
	unsigned int	wall;
	unsigned int	collectible;
	unsigned int	exit;
	unsigned int	player;
	unsigned int	total;
}	t_count_objects;

void	map_setup(t_map *map, void *path);
void	validate_map(t_map *map);
void	set_map_status(t_map *map, t_map_status status);

#endif