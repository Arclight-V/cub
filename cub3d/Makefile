# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/19 14:24:49 by anatashi          #+#    #+#              #
#    Updated: 2020/10/09 15:59:35 by anatashi         ###   ########.fr        #
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

SRCS_DIR = ./game
PARSER_DIR = ./parser
TOOLS_DIR = ./tools
SRCS = 	$(SRCS_DIR)/cub3d.c \
		$(SRCS_DIR)/structure_initialization_one.c\
		$(SRCS_DIR)/sorting_of_distances_of_sprites.c\
		$(SRCS_DIR)/make_map.c \
		$(SRCS_DIR)/make_windows.c \
		$(SRCS_DIR)/movement_of_player.c\
		$(SRCS_DIR)/first_horisont_intersection.c\
		$(SRCS_DIR)/first_vertical_intersection.c\
		$(SRCS_DIR)/horizontal_intersection_with_wall.c\
		$(SRCS_DIR)/vertical_intersection_with_wall.c\
		$(SRCS_DIR)/calculating_nearest_distance_to_wall.c\
		$(SRCS_DIR)/loop_hook.c\
		$(SRCS_DIR)/drawing_screen.c\
		$(SRCS_DIR)/drawing_walls.c\
		$(SRCS_DIR)/calculation_of_parameters_of_sprites.c\
		$(SRCS_DIR)/drawing_sprites.c\
		$(SRCS_DIR)/rendered_image_in_bmp.c\
		$(SRCS_DIR)/game_exit.c\
		$(SRCS_DIR)/structure_initialization_two.c\
		$(SRCS_DIR)/calculation_constant_values.c\
		$(SRCS_DIR)/checking_direction.c \
		$(SRCS_DIR)/raycasting.c\
		$(SRCS_DIR)/render_next_frame.c\
		$(SRCS_DIR)/take_texture_parameters.c\
		$(SRCS_DIR)/search_player_and_sprites.c\
		$(SRCS_DIR)/calculating_wall_length_in_one_slice.c\
		$(SRCS_DIR)/for_bonus.c\
		$(PARSER_DIR)/parser_of_scene.c \
		$(PARSER_DIR)/checking_resolution.c\
		$(PARSER_DIR)/checking_validity_map.c\
		$(PARSER_DIR)/ft_creat_list.c\
		$(PARSER_DIR)/checking_textures_wall.c\
		$(PARSER_DIR)/checking_textures_sprite.c\
		$(PARSER_DIR)/checking_color.c\
		$(PARSER_DIR)/check_forbid_characters_map.c\
		$(PARSER_DIR)/checking_map.c\
		$(TOOLS_DIR)/ft_skip_spaces.c\
		$(TOOLS_DIR)/ft_add_space.c\
		$(TOOLS_DIR)/ft_atoi_mod.c\
		$(TOOLS_DIR)/ft_error_output.c \
		$(TOOLS_DIR)/ft_max_len.c\
		$(TOOLS_DIR)/my_mlx_pixel_put.c
		

OBJ	= $(SRCS:%.c=%.o)
HEADER_DIR	= ./header
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