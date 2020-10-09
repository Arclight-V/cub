/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_initialization_one.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 08:23:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 22:07:43 by anatashi         ###   ########.fr       */
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
	map->first_ray = 0;
	map->x_horizont = 0;
	map->y_horizont = 0;
	map->X_a_h = 0;
	map->Y_a_h = 0;
	map->x_vertical = 0;
	map->y_vertical = 0;
	map->X_a_v = 0;
	map->Y_a_v = 0;
	map->pd = 0;
	map->pe = 0;
	map->flag = 0;
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
	cnst->dist_projec_plan = 0;
	cnst->center_project = 0;
	cnst->delta_ray = 0;
	cnst->x_max = 0;
	cnst->y_max = 0;
	cnst->ratio_of_nord_width_to_cube = 0;
	cnst->ratio_of_south_width_to_cube = 0;
	cnst->ratio_of_west_width_to_cube = 0;
	cnst->ratio_of_east_width_to_cube = 0;
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
