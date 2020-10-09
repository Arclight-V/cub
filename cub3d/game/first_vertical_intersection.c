/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_vertical_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:43:01 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 21:49:40 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	first_vertical_intersection(t_map *map, double tang)
{
	if (map->first_ray < M_PI_2 || map->first_ray > TREE_PI_ON_2)
	{
		map->Y_a_v = -(CUBE * tang);
		map->x_vertical = (((int)map->x_p >> 6) << 6) + CUBE;
		map->y_vertical = map->y_p + ((map->x_p - map->x_vertical) * tang);
		map->X_a_v = CUBE;
	}
	else
	{
		map->Y_a_v = CUBE * tang;
		map->x_vertical = (((int)map->x_p >> 6) << 6) - 0.001;
		map->y_vertical = (map->y_p + (map->x_p - map->x_vertical) * tang);
		map->X_a_v = -CUBE;
	}
}
