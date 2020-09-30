# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/19 14:24:49 by anatashi          #+#    #+#              #
#    Updated: 2020/09/30 17:27:02 by anatashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.dylib
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

CC = gcc
FLAGS = -Wall -Wextra -Werror 

SRCS_DIR = ./srcs
SRCS = 	$(SRCS_DIR)/cub3d.c \
		$(SRCS_DIR)/parser_of_scene.c \
		$(SRCS_DIR)/tools.c \
		$(SRCS_DIR)/structure_initialization_one.c\
		$(SRCS_DIR)/free_memory.c \
		$(SRCS_DIR)/checking_indentifiers.c \
		$(SRCS_DIR)/sorting_of_distances_of_sprites.c\
		$(SRCS_DIR)/error_output.c \
		$(SRCS_DIR)/checking_map.c \
		$(SRCS_DIR)/big.c \
		$(SRCS_DIR)/make_map.c \
		$(SRCS_DIR)/make_windows.c \
		$(SRCS_DIR)/movement_of_player.c\
		$(SRCS_DIR)/calculation_of_parameters_for_horizontal_and_vertical_lines.c \
		$(SRCS_DIR)/loop_hook.c



# SRCS = 	$(SRCS_DIR)/put_test.c \

OBJ	= $(SRCS:%.c=%.o)
HEADER_DIR	= ./srcs
HEADER = $(HEADER_DIR)/cub3d.h




all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) -I$(HEADER_DIR) -lm -L$(LIBFT_DIR) -lft $(MLX_FLAGS)

%.o: %.c $(HEADER) $(LIBFT) $(MLX)
	# $(CC) -g $(FLAGS) -I$(HEADER_DIR) -c $< -o $@
	$(CC) -g -I$(HEADER_DIR) -Imlx -c $< -o $@ 


$(LIBFT):

	make -C $(LIBFT_DIR)

$(MLX):

	make -C $(MLX_DIR)
	mv $(MLX) . 


clean :
	rm -rf $(OBJ)
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	rm -rf ./libmlx.dylib

re : fclean all

bonus : $(NAME)

valgrind:
	valgrind --leak-check=full ./cub3D maps/cub2.cub
test:
	./cub3D maps/cub2.cub