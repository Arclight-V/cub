/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_of_parameters_for_horizontal_an        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:53:48 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/05 16:23:33 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_intersection_with_wall(t_map *map, t_const *cnst)
{
	if ((map->x_horizont > 0 && map->x_horizont < cnst->xMapMax) && \
		(map->y_horizont > 0 && map->y_horizont < cnst->yMapMax))
	{
		if (map->map[(int)map->y_horizont/CUBE][(int)map->x_horizont/CUBE] != '1')
			{
				map->y_horizont += map->Y_a_h;
				map->x_horizont += map->X_a_h;
				horizontal_intersection_with_wall(map, cnst);
			}
	}
}

void	vertical_intersection_with_wall(t_map *map, t_const *cnst)
{
	if ((map->x_vertical > 0 && map->x_vertical < cnst->xMapMax )
		&& (map->y_vertical > 0 && map->y_vertical < cnst->yMapMax))
	{
		if (map->map[(int)map->y_vertical/CUBE][(int)map->x_vertical/CUBE] != '1')
			{
				map->y_vertical += map->Y_a_v;
				map->x_vertical += map->X_a_v;
				vertical_intersection_with_wall(map, cnst);
			}
	}
}

void	first_horisont_intersection(t_map *map)
{	
	double tang;

	tang = tan(map->angle_start);
	if (map->angle_start > 0 && map->angle_start < M_PI )
	{
		map->X_a_h = CUBE /tang;
		map->y_horizont = (int)(map->y_p / CUBE) * CUBE - 0.0001;
		map->x_horizont = map->x_p + (map->y_p - map->y_horizont) / tang;
		map->Y_a_h = -CUBE;
	}
	else
	{
		map->X_a_h = -(CUBE /tang);
		map->y_horizont = (int)(map->y_p / CUBE) * CUBE + CUBE;
		map->x_horizont = map->x_p + (map->y_p - map->y_horizont) / tang;
		map->Y_a_h = CUBE;
	}
}

void	first_vertical_intersection(t_map *map)
{
	double	tang;

	tang = tan(map->angle_start);
	if (map->angle_start < M_PI_2 || map->angle_start > TREE_PI_ON_2)
	{
		map->Y_a_v = -(CUBE * tang);
		map->x_vertical = (int)(map->x_p / CUBE) * CUBE + CUBE;
		map->y_vertical = map->y_p + ((map->x_p - map->x_vertical) * tang);
		map->X_a_v = CUBE;
	}
	else
	{
		map->Y_a_v = CUBE * tang;
		map->x_vertical = (int)(map->x_p / CUBE) * CUBE - 0.0001;
		map->y_vertical = (map->y_p + (map->x_p - map->x_vertical) * tang);
		map->X_a_v = -CUBE;
	}
}

void	calculating_nearest_distance_to_wall(t_map *map, t_dataWall *dataWall)
{
	map->PD = sqrt(pow((map->x_p - map->x_horizont), 2) + pow((map->y_p - map->y_horizont), 2));
	map->PE = sqrt(pow((map->x_p - map->x_vertical), 2) + pow((map->y_p - map->y_vertical), 2));
	if (map->PD < map->PE)
	{
		dataWall->distance_wall_not_corr[dataWall->index] = map->PD;
		dataWall->distance_wall[dataWall->index] = map->PD * cos(map->a_p - map->angle_start);
		map->flagPDPE = 1;
	}
	else
	{
		dataWall->distance_wall_not_corr[dataWall->index] = map->PE;
		dataWall->distance_wall[dataWall->index] = map->PE * cos(map->a_p - map->angle_start);
		map->flagPDPE = 0;
	}
}