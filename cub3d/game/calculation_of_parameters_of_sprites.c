/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_of_parameters_of_sprites.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:11:23 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 22:04:07 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	calculating_sprite_direction(double x_player, double y_player,\
										int x_sprite, int y_sprite)
{
	double		direction;

	direction = atan2(y_player - y_sprite, x_sprite - x_player);
	direction = direction >= 0 ? direction : TWO_PI + direction;
	return (direction);
}

static double	calculating_delta(double fov_start, double sprite_dir)
{
	double		delta;

	delta = fov_start - sprite_dir;
	if (delta <= -M_PI)
		delta += TWO_PI;
	else if (delta >= M_PI)
		delta -= TWO_PI;
	return (delta);
}

void			calculation_of_parameters_of_sprites(t_all *s, t_data *data,\
											t_sprite *sp, t_const *cnst)
{
	int			i;
	double		delta;

	i = -1;
	while (++i < s->map->item)
	{
		sp[i].angle = calculating_sprite_direction(s->map->x_p, s->map->y_p,\
													sp[i].x, sp[i].y);
		sp[i].distance = sqrt(pow(s->map->x_p - sp[i].x, 2) + pow(s->map->y_p\
												- sp[i].y, 2));
		sp[i].hight = (CUBE / (sp[i].distance * cos(s->map->a_p - \
								sp[i].angle))) * cnst->dist_projec_plan;
		sp[i].hight_coor = sp[i].hight > s->win->y ? s->win->y : sp[i].hight;
		sp[i].sprite_width = CUBE / sp[i].distance * cnst->dist_projec_plan;
		sp[i].hight_half = sp[i].hight_coor / 2;
		delta = calculating_delta(s->map->a_p + M_PI_6, sp[i].angle);
		sp[i].h_offset = delta / (s->cnst->delta_ray) - sp[i].hight_half;
		sp[i].position_sprite = ((cnst->center_project - sp[i].hight_half));
	}
	if (!(data->distan_of_sprites = sorting_of_distances_of_sprites(s, \
											data->distan_of_sprites)))
		ft_error_output(s, MALLOC_23);
}
