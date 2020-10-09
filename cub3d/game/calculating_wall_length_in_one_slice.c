/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating_wall_length_in_one_slice.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:33:52 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 22:05:10 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calcu_ofsetx_in_texture(t_all *s, t_data *data, t_map *map, char ch)
{
	data->side_of_world[data->i] = ch;
	if (map->flag == 1 && ch == 'N')
		data->x_image[data->i] = floor(fmod(map->x_horizont, CUBE) *\
							s->cnst->ratio_of_nord_width_to_cube);
	else if (ch == 'W')
		data->x_image[data->i] = floor(fmod(map->y_vertical, CUBE) *\
							s->cnst->ratio_of_west_width_to_cube);
	else if (ch == 'S')
		data->x_image[data->i] = floor(fmod(map->x_horizont, CUBE) *\
							s->cnst->ratio_of_south_width_to_cube);
	else if (ch == 'E')
		data->x_image[data->i] = floor(fmod(map->y_vertical, CUBE) *\
							s->cnst->ratio_of_east_width_to_cube);
}

void		calculating_wall_length_in_one_slice(t_all *s, t_data *data, \
												t_map *map, t_const *cnst)
{
	data->wall_hfull[data->i] = CUBE / data->distance_wall[data->i] *\
											cnst->dist_projec_plan;
	data->wall_h[data->i] = data->wall_hfull[data->i] > s->win->y ?\
								s->win->y : data->wall_hfull[data->i];
	data->celing_h[data->i] = floor((cnst->center_project -\
											data->wall_h[data->i] / 2));
	if (map->first_ray > 0 && map->first_ray < M_PI)
	{
		if (map->flag == 1)
			calcu_ofsetx_in_texture(s, data, map, 'N');
		else if (map->first_ray < M_PI_2 && map->flag == 0)
			calcu_ofsetx_in_texture(s, data, map, 'E');
		else
			calcu_ofsetx_in_texture(s, data, map, 'W');
	}
	else
	{
		if (map->flag == 1)
			calcu_ofsetx_in_texture(s, data, map, 'S');
		else if (map->first_ray > TREE_PI_ON_2 && map->flag == 0)
			calcu_ofsetx_in_texture(s, data, map, 'E');
		else
			calcu_ofsetx_in_texture(s, data, map, 'W');
	}
}
