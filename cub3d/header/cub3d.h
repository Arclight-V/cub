/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:02:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/13 19:36:14 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/header/libft.h"
# include "../mlx/mlx.h"

/*
** constants to avoid repeated multiplication
*/
# define CUBE 64
# define FOV M_PI / 3
# define M_PI_6 0.52359877559829882
# define TWO_PI 6.2831853071795862
# define TREE_PI_ON_2 4.7123889803846897

/*
** key code of the keyboard keys
*/
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

/*
** index of the sides of the walls
*/
# define NORD 0
# define SOUTH 1
# define WEST 2
# define EAST 3

/*
** the text of the error output
*/
# define MALLOC_1 "Error : Malloc fail (initializing_structure_of_structures)"
# define MALLOC_2 "Error : Malloc fail (initializing_map_structure)"
# define MALLOC_3 "Error : Malloc fail (initializing_fd_structure)"
# define MALLOC_4 "Error : Malloc fail (initializing_win_structure)"
# define MALLOC_5 "Error : Malloc fail (initializing_cnst_structure)"
# define MALLOC_6 "Error : Malloc fail (initializing_wall_structure)"
# define MALLOC_7 "Error : Malloc fail (init_slice_parameters_structure)"
# define MALLOC_8 "Error : Malloc fail (checking_textures_wall)"
# define MALLOC_9 "Error : Malloc fail (checking_textures_sprite)"
# define MALLOC_10 "Error : Malloc fail (ft_creat_list (ft_lstnew))"
# define MALLOC_11 "Error : Malloc fail (ft_add_space (ft_str_add_chr))"
# define MALLOC_12 "Error : Malloc fail (make_map (ft_calloc))"
# define MALLOC_13 "Error : Malloc fail (take_texture_parameters)"
# define MALLOC_14 "Error : Malloc fail (creating_array_for_ray (wall_h))"
# define MALLOC_15 "Error : Malloc fail (creating_array_for_ray(wall_hfull))"
# define MALLOC_16 "Error : Malloc fail (creating_array_for_ray(celing_h))"
# define MALLOC_17 "Error : Malloc fail (creating_array_for_ray(y_image))"
# define MALLOC_18 "Error : Malloc fail (creating_array_for_ray(side_of_world))"
# define MALLOC_19 "Error : Malloc fail (creating_array_for_ray(x_image))"
# define MALLOC_20 "Error : Malloc fail (creating_array_for_ray(distance_wall))"
# define MALLOC_21 "Error : Malloc fail (distance_wall_not_corr)"
# define MALLOC_22 "Error : Malloc fail (distan_of_sprites)"
# define MALLOC_23 "Error : Malloc fail (sorting_of_distances_of_sprites)"
# define FD_1 "Error : Couldn't read fd (CUB)"
# define FD_2 "Error : Readed fd complited with error (get_next_line)"
# define FD_3 "Error : Couldn't read fd (checking_textures_wall)"
# define FD_4 "Error : Couldn't read fd (checking_textures_sprite)"
# define RESOLUTION_1 "Error : Resolution specified twice"
# define RESOLUTION_2 "Error : Invalid resolution"
# define TEXTURE_1 "Error : Texture of the wall image twice"
# define TEXTURE_2 "Error : Texture of the wall inf-n contains invalid char-s"
# define TEXTURE_3 "Error : Not available image format of the wall"
# define TEXTURE_4 "Error : Texture of sprite image twice"
# define TEXTURE_5 "Error : Texture of sprite inf-on contains invalid char-s"
# define TEXTURE_6 "Error : Not available image format of the sprite"
# define TEXTURE_7 "Error : Broken file .xpm (sprite)"
# define TEXTURE_8 "Error : Broken file .xpm (wall)"
# define FLOOR_1 "Error : Floor/ceiling specified twice"
# define FLOOR_2 "Error : Invalid floor/celing line"
# define MAP_1 "Error : The map content information contains invalid characters"
# define MAP_2 "Error : The map content is not the last element"
# define MAP_3 "Error : The .cub scene contains invalid characters"
# define MAP_4 "Error : The map must contain only one player"
# define END "End game"

/*
** file descriptor for reading the map and flags and etc
*/

typedef struct	s_fd
{
	size_t		max_len;
	int			flag;
	int			count_ind;
	int			flag_sprite;
	char		*filename;
	int			err;
	int			i;
	int			player;
}				t_fd;

/*
** variables for calculating the rays
*/
typedef struct	s_map
{
	char		**map;
	int			item;
	int			size;
	float		x_p;
	float		y_p;
	double		x_horizont;
	double		y_horizont;
	double		xa_h;
	double		ya_h;
	double		x_vertical;
	double		y_vertical;
	double		xa;
	double		ya;
	double		a_p;
	double		first_ray;
	double		pd;
	double		pe;
	int			flag;
	int			floor;
	int			ceil;
}				t_map;

/*
** constants to avoid repeated multiplication
*/
typedef struct	s_const
{
	double		dist_projec_plan;
	int			center_project;
	double		delta_ray;
	int			x_max;
	int			y_max;
	double		ratio_of_nord_width_to_cube;
	double		ratio_of_south_width_to_cube;
	double		ratio_of_east_width_to_cube;
	double		ratio_of_west_width_to_cube;
}				t_const;

/*
** structure for window
*/
typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			line_lenght;
	int			bps;
	int			endian;
	int			x;
	int			y;
}				t_win;

/*
** structures for textures walls and spretes
*/
typedef struct	s_wall
{
	char		*filename;
	char		*adr;
	void		*img;
	int			width;
	int			height;
	int			bps;
	int			size_line;
	int			endian;
}				t_wall;

