/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:49:44 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 15:39:03 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycasting(t_all *s, t_data *data, t_map *map, t_const *cnst)
{
	double tang;

	map->first_ray = map->a_p + M_PI_6;
	while (++data->index < s->win->x)
	{
		tang = tan(map->first_ray);
		checking_direction(&map->first_ray);
		first_horisont_intersection(map, tang);
		first_vertical_intersection(map, tang);
		horizontal_intersection_with_wall(map, cnst);
		vertical_intersection_with_wall(map, cnst);
		calculating_nearest_distance_to_wall(s, map, data);
		calculating_wall_length_in_one_slice(s, data, map, cnst);
		map->first_ray -= cnst->delta_ray;
	}
}