/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:02:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/29 11:27:57 by anatashi         ###   ########.fr       */
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
# define FD_1 "Error : Couldn't read fd"
# define RESOLUTION_1 "Error : Resolution specified twice"
# define RESOLUTION_2 "Error : Invalid resolution"


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

typedef struct	s_nord
{
	char			*adr;
	void			*img;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

}					t_nord;

typedef struct	s_south
{
	char			*adr;
	void			*img;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

}					t_south;

typedef struct	s_east
{
	char			*adr;
	void			*img;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

}					t_east;

typedef struct	s_west
{
	char			*adr;
	void			*img;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

}					t_west;

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
	t_nord			*nord;
	t_south			*south;
	t_west			*west;
	t_east			*east;
	t_sprite		*sprite;
}					t_all;



/*
** structure of pointers to the structure
*/


int		initializing_structures(char *cub);

/*
** structure initialization
*/
t_map			*initializing_map_structure();
t_err			*initializing_err_structure();
t_fd			*initializing_fd_structure();
t_win			*initializing_win_structure();
t_ConstValue	*initializing_const_values_structure();
t_nord			*initializing_nord_wall_structure();
t_south			*initializing_south_wall_structure();
t_east			*initializing_east_wall_structure();
t_west			*initializing_west_wall_structure();
t_dataWall		*initializing_slice_parameters_structure();
t_sprite		*ft_creat_sprite_s();
t_all			*initializing_structure_of_structures();



/*
**	parser
*/
int			ft_parser(char *cub, t_all *s);
t_list		*ft_add_space(t_list **head, t_all *s);
int			checking_validity_map(t_list *head, char *line, t_all *s);
t_list		*ft_creat_list(t_list *head, t_all *s, char *line);
void		ft_max_len(t_list **head, t_all *s);
// int		ft_creat_list(t_list *head, t_all *s, char *line);
/*
**	parser tools:
*/

int			ft_forb_char_map(t_list **head, char *line, t_all *s, int *i);
int			ft_checking_resolution(t_list **head, char *line, t_all *s, int *i);
int			ft_checking_textures(t_all *s);
int			checking_sprites(t_all *s);
int			*sorting_of_distances_of_sprites(t_all *s, int *array_of_sequence_numbers_of_sprites);
/*
**	tools:
*/
int			ft_skip_spaces(char *line, int *i);
int			ft_strerror(int err);
int			ft_atoi_mod(const char *nptr, int *i);
int			ft_errorstr(char *str, int num);
/*
** free memory
*/
void 	ft_freearrmap(char **map);
void	lstdelone_f(void *d);


#endif
