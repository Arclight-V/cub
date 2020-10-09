/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating_nearest_distance_to_wall.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:53:48 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 16:07:20 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculating_nearest_distance_to_wall(t_all *s, t_map *map, t_data *data)
{
	map->PD = sqrt(pow((map->x_p - map->x_horizont), 2) +\
					pow((map->y_p - map->y_horizont), 2));
	map->PE = sqrt(pow((map->x_p - map->x_vertical), 2) +\
					pow((map->y_p - map->y_vertical), 2));
	if (map->PD < map->PE)
	{
		data->distance_wall_not_corr[data->i] = map->PD;
		data->distance_wall[data->i] = map->PD * cos(map->a_p -\ 
														map->first_ray);
		map->flagPDPE = 1;
	}
	else
	{
		data->distance_wall_not_corr[data->i] = map->PE;
		data->distance_wall[data->i] = map->PE * cos(map->a_p -\
														map->first_ray);
		map->flagPDPE = 0;
	}
}
