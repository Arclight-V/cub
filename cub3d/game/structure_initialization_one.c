/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_initialization_one.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 08:23:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 14:54:31 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		*initializing_map_structure(void)
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
	map->PD = 0;
	map->PE = 0;
	map->flagPDPE = 0;
	map->floor = -1;
	map->ceil = -1;
	return (map);
}

t_fd		*initializing_fd_structure(void)
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
	fd->player = 0;
	return (fd);
}

t_win		*initializing_win_structure(void)
{
	t_win	*win;

	if (!(win = (t_win *)malloc(sizeof(t_win))))
		return (NULL);
	win->mlx = NULL;
	win->win = NULL;
	win->img = NULL;
	win->addr = NULL;
	win->line_lenght = 0;
	win->bps = 0;
	win->endian = 0;
	win->x = 0;
	win->y = 0;
	return (win);
}

t_const		*initializing_const_values_structure(void)
{
	t_const	*cnst;

	if (!(cnst = (t_const *)malloc(sizeof(t_const))))
		return (NULL);
	cnst->DistProjectionPlan = 0;
	cnst->CenterProjection = 0;
	cnst->delta_ray = 0;
	cnst->xMapMax = 0;
	cnst->yMapMax = 0;
	cnst->ratio_of_texture_width_to_CUBE_NORD = 0;
	cnst->ratio_of_texture_width_to_CUBE_South = 0;
	cnst->ratio_of_texture_width_to_CUBE_WEST = 0;
	cnst->ratio_of_texture_width_to_CUBE_EAST = 0;
	return (cnst);
}

t_all		*initializing_structure_of_structures(t_all *s)
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
	s->head = NULL;
	return (s);
}
