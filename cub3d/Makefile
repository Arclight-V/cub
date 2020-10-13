# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/19 14:24:49 by anatashi          #+#    #+#              #
#    Updated: 2020/10/13 19:37:08 by anatashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CC = gcc
OPFLAGS = -O2
FLAGS = -Wall -Wextra -Werror 
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADER		=	header/
GAME_DIR	=	game/
PARSER_DIR	=	parser/
TOOLS_DIR	=	tools/
GAME_LIST	=	cub3d.c \
				structure_initialization_one.c\
				sorting_of_distances_of_sprites.c\
				make_map.c \
				make_windows.c \
				keystroke.c\
				first_horisont_intersection.c\
				first_vertical_intersection.c\
				horizontal_intersection_with_wall.c\
				vertical_intersection_with_wall.c\
				calculating_nearest_distance_to_wall.c\
				loop_hook.c\
				drawing_screen.c\
				drawing_walls.c\
				calculation_of_parameters_of_sprites.c\
				drawing_sprites.c\
				rendered_image_in_bmp.c\
				game_exit.c\
				structure_initialization_two.c\
				calculation_constant_values.c\
				checking_direction.c \
				raycasting.c\
				render_next_frame.c\
				take_texture_parameters.c\
				search_player_and_sprites.c\
				calculating_wall_length_in_one_slice.c\
				freeing_memory_from_win_structure.c\
				freeing_memory_from_list.c\
				freeing_memory_from_sprite_texture.c\
				freeing_memory_from_map_structure.c\
				freeing_memory_from_fd_structure.c\
				freeing_memory_from_data_structure.c\
				freeing_memory_form_wall_texture.c\
				ft_close.c
		
PARSER_LIST	=	parser_of_scene.c \
				checking_resolution.c\
				checking_validity_map.c\
				ft_creat_list.c\
				checking_textures_wall.c\
				checking_textures_sprite.c\
				checking_color.c\
				check_forbid_characters_map.c\
				checking_map.c

TOOLS_LIST	=	ft_skip_spaces.c\
				ft_add_space.c\
				ft_atoi_mod.c\
				ft_error_output.c \
				ft_max_len.c\
				my_mlx_pixel_put.c\
				get_color_pixel.c

LIBFT_DIR	 =	libft/
MLX_DIR 	= 	mlx/
MLX_NAME	= 	libmlx.dylib


SOURCE_GAME	=	$(addprefix $(GAME_DIR), $(GAME_LIST))
SOURCE_PARSER =	$(addprefix $(PARSER_DIR), $(PARSER_LIST))
SOURCE_TOOLS =	$(addprefix $(TOOLS_DIR), $(TOOLS_LIST)) 

OBJ	= $(patsubst %.c, %.o, $(SOURCE_GAME) $(SOURCE_PARSER) $(SOURCE_TOOLS))
D_FILES = $(patsubst %.c, %.d, $(SOURCE_GAME) $(SOURCE_PARSER) $(SOURCE_TOOLS))

.PHONY: all clean fclean re test 

all: lib mlxlib $(NAME)

lib:
	make -C $(LIBFT_DIR)

mlxlib:
	make -C $(MLX_DIR)
	
$(NAME): $(OBJ)
	cp $(MLX_DIR)$(MLX_NAME) . 
	$(CC) -o $(NAME) $(FLAGS) $(OPFLAGS) $(MLX_FLAGS) $(MLX_NAME) -L$(LIBFT_DIR) -lft $(OBJ)
	
%.o: %.c $(HEADER)cub3d.h
	$(CC) $(FLAGS) $(OPFLAGS) -I$(HEADER) -c $< -o $@ -MD

include $(wildcard $(D_FILE))

clean :
	rm -rf $(OBJ) $(D_FILES)
	rm -rf $(NAME).bmp
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(NAME)
	rm -rf ./libmlx.dylib

re : fclean all

test:
	./cub3D maps/cub2.cub
