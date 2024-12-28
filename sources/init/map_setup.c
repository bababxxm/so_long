/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:09:02 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/24 17:07:39 by sklaokli         ###   ########.fr       */
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

static void	grid_setup(t_map *map, t_file *file)
{
	int	i;

	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		perror(MEMORY_ALLOCATION_FAILED_MSG);
	i = -1;
	while (++i < (int)map->height)
	{
		map->grid[i] = ft_split(file->read->content, '\n')[0];
		if (!map->grid[i])
			perror(MEMORY_ALLOCATION_FAILED_MSG);
		file->read = file->read->next;
	}
	i = -1;
	while (map->grid[++i])
		printf("grid[%d]:\t%s\n", i, map->grid[i]);
}

static void	read_file(t_map *map, t_file *file, void *path)
{
	char	*line;

	file->fd = open(path, O_RDONLY);
	if (file->fd < 0)
		perror(INVALID_FILE_DESCRIPTOR_MSG);
	line = get_next_line(file->fd);
	if (!line)
		perror(EMPTY_FILE_MSG);
	file->read = NULL;
	map->width = count_width(line);
	while (line)
	{
		ft_lstadd_back(&file->read, ft_lstnew(line));
		line = get_next_line(file->fd);
		if (!line)
			break ;
		if (map->width != count_width(line))
			perror(NON_RECTANGULAR_MSG);
	}
	map->height = count_height(file->read);
	close(file->fd);
}

void	map_setup(t_game *game, void *path)
{
	printf("---------------------------------------------\n");
	printf("[ map set up ]\n---------------------------------------------\n");
	game->map.status = VALID_MAP;
	read_file(&game->map, &game->file, path);
	printf("map width: %zu\nmap height: %zu\n", game->map.width, game->map.height);
	grid_setup(&game->map, &game->file);
	printf("---------------------------------------------\n");
}
