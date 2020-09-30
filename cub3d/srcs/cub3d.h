/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:02:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/30 19:31:56 by anatashi         ###   ########.fr       */
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

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define CUBE_SIZE 64
# define FOV M_PI / 3




# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define UP 126
# define SPACE 49
# define SHIFT 257
# define TURN 0.3

# define NORD 0
# define SOUTH 1
# define WEST 2
# define EAST 3


# define MALLOC_1 "Error : Malloc fail (initializing_structure_of_structures)"
# define MALLOC_2 "Error : Malloc fail (initializing_map_structure)"
# define MALLOC_3 "Error : Malloc fail (initializing_err_structure)"
# define MALLOC_4 "Error : Malloc fail (initializing_fd_structure)"
# define MALLOC_5 "Error : Malloc fail (initializing_win_structure)"
# define MALLOC_6 "Error : Malloc fail (initializing_const_values_structure)"
# define MALLOC_7 "Error : Malloc fail (initializing_nord_wall_structure)"
# define MALLOC_8 "Error : Malloc fail (initializing_south_wall_structure)"
# define MALLOC_9 "Error : Malloc fail (initializing_west_wall_structure)"
# define MALLOC_10 "Error : Malloc fail (initializing_east_wall_structure)"
# define MALLOC_11 "Error : Malloc fail (initializing_slice_parameters_structure_structure)"
# define MALLOC_12 "Error : Malloc fail (checking_textures_wall)"
# define MALLOC_13 "Error : Malloc fail (checking_textures_sprite)"
# define FD_1 "Error : Couldn't read fd (CUB)"
# define FD_2 "Error : Couldn't read fd (Texture of the wall)"
# define FD_3 "Error : Couldn't read fd (checking_textures_sprite)"
# define RESOLUTION_1 "Error : Resolution specified twice"
# define RESOLUTION_2 "Error : Invalid resolution"
# define TEXTURE_1 "Error : Texture of the wall image twice"
# define TEXTURE_2 "Error : Texture of the wall information contains invalid characters"
# define TEXTURE_3 "Error : Not available image format of the wall"

# define TEXTURE_4 "Error : Texture of the sprite image twice"
# define TEXTURE_5 "Error : Texture of the sprite information contains invalid characters"
# define TEXTURE_6 "Error : Not available image format of the sprite"


/*
** file descriptor for reading the map
*/
typedef struct		s_fd
{
	int				fd;
	int				ret;
	size_t			max_len;
	int				flag;
	int				count_ind;
	int				flag_sprite;
	char			*filename;
}					t_fd;


/*
** error counter
*/
typedef struct		s_err 
{
	int				num;
}					t_err;

/*
** level map
*/
typedef struct		s_map 
{
	char			**level;
	int				x;
	int				y;
	int				item;
	int				size;
	int				x_p;
	int				y_p;
	double				x_pp;
	double				y_pp;
	double				x_horizont;
	double				y_horizont;
	double				X_a_h;
	double				Y_a_h;
	double				x_vertical;
	double				y_vertical;
	double				X_a_v;
	double				Y_a_v;
	double			PDvsPE;
	double			a_p;
	double			angle_start;
	double			c;
	double			PD;
	double			PE;
	int				flagPDPE;
	int				i;
	int				yyy;
}					t_map;


typedef struct	s_constValue 
{
	double		DistanceProjectionPlan;
	int			CenterProjection;
	double		delta_ray;
	int			xMapMax;
	int			yMapMax;
	double		ratio_of_texture_height_to_CUBE_SIZE_NORD;
	double		ratio_of_texture_height_to_CUBE_SIZE_South;
	double		ratio_of_texture_height_to_CUBE_SIZE_EAST;
	double		ratio_of_texture_height_to_CUBE_SIZE_WEST;
	double		thiry_degrees;
	double		two_pi;
	double		tree_pi_by_two;
}				t_ConstValue;

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
	int			bits_per_pixel;
	int			endian;
	int			x;
	int			y;
}				  t_win;

/*
** structure for textures
*/


typedef struct	s_wall
{
	char			*adr;
	void			*img;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

}					t_wall;


typedef struct	s_sprite
{
	char			*adr;
	void			*img;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				x;
	int				y;
	double			sprite_angle;
	double			distance;
	double			sprite_screen_size_full;
	double			sprite_screen_size_half;
	double			sprite_screen_size_coor;
	double			sprite_width;
	int				position_sprite;
	int				h_offset;
	int				v_offset;

}					t_sprite;