typedef struct	s_sprite
{
	char		*adr;
	void		*img;
	int			width;
	int			height;
	int			bps;
	int			size_line;
	int			endian;
	int			x;
	int			y;
	double		angle;
	double		distance;
	double		hight;
	double		hight_half;
	double		hight_coor;
	int			sprite_width;
	int			position_sprite;
	int			h_offset;
	int			v_offset;

}				t_sprite;

/*
** structure for storing data about a wall segment and an index for one-time
** traversal of all calculated data
*/

typedef	struct	s_data
{
	double		*wall_h;
	double		*wall_hfull;
	int			*celing_h;
	int			*y_image;
	char		*side_of_world;
	int			*x_image;
	double		*distance_wall;
	double		*distance_wall_not_corr;
	int			*distan_of_sprites;
	int			i;
}				t_data;

/*
** sorting by tree
*/
typedef struct	s_tre
{
	double		distance;
	int			num;
	struct s_tre* left;
	struct s_tre* right;
}				t_tre;

/*
** structure of pointers to the structure
*/
typedef struct	s_all
{
	t_map		*map;
	t_fd		*fd;
	t_win		*win;
	t_const		*cnst;
	t_data		*data;
	t_wall		*wall;
	t_sprite	*sprite;
	t_list		*head;
}				t_all;

/*
** structures for bmp file
*/
typedef struct	s_bitmap_file_header
{
	char		type[2];
	int			syze;
	short		rezerved1;
	short		rezerved2;
	int			off_bits;
}				t_bitmap_file_header;

typedef struct	s_bitmap_info_header
{
	int			size;
	int			width;
	int			heigt;
	short		planes;
	short		bit_count;
	int			compression;
	int			size_image;
	int			x_pels_per_meter;
	int			y_pels_per_meter;
	int			clr_used;
	int			clr_important;

}				t_bitmap_info_header;

/*
** structure initialization
*/
t_all			*initializing_structures(t_all *s);
t_all			*initializing_structure_of_structures(t_all *s);
t_map			*initializing_map_structure(void);
t_fd			*initializing_fd_structure(void);
t_win			*initializing_win_structure(void);
t_const			*initializing_const_values_structure(void);
t_wall			*initializing_wall_structure(t_wall *wall);
t_data			*initializing_slice_parameters_structure();
t_sprite		*ft_creat_sprite_s(void);
void			creating_array_for_ray(t_all *s);
/*
**	parser
*/
t_list			*parser_of_scene(t_all *s, t_list *head, char *cub);
void			*ft_creat_list(t_all *s, t_list *head, char *line);
void			checking_validity_map(t_all *s, char *line);
void			checking_resolution(t_all *s, char *line, int *i);
void			checking_textures_wall(t_all *s, char *line, int num);
void			checking_textures_sprite(t_all *s, char *line, int *i);
void			checking_color(t_all *s, char *line, int *color);
void			check_forbid_characters_map(t_all *s, char *line, int *i);
void			checking_map(t_all *s, int size);
/*
**	tools:
*/
t_list			*ft_add_space(t_all *s, t_list *head);
int				ft_atoi_mod(const char *nptr, int *i);
void			ft_error_output(t_all *s, char *str);
void			ft_max_len(t_all *s, t_list *head);
int				ft_skip_spaces(char *line, int *i);
int				get_color_pixel(t_data *data, char *adr, int size_line,\
							int bps);
void			my_mlx_pixel_put(t_win *win, int x, int y, int color);
/*
**	functions for drawing the screen and calculation of parameters of the rays
**	of the walls and sprites
*/
void			calculating_nearest_distance_to_wall(t_map *map, t_data *data);
void			calculating_wall_length_in_one_slice(t_all *s, t_data *data,
													t_map *map, t_const *cnst);
void			calculation_constant_values(t_all *s);
void			calculation_of_parameters_of_sprites(t_all *s, t_data *data,
											t_sprite *sprite, t_const *cnst);
void			checking_direction(double *direction);
void			take_texture_parameters(t_all *s, int item);
int				main(int argc, char **argv);
void			drawing_screen(t_all *s, t_data *data, t_map *map);
int				drawing_sprites(t_all *s, t_data *data, t_sprite *sprite,
								int i);
void			drawing_walls(t_all *s, t_data *data, t_wall *wall, int y);
void			first_horisont_intersection(t_map *map, double tang);
void			first_vertical_intersection(t_map *map, double tang);
void			horizontal_intersection_with_wall(t_map *map, t_const *cnst);
void			vertical_intersection_with_wall(t_map *map, t_const *cnst);
void			search_player_and_sprites(t_map *map, t_sprite *sprite,
											int x, int y);
int				keystroke(int keycode, t_all *s);
int				*sorting_of_distances_of_sprites(t_all *s,
				int *array_of_sequence_numbers_of_sprites);
void			make_windows(t_win *win);
int				render_next_frame(t_all *s);
void			raycasting(t_all *s, t_data *data, t_map *map, t_const *cnst);
void			loop_hook(t_all *s, void *mlx, void *win);
void			rendered_image_in_bmp(char *cub);
void			make_map(t_all *s, int size);
int				game_exit(t_all *s, int num);
int				ft_close(t_all *s);
/*
** free memory
*/
void			freeing_memory_form_wall_texture(t_wall *wall);
void			freeing_memory_from_data_structure(t_data *data);
void			freeing_memory_from_fd_structure(t_fd *fd);
void			freeing_memory_from_list(t_list *head);
void			freeing_memory_from_map_structure(t_map *map);
void			freeing_memory_from_sprite_texture(t_sprite *sprite, int i);
void			freeing_memory_from_win_structure(t_win *win);
#endif
