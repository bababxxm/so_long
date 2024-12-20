# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaoklitudent.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:44:55 by sklaokli          #+#    #+#              #
#    Updated: 2024/12/17 16:22:41 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Libraries
NAME	=	so_long
LIBFT	=	$(LIB_DIR)/libft
GNL		=	$(GNL_DIR)/get_next_line

## Paths to files
SRC_DIR	=	sources
OBJ_DIR	=	objects
INC_DIR	=	include
LIB_DIR	=	libraries/libft
GNL_DIR	=	libraries/get_next_line

## Source files
SRC		=	$(SRC_DIR)/main/main.c \
			$(SRC_DIR)/init/map_setup.c $(SRC_DIR)/init/validate_map.c \
			$(SRC_DIR)/utils/map_utils.c

INC		=	$(INC_DIR)/so_long.h

## Convert *.c files into *.o files
OBJ		=	$(SRC:%.c=%.o)

## Commands
RM		=	rm -f
CC		=	cc
LIBC	=	ar rcs
FLAGS	=

## Color Codes
CYAN	=	\033[0;36m
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
YELLOW	=	\033[0;33m
RESET	=	\033[0m

## Targets
%.o:		%.c
			@ $(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@ $(MAKE) -sC $(LIB_DIR)
			@ $(MAKE) -sC $(GNL_DIR)
			@ echo "$(BLUE)Building so_long...$(RESET)"
			@ $(CC) $(FLAGS) $(OBJ) $(LIBFT) $(GNL) -o $(NAME)
			@ echo "$(GREEN)Done! so_long is now ready.$(RESET)"

clean:
			@ $(RM) -rf $(OBJ)
			@ $(MAKE) -sC $(LIB_DIR) clean
			@ $(MAKE) -sC $(GNL_DIR) clean
			@ echo "$(CYAN)All so_long object files have been cleaned.$(RESET)"

fclean:
			@ $(RM) -rf $(OBJ) $(NAME)
			@ $(MAKE) -sC $(LIB_DIR) fclean
			@ $(MAKE) -sC $(GNL_DIR) fclean
			@ echo "$(CYAN)All so_long executable files have been cleaned.$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re