typedef struct	s_dataWall
{
	double 		ProjectedSliceHeight[2560];
	double 		ProjectedSliceHeightNotCorr[2560];
	int			PositionWall[2560];
	int			yCoordinateInTexture[2560];
	char		CardinalDirections[2560];
	int			OfsetX[2560];
	double			scalingIndex[2560];
	double		distance_wall[2560];
	double		distance_wall_not_corr[2560];
	int			index;
}				t_dataWall;

typedef struct	s_tre
{
	double		distance;
	int			num;
	struct		s_tre *left;
	struct  	s_tre *right;
}				t_tre;

/*
** structure of pointers to the structure
*/
typedef struct		s_all 
{	
	t_map			*map;
	t_err			*err;
	t_fd			*fd;
	t_win			*win;
	t_ConstValue	*ConstValue;
	t_dataWall		*dataWall;
	t_wall			*wall;
	t_sprite		*sprite;
}					t_all;



/*
** structure of pointers to the structure
*/


t_all		*initializing_structures(t_all *s);

/*
** structure initialization
*/
t_map			*initializing_map_structure();
t_err			*initializing_err_structure();
t_fd			*initializing_fd_structure();
t_win			*initializing_win_structure();
t_ConstValue	*initializing_const_values_structure();
t_wall			*initializing_wall_structure(t_wall *wall);
t_dataWall		*initializing_slice_parameters_structure();
t_sprite		*ft_creat_sprite_s();
t_all			*initializing_structure_of_structures(t_all *s);



/*
**	parser
*/
t_list		*parser_of_scene(char *cub, t_all *s, t_list *head);
t_list		*ft_add_space(t_list **head, t_all *s);
int			checking_validity_map(t_list *head, char *line, t_all *s);
t_list		*ft_creat_list(t_list *head, t_all *s, char *line);
void		ft_max_len(t_list **head, t_all *s);
// int		ft_creat_list(t_list *head, t_all *s, char *line);
/*
**	parser tools:
*/

int			ft_forb_char_map(t_list **head, char *line, t_all *s, int *i);
int			checking_resolution(t_all *s, char *line, int *i);
int			checking_textures_wall(t_all *s, char *line, int *i, int num);
int			checking_textures_sprite(t_all *s, char *line, int *i);
int			*sorting_of_distances_of_sprites(t_all *s, int *array_of_sequence_numbers_of_sprites);
void		take_texture_parameters(t_win *win, t_wall *wall, int i, char *filename);

/*
**	tools:
*/
int			ft_skip_spaces(char *line, int *i);
int			ft_strerror(int err);
int			ft_atoi_mod(const char *nptr, int *i);
int			ft_errorstr(char *str, int num);
int			ft_strnstrindex(char *big, char *little);
char		**make_map(t_list **head, int size, t_all *s);


/*
**	functions for drawing the screen
*/

int			make_windows(t_all *s, t_win *win);
int			render_next_frame(t_all *s);
void 		raycasting(t_all *s, t_dataWall *dataWall);
int			drawing_screen(t_all *s, t_dataWall *dataWall);
void		calculatingDeltaForHorizontalIntersection(t_all *s, float a_p);
void		calculatingDeltaForVerticallIntersection(t_all *s, float a_p);
void		checking_coordinates_h(t_all *s);
void		checking_coordinates_v(t_all *s);
void		calculating_wall_length_in_one_slice(t_all *s, t_dataWall *dataWall);
int			loop_hook(t_all *s, void *mlx, void *win);
void		drawing_celing(t_all *s);
void		drawing_walls(t_all *s, t_dataWall *dataWall);
void		drawing_floor(t_all *s);
void		drawing_sprites(t_all *s);
int			take_texture_parameters_sprite(t_all *s, int item, char *filename);
int			search_player_and_sprites(t_all *s);
void		calculation_constant_values(t_all *s);


int			ft_key(int keycode, t_all *s);
void		ft_move_forward_back(t_all *s, int i);
void		ft_rotate(t_all *s, int i);
void		ft_move_left_right(t_all *s, int i);
/*
** free memory
*/
void 	ft_freearrmap(char **map);
void	lstdelone_f(void *d);


#endif
