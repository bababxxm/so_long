/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:29:46 by sklaokli          #+#    #+#             */
/*   Updated: 2024/12/28 19:27:52 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/includes/libft.h"
# include "../libraries/get_next_line/includes/get_next_line.h"
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/MLX42/include/MLX42/MLX42_Int.h"

# include "point.h"
# include "object.h"
# include "player.h"
# include "map.h"
# include "game.h"

# define GAME "so_long"

# define GRID_SIZE 32

# define WINDOW_MAX_WIDTH 3840
# define WINDOW_MAX_HEIGHT 2160

# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define EXIT_MAXIMUM 1
# define PLAYER_MAXIMUM 1
# define OBJECT_MINIMUM 1
# define WALL_MINIMUM (map->width * 2) + (2 * (map->height - 2))

# define EMPTY_SPACE_SOURCE "./assets/object/empty_space.png"
# define WALL_SOURCE "./assets/object/wall.png"
# define COLLECTIBLE_SOURCE "./assets/object/collectible.png"
# define EXIT_HIDDEN_SOURCE "./assets/object/exit_hidden.png"
# define EXIT_APPEAR_SOURCE "./assets/object/exit_appear.png"

# define STANDING_UP_SOURCE "./assets/player/standing_up.png"
# define STANDING_DOWN_SOURCE "./assets/player/standing_down.png"
# define STANDING_LEFT_SOURCE "./assets/player/standing_left.png"
# define STANDING_RIGHT_SOURCE "./assets/player/standing_right.png"
# define MOVING_UP_SOURCE "./assets/player/moving_up.png"
# define MOVING_DOWN_SOURCE "./assets/player/moving_down.png"
# define MOVING_LEFT_SOURCE "./assets/player/moving_left.png"
# define MOVING_RIGHT_SOURCE "./assets/player/moving_right.png"

# define ERROR_MSG "Error"

# define MLX_INITIALIZATION_FAILED_MSG "MLX Initialization Failed"
# define MLX_INVALID_SOURCE_MSG "MLX Invalid Source"
# define MEMORY_ALLOCATION_FAILED_MSG "Memory Allocation Failed"
# define EMPTY_FILE_MSG "Empty File"
# define INVALID_FILE_DESCRIPTOR_MSG "Invalid File Descriptor"
# define INVALID_FILE_TYPE_MSG "Invalid File Type"
# define BAD_EXTENSION_MSG "Bad Extension"
# define UNDEFINED_PARAMETER_MSG "Undefined Parameter"
# define NON_RECTANGULAR_MSG "Non Rectangular"
# define INCORRECT_BORDER_MSG "Incorrect Boarder"
# define MISSING_OBJECT_MSG "Missing Object"
# define EXCESSIVE_OBJECT_MSG "Excessive Object"
# define PLAYER_TRAPPED_MSG "Player Trapped"
# define EXIT_BLOCKED_MSG "Exit Blocked"
# define COLLECTIBLE_BLOCKED_MSG "Collectible Blocked"
# define VALID_MAP_MSG "Valid Map"

bool	is_undefined_parameter(char grid_tile);
void	map_setup(t_game *game, void *path);
void	validate_map(t_game *game);
void	set_map_status(t_map *map, t_map_status status);
void	boardcast_map_status(t_map_status status);
void	setup_path(t_map *map, t_tile *path);
void	setup_assets(mlx_t *mlx, t_source_mlx *source, void *path);
void	window_init(t_game *game);
void	game_setup(t_game *game);
void	window_init(t_game *game);
void	gameplay(t_game *game);
void	render_map(mlx_t *mlx, t_player *player, t_map *map);
void	move_player(t_game *game, mlx_image_t *image, t_direction direction);
void	setup_player_path(t_map *map, t_player *player);
void	setup_path(t_map *map, t_tile *path);
void	reset_player_stage(mlx_t *mlx, t_player *player);

#endif