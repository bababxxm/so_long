/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:36:43 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/10 21:13:11 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/includes/libft.h"
# include "../libraries/get_next_line/includes/get_next_line.h"
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/MLX42/include/MLX42/MLX42_Int.h"

# include "player.h"
# include "map.h"
# include "game.h"

# define GAME "so_long"

# define GRID_SIZE 32

# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define EMPTY_SPACE_SOURCE "./assets/object/empty_space.png"
# define WALL_SOURCE "./assets/object/wall.png"
# define COLLECTIBLE_SOURCE "./assets/object/collectible.png"
# define EXIT_HIDDEN_SOURCE "./assets/object/exit_hidden.png"
# define EXIT_APPEAR_SOURCE "./assets/object/exit_appear.png"

# define PLAYER_UP_SOURCE "./assets/player/standing_up.png"
# define PLAYER_DOWN_SOURCE "./assets/player/standing_down.png"
# define PLAYER_LEFT_SOURCE "./assets/player/standing_left.png"
# define PLAYER_RIGHT_SOURCE "./assets/player/standing_right.png"

# define ERROR_MSG "Error"

void	read_file(t_map *map, t_file *file);
void	init_grid(t_map *map, t_list *read);
void	validate_map(t_map *map, t_player *player);
int		count_width(char *line);
int		count_height(t_list *read);
char	*split_line(char *line);
void	init_data(t_game *game);
void	count_objects(t_map *map, int x, int y);
void	init_mlx(t_game *game);
void	init_assets(mlx_t *mlx, t_source *source);
void	init_image(mlx_t *mlx, t_source_mlx *source, void *path);
void	render_image(mlx_t *mlx, mlx_image_t *image, t_point point);
void	render_map(mlx_t *mlx, t_source *source, t_map *map);
void	clear(t_game *game, bool status);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	validate_gameplay(t_game *game, t_map *map, t_player *player);

#endif