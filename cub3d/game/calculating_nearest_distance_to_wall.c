/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating_nearest_distance_to_wall.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:53:48 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 22:08:19 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculating_nearest_distance_to_wall(t_map *map, t_data *data)
{
	map->pd = sqrt(pow((map->x_p - map->x_horizont), 2) +\
					pow((map->y_p - map->y_horizont), 2));
	map->pe = sqrt(pow((map->x_p - map->x_vertical), 2) +\
					pow((map->y_p - map->y_vertical), 2));
	if (map->pd < map->pe)
	{
		data->distance_wall_not_corr[data->i] = map->pd;
		data->distance_wall[data->i] = map->pd * cos(map->a_p -\
														map->first_ray);
		map->flag = 1;
	}
	else
	{
		data->distance_wall_not_corr[data->i] = map->pe;
		data->distance_wall[data->i] = map->pe * cos(map->a_p -\
														map->first_ray);
		map->flag = 0;
	}
}
