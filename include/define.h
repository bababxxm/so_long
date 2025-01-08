/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:39:17 by sklaokli          #+#    #+#             */
/*   Updated: 2025/01/07 17:37:34 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define GAME "so_long"

# define GRID_SIZE 32

# define WINDOW_MAX_WIDTH 3840
# define WINDOW_MAX_HEIGHT 2160

# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define ERROR_MSG "Error"

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

#endif
