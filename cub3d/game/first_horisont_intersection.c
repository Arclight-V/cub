/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_horisont_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:40:10 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/12 09:09:43 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	first_horisont_intersection(t_map *map, double tang)
{
	if (map->first_ray > 0 && map->first_ray < M_PI)
	{
		map->xa_h = CUBE / tang;
		map->y_horizont = (((int)map->y_p >> 6) << 6) - 0.001;
		map->x_horizont = map->x_p + (map->y_p - map->y_horizont) / tang;
		map->ya_h = -CUBE;
	}
	else
	{
		map->xa_h = -(CUBE / tang);
		map->y_horizont = (((int)map->y_p >> 6) << 6) + CUBE;
		map->x_horizont = map->x_p + (map->y_p - map->y_horizont) / tang;
		map->ya_h = CUBE;
	}
}
