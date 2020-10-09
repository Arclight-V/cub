/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_of_parameters_of_sprites.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:11:23 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 14:54:31 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	calculating_sprite_direction(double x_player, double y_player,\
										 int x_sprite, int y_sprite)
{
	double	direction;

	direction = atan2(y_player - y_sprite, x_sprite - x_player);
	direction = direction >= 0 ? direction : TWO_PI + direction;
	return (direction);
}

static double	calculating_delta(double fov_start, double sprite_dir)
{
	double 	delta;

	delta = fov_start - sprite_dir;
	if (delta <= -M_PI)
		delta += TWO_PI;
	else if (delta >= M_PI)
		delta -= TWO_PI;
	return (delta);
}

void	calculation_of_parameters_of_sprites(t_all *s, t_data *data,\
											 t_sprite *sprite, t_const *cnst)
{
	int		i;
	double	delta;

	i = -1;
	while (++i < s->map->item)
	{
		sprite[i].sprite_angle = calculating_sprite_direction(s->map->x_p, s->map->y_p, sprite[i].x, sprite[i].y);
		sprite[i].distance = sqrt(pow(s->map->x_p - sprite[i].x, 2) + pow(s->map->y_p - sprite[i].y, 2));
		sprite[i].sprite_screen_size_full = (CUBE / (sprite[i].distance  * cos(s->map->a_p - sprite[i].sprite_angle))) * cnst->DistProjectionPlan;
		sprite[i].sprite_screen_size_coor = sprite[i].sprite_screen_size_full > s->win->y ? s->win->y : sprite[i].sprite_screen_size_full;
		sprite[i].sprite_width = CUBE / sprite[i].distance * cnst->DistProjectionPlan;
		sprite[i].sprite_screen_size_half = sprite[i].sprite_screen_size_coor / 2;
		delta = calculating_delta(s->map->a_p + M_PI_6, sprite[i].sprite_angle);
		sprite[i].h_offset =  delta / (s->cnst->delta_ray) - sprite[i].sprite_screen_size_half;
		sprite[i].position_sprite = ((cnst->CenterProjection - sprite[i].sprite_screen_size_half));
	}
}