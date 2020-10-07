/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_initialization_one.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 08:23:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 16:15:40 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		*initializing_map_structure()
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->map = NULL;
	map->item = 0;
	map->size = 0;
	map->x_p = 0;
	map->y_p = 0;
	map->a_p = 0;
	map->angle_start = 0;
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
	map->floor = -1;
	map->ceil = -1;
	return (map);
}

t_fd		*initializing_fd_structure()
{
	t_fd	*fd;

	if (!(fd = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	fd->max_len = 0;
	fd->flag = 0;
	fd->count_ind = 0;
	fd->filename = NULL;
	fd->flag_sprite = 0;
	fd->err = 0;
	return (fd);
}

t_win		*initializing_win_structure()
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

t_const		*initializing_const_values_structure()
{
	t_const	*cnst;

	if (!(cnst = (t_const *)malloc(sizeof(t_const))))
		return(NULL);
	cnst->DistanceProjectionPlan = 0;
	cnst->CenterProjection = 0;
	cnst->delta_ray = 0;
	cnst->xMapMax = 0;
	cnst->yMapMax = 0;
	cnst->ratio_of_texture_height_to_CUBE_NORD = 0;
	cnst->ratio_of_texture_height_to_CUBE_South = 0;
	cnst->ratio_of_texture_height_to_CUBE_WEST = 0;
	cnst->ratio_of_texture_height_to_CUBE_EAST = 0;
	return (cnst);
}

t_all		*initializing_structure_of_structures(t_all	*s)
{

	if (!(s = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	s->map = NULL;
	s->fd = NULL;
	s->win = NULL;
	s->cnst = NULL;
	s->data = NULL;
	s->sprite = NULL; 
	s->wall = NULL;
	return (s);
}
t_wall		*initializing_wall_structure(t_wall *wall)
{
	int		i;

	i = -1;
	if(!(wall = (t_wall *)malloc(4 * (sizeof(t_wall)))))
		return(NULL);
	while (++i < 4)
	{
		wall[i].adr = NULL;
		wall[i].bits_per_pixel = 0;
		wall[i].endian = 0;
		wall[i].height = 0;
		wall[i].img = 0;
		wall[i].size_line = 0;
		wall[i].width = 0;
		wall[i].filename = NULL;
	}
	return(wall);
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

t_data		*initializing_slice_parameters_structure()
{
	t_data 	*data;
	int			index;

	index = -1;
	if(!(data = (t_data *)malloc(sizeof(t_data))))
		return(NULL);
	data->index = -1;
	data->wall_h = NULL;
	data->wall_hFull = NULL;
	data->celing_h = NULL;
	data->y_image = NULL;
	data->side_of_world = NULL;
	data->x_image = NULL;
	data->distance_wall = NULL;
	data->distance_wall_not_corr = NULL;
	data->distan_of_sprites = NULL;
	return(data);
}