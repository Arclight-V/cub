/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_initialization_one.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 08:23:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/25 19:07:40 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		*ft_creat_map_s()
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->level = NULL;
	map->x = 0;
	map->y = 0;
	map->item = 0;
	map->size = 0;
	map->x_p = 0;
	map->y_p = 0;
	map->x_pp = 0;
	map->y_pp = 0;
	map->a_p = 0;
	map->angle_start = 0;
	map->c = 0.0;
	map->x_horizont = 0;
	map->y_horizont = 0;
	map->X_a_h = 0;
	map->Y_a_h = 0;
	map->x_vertical = 0;
	map->y_vertical = 0;
	map->X_a_v = 0;
	map->Y_a_v = 0;
	map->PDvsPE = 0;
	map->PD = 0;
	map->PE = 0;
	map->flagPDPE = 0;
	map->i = 0;
	map->y = 0;
	return (map);
}

t_err		*ft_creat_err_s()
{
	t_err	*err;

	if (!(err = (t_err *)malloc(sizeof(t_err))))
		return (NULL);
	err->num = 0;
	return (err);
}

t_fd		*ft_creat_fd_s()
{
	t_fd	*fd;

	if (!(fd = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	fd->fd = 0;
	fd->ret = 1;
	fd->max_len = 0;
	fd->flag = 0;
	fd->count_ind = 0;
	return (fd);
}

t_win		*ft_creat_win_s()
{
	t_win	*win;

	if (!(win = (t_win *)malloc(sizeof(t_win))))
		return(NULL);
	win->mlx = NULL;
	win->win = NULL;
	win->img = NULL;
	win->addr = NULL;
	win->line_lenght = 0;
	win->bits_per_pixel = 0;
	win->endian = 0;
	win->x = 0;
	win->y = 0;
	return (win);
}

t_ConstValue		*ft_constValue_s()
{
	t_ConstValue	*constValue;

	if (!(constValue = (t_ConstValue *)malloc(sizeof(t_ConstValue))))
		return(NULL);
	constValue->DistanceProjectionPlan = 0;
	constValue->CenterProjection = 0;
	constValue->delta_ray = 0;
	constValue->xMapMax = 0;
	constValue->yMapMax = 0;
	constValue->ratio_of_texture_height_to_CUBE_SIZE_NORD = 0;
	constValue->ratio_of_texture_height_to_CUBE_SIZE_South = 0;
	constValue->ratio_of_texture_height_to_CUBE_SIZE_WEST = 0;
	constValue->ratio_of_texture_height_to_CUBE_SIZE_EAST = 0;
	constValue->thiry_degrees = M_PI / 6;
	constValue->two_pi = 2 * M_PI;
	constValue->tree_pi_by_two = 3 * M_PI_2;
	return (constValue);
}

t_all		*ft_creat_all_s()
{
	t_all	*s;

	if (!(s = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	s->map = NULL;
	s->err = NULL;
	s->fd = NULL;
	s->win = NULL;
	s->ConstValue = NULL;
	s->nord = NULL;
	s->south = NULL;
	s->east = NULL;
	s->west = NULL;
	s->dataWall = NULL;
	s->sprite = NULL; 
	return (s);
}

t_nord		*ft_creat_nord_s()
{
	t_nord *nord;

	if(!(nord = (t_nord *)malloc(sizeof(t_nord))))
		return(NULL);
	nord->adr = NULL;
	nord->bits_per_pixel = 0;
	nord->endian = 0;
	nord->height = 0;
	nord->img = 0;
	nord->size_line = 0;
	nord->width = 0;
	return(nord);
}

t_south		*ft_creat_south_s()
{
	t_south *south;

	if(!(south = (t_south *)malloc(sizeof(t_south))))
		return(NULL);
	south->adr = NULL;
	south->bits_per_pixel = 0;
	south->endian = 0;
	south->height = 0;
	south->img = 0;
	south->size_line = 0;
	south->width = 0;
	return(south);
}

t_east		*ft_creat_east_s()
{
	t_east *east;

	if(!(east = (t_east *)malloc(sizeof(t_east))))
		return(NULL);
	east->adr = NULL;
	east->bits_per_pixel = 0;
	east->endian = 0;
	east->height = 0;
	east->img = 0;
	east->size_line = 0;
	east->width = 0;
	return(east);
}

t_west		*ft_creat_west_s()
{
	t_west *west;

	if(!(west = (t_west *)malloc(sizeof(t_west))))
		return(NULL);
	west->adr = NULL;
	west->bits_per_pixel = 0;
	west->endian = 0;
	west->height = 0;
	west->img = 0;
	west->size_line = 0;
	west->width = 0;
	return(west);
}

t_sprite		*ft_creat_sprite_s()
{
	t_sprite *sprite;

	if(!(sprite = (t_sprite *)malloc(sizeof(t_sprite))))
		return(NULL);
	sprite->adr = NULL;
	sprite->bits_per_pixel = 0;
	sprite->endian = 0;
	sprite->height = 0;
	sprite->img = 0;
	sprite->size_line = 0;
	sprite->width = 0;
	sprite->x = 0;
	sprite->y = 0;
	sprite->sprite_angle = 0.0;
	sprite->distance = 0.0;
	sprite->size_line = 0;
	sprite->sprite_screen_size_full = 0.0;
	sprite->sprite_screen_size_half = 0.0;
	sprite->sprite_screen_size_coor = 0.0;
	sprite->position_sprite = 0;
	sprite->h_offset = 0;
	sprite->v_offset = 0;
	return(sprite);
}

t_dataWall		*ft_creat_dataWall_s()
{
	t_dataWall 	*dataWall;
	int			index;

	index = -1;
	if(!(dataWall = (t_dataWall *)malloc(sizeof(t_dataWall))))
		return(NULL);
	dataWall->index = -1;
	while(++index < 2560)
	{
		dataWall->ProjectedSliceHeight[index] = 0.0;
		dataWall->ProjectedSliceHeightNotCorr[index] = 0.0;
		dataWall->PositionWall[index] = 0.0;
		dataWall->CardinalDirections[index] = 0.0;
		dataWall->OfsetX[index] = 0.0;
		dataWall->scalingIndex[index] = 0.0;
		dataWall->yCoordinateInTexture[index] = 0.0;
		dataWall->distance_wall[index] = 0.0;
		dataWall->distance_wall_not_corr[index] = 0.0;
	}
	return(dataWall);
}