/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:15:27 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/07 17:16:34 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	parser(t_game *game, int argc, char *argv[])
{
	if (argc < 2 || ft_is_invalid_argv(argc, argv))
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	game->file.path = argv[1];
	game->file.fd = open(argv[1], O_RDONLY);
	if (game->file.fd < 0)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	close(game->file.fd);
	while (*argv[1] && *argv[1] != '.')
		argv[1]++;
	if (ft_strncmp(argv[1], ".ber", -1))
		ft_exit(ERROR_MSG, EXIT_FAILURE);
}

void	count_objects(t_map *map, int x, int y)
{
	if (map->grid[y][x] == EMPTY_SPACE)
		map->object.count.empty_space++;
	else if (map->grid[y][x] == WALL)
		map->object.count.wall++;
	else if (map->grid[y][x] == COLLECTBLE)
		map->object.count.collectible++;
	else if (map->grid[y][x] == EXIT)
		map->object.count.exit++;
	else if (map->grid[y][x] == PLAYER)
		map->object.count.player++;
	else if (map->grid[y][x] != EMPTY_SPACE 
		&& map->grid[y][x] != WALL
		&& map->grid[y][x] != COLLECTBLE
		&& map->grid[y][x] != EXIT
		&& map->grid[y][x] != PLAYER)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
}

void	clear_map(t_map *map)
{
	if (map->grid)
		ft_split_free(map->grid);
}

void	clear_file(t_file *file)
{
	t_list	*tmp;

	while (file->read)
	{
		tmp = file->read;
		file->read = file->read->next;
		free(tmp);
	}
}

void	clear(t_game *game)
{
	clear_file(&game->file);
	clear_map(&game->map);
}

char	*split_line(char *line)
{
	// int		len;
	// char	*row;

	// len = 0;
	// while (line[len] && line[len] != '\n')
	// 	len++;
	// row = (char *)malloc(sizeof(char) * (len + 1));
	// if (!row)
	// 	return (NULL);
	
	char *nl = ft_strchr(line, '\n');
	size_t nl_len;
	if (!nl)
		nl_len = ft_strlen(line);
	else
		nl_len = nl - line;
	return ft_substr(line, 0, nl_len);
	// row[len] = '\0';
	// while (len-- > 0)
	// 	row[len] = line[len];
	// ft_memcpy(row, line, len);
	// return (row);
}

int	count_width(char *line)
{
	int	width;

	if (!line)
		return (0);
	width = 0;
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
}

int	count_height(t_list *read)
{
	int	height;

	if (!read)
		return (0);
	height = ft_lstsize(read);
	return (height);
}