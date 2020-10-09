/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_of_parameters_for_horizontal_an        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:53:48 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 15:01:58 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_intersection_with_wall(t_map *m, t_const *cnst)
{
	if ((m->x_horizont > 0 && m->x_horizont < cnst->xMapMax) && \
		(m->y_horizont > 0 && m->y_horizont < cnst->yMapMax))
	{
		if (m->map[(int)m->y_horizont >> 6][(int)m->x_horizont >> 6] != '1')
			{
				m->y_horizont += m->Y_a_h;
				m->x_horizont += m->X_a_h;
				horizontal_intersection_with_wall(m, cnst);
			}
	}
}

void	vertical_intersection_with_wall(t_map *m, t_const *cnst)
{
	if ((m->x_vertical > 0 && m->x_vertical < cnst->xMapMax )
		&& (m->y_vertical > 0 && m->y_vertical < cnst->yMapMax))
	{
		if (m->map[(int)m->y_vertical >> 6][(int)m->x_vertical >> 6] != '1')
			{
				m->y_vertical += m->Y_a_v;
				m->x_vertical += m->X_a_v;
				vertical_intersection_with_wall(m, cnst);
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
		map->y_horizont = (((int)map->y_p >> 6) << 6) - 0.001;
		map->x_horizont = map->x_p + (map->y_p - map->y_horizont) / tang;
		map->Y_a_h = -CUBE;
	}
	else
	{
		map->X_a_h = -(CUBE /tang);
		map->y_horizont = (((int)map->y_p >> 6) << 6) + CUBE;
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
		map->x_vertical = (((int)map->x_p >> 6) << 6) + CUBE;
		map->y_vertical = map->y_p + ((map->x_p - map->x_vertical) * tang);
		map->X_a_v = CUBE;
	}
	else
	{
		map->Y_a_v = CUBE * tang;
		map->x_vertical = (((int)map->x_p >> 6) << 6)  - 0.001;
		map->y_vertical = (map->y_p + (map->x_p - map->x_vertical) * tang);
		map->X_a_v = -CUBE;
	}
}

void	calculating_nearest_distance_to_wall(t_all *s, t_map *map, t_data *data)
{
	map->PD = sqrt(pow((map->x_p - map->x_horizont), 2) + pow((map->y_p - map->y_horizont), 2));
	map->PE = sqrt(pow((map->x_p - map->x_vertical), 2) + pow((map->y_p - map->y_vertical), 2));
	if (map->PD < map->PE)
	{
		data->distance_wall_not_corr[data->index] = map->PD;
		data->distance_wall[data->index] = map->PD * cos(map->a_p - map->angle_start);
		map->flagPDPE = 1;
	}
	else
	{
		data->distance_wall_not_corr[data->index] = map->PE;
		data->distance_wall[data->index] = map->PE * cos(map->a_p - map->angle_start);
		map->flagPDPE = 0;
	}
}