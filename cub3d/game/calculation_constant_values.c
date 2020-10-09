/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_constant_values.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:28:56 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 14:55:09 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		calculation_constant_values(t_all *s)
{
	s->cnst->DistProjectionPlan = floor((float)s->win->x / 2) / tan(FOV / 2);
	s->cnst->CenterProjection = floor((float)s->win->y / 2);
	s->cnst->delta_ray = FOV / s->win->x;
	s->cnst->ratio_of_texture_width_to_CUBE_NORD = s->wall[NORD].width / CUBE;
	s->cnst->ratio_of_texture_width_to_CUBE_South = s->wall[SOUTH].width / CUBE;
	s->cnst->ratio_of_texture_width_to_CUBE_WEST = s->wall[WEST].width / CUBE;
	s->cnst->ratio_of_texture_width_to_CUBE_EAST = s->wall[EAST].width / CUBE;
	s->cnst->xMapMax = s->fd->max_len * CUBE - 1;
	s->cnst->yMapMax = s->map->size * CUBE - 1;
}
