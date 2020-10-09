/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating_wall_length_in_one_slice.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:33:52 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 16:07:20 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calcu_ofsetx_in_texture(t_all *s, t_data *data, t_map *map, char ch)
{
	data->side_of_world[data->i] = ch;
	if (map->flagPDPE == 1 && ch == 'N')
		data->x_image[data->i] = floor(fmod(map->x_horizont, CUBE) *\
							s->cnst->ratio_of_texture_width_to_CUBE_NORD);
	else if (ch == 'W')
		data->x_image[data->i] = floor(fmod(map->y_vertical, CUBE) *\
							s->cnst->ratio_of_texture_width_to_CUBE_WEST);
	else if (ch == 'S')
		data->x_image[data->i] = floor(fmod(map->x_horizont, CUBE) *\
							s->cnst->ratio_of_texture_width_to_CUBE_South);
	else if (ch == 'E')
		data->x_image[data->i] = floor(fmod(map->y_vertical, CUBE) *\
							s->cnst->ratio_of_texture_width_to_CUBE_EAST);
}

void		calculating_wall_length_in_one_slice(t_all *s, t_data *data, \
												t_map *map, t_const *cnst)
{
	data->wall_hFull[data->i] = CUBE / data->distance_wall[data->i] *\
											cnst->DistProjectionPlan;
	data->wall_h[data->i] = data->wall_hFull[data->i] > s->win->y ?\
								s->win->y : data->wall_hFull[data->i];
	data->celing_h[data->i] = floor((cnst->CenterProjection -\
											data->wall_h[data->i] / 2));
	if (map->first_ray > 0 && map->first_ray < M_PI)
	{
		if (map->flagPDPE == 1)
			calcu_ofsetx_in_texture(s, data, map, 'N');
		else if (map->first_ray < M_PI_2 && map->flagPDPE == 0)
			calcu_ofsetx_in_texture(s, data, map, 'E');
		else
			calcu_ofsetx_in_texture(s, data, map, 'W');
	}
	else
	{
		if (map->flagPDPE == 1)
			calcu_ofsetx_in_texture(s, data, map, 'S');
		else if (map->first_ray > TREE_PI_ON_2 && map->flagPDPE == 0)
			calcu_ofsetx_in_texture(s, data, map, 'E');
		else
			calcu_ofsetx_in_texture(s, data, map, 'W');
	}
}
