/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:09:02 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/21 01:41:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	count_width(char *line)
{
	int	width;

	if (!line)
		return (0);
	width = 0;
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
}

static int	count_height(t_list *read)
{
	int	height;

	if (!read)
		return (0);
	height = ft_lstsize(read);
	return (height);
}

static void	grid_setup(t_file *file, t_map *map)
{
	int	i;
	int	j;

	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < map->height)
	{
		map->grid[i] = ft_split(file->read->content, '\n')[0];
		if (!map->grid[i])
			exit(EXIT_FAILURE);
		file->read = file->read->next;
	}
	i = -1;
	while (map->grid[++i])
		printf("grid[%d]:\t%s\n", i, map->grid[i]);
}

static void	read_file(t_file *file, t_map *map)
{
	int	width;
	int	height;
	
	file->line = get_next_line(file->fd);
	width = count_width(file->line);
	while (file->line)
	{
		ft_lstadd_back(&file->read, ft_lstnew(file->line));
		file->line = get_next_line(file->fd);
		if (!file->line)
			break ;
		if (width != count_width(file->line))
			set_map_status(map, NON_RECTANGULAR);
	}
	height = count_height(file->read);
	map->width = width;
	map->height = height;
}

void	map_setup(t_map *map, void *path)
{
	t_file	file;

	// file = (t_file){0, NULL, NULL};
	printf("---------------------------------------------\n");
	printf("[ map set up ]\n---------------------------------------------\n");
	file.fd = open(path, O_RDONLY);
	if (file.fd < 0)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	read_file(&file, map);
	printf("map width: %d\nmap height: %d\n", map->width, map->height);
	grid_setup(&file, map);
	printf("---------------------------------------------\n");
	// set_map_status(map, VALID_MAP);
}