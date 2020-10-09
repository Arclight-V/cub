/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:49:44 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 11:54:56 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycasting(t_all *s, t_data *data, t_map *map, t_const *cnst)
{
	map->angle_start = map->a_p + M_PI_6;
	while (++data->index < s->win->x)
	{
		checking_direction(&map->angle_start);
		first_horisont_intersection(map);
		first_vertical_intersection(map);
		horizontal_intersection_with_wall(map, cnst);
		vertical_intersection_with_wall(map, cnst);
		calculating_nearest_distance_to_wall(s, map, data);
		calculating_wall_length_in_one_slice(s, data, map, cnst);
		map->angle_start -= cnst->delta_ray;
	}
}