/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:36:43 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/08 18:34:17 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/includes/libft.h"
# include "../libraries/get_next_line/includes/get_next_line.h"
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/MLX42/include/MLX42/MLX42_Int.h"

# include "define.h"
# include "typedef.h"

void	parser(t_game *game, int argc, char *argv[]);
void	read_file(t_map *map, t_file *file);
void	init_grid(t_map *map, t_list *read);
void	validate_map(t_map *map, t_player *player);
int		count_width(char *line);
int		count_height(t_list *read);
char	*split_line(char *line);
void	initialize_map_data(t_map *map);
void	count_objects(t_map *map, int x, int y);
void	init_mlx(t_game *game);
void	init_assets(mlx_t *mlx, t_source *source);
void	render_map(mlx_t *mlx, t_source *source, t_map *map);
void	clear_file(t_file *file);
void	clear_map(t_map *map);
void	clear(t_game *game);
void	ft_loop_hook(void *param);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_close_hook(void *param);

#endif