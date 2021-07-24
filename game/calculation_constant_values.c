/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_constant_values.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:28:56 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 22:04:07 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		calculation_constant_values(t_all *s)
{
	s->cnst->dist_projec_plan = floor((float)s->win->x / 2) / tan(FOV / 2);
	s->cnst->center_project = floor((float)s->win->y / 2);
	s->cnst->delta_ray = FOV / s->win->x;
	s->cnst->ratio_of_nord_width_to_cube = s->wall[NORD].width / CUBE;
	s->cnst->ratio_of_south_width_to_cube = s->wall[SOUTH].width / CUBE;
	s->cnst->ratio_of_west_width_to_cube = s->wall[WEST].width / CUBE;
	s->cnst->ratio_of_east_width_to_cube = s->wall[EAST].width / CUBE;
	s->cnst->x_max = s->fd->max_len * CUBE - 1;
	s->cnst->y_max = s->map->size * CUBE - 1;
}
