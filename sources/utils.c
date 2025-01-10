/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:15:27 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/10 20:58:03 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*split_line(char *line)
{
	char	*nl;
	size_t	nl_len;

	nl = ft_strchr(line, '\n');
	if (!nl)
		nl_len = ft_strlen(line);
	else
		nl_len = nl - line;
	return (ft_substr(line, 0, nl_len));
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

void	render_image(mlx_t *mlx, mlx_image_t *image, t_point point)
{
	mlx_image_to_window(mlx, image, point.x * GRID_SIZE, point.y * GRID_SIZE);
}

void	clear(t_game *game, bool status)
{
	t_list	*tmp;

	while (game->file.read)
	{
		tmp = game->file.read;
		game->file.read = game->file.read->next;
		free(tmp);
	}
	ft_split_free(game->map.grid);
	if (status == EXIT_FAILURE)
		ft_exit(ERROR_MSG, EXIT_FAILURE);
	if (status == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
}
