/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_memory_from_data_structure.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:33:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 21:45:20 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freeing_memory_from_data_structure(t_data *data)
{
	if (data->wall_h)
		ft_free_tmp(data->wall_h);
	if (data->wall_hfull)
		ft_free_tmp(data->wall_hfull);
	if (data->celing_h)
		ft_free_tmp(data->celing_h);
	if (data->y_image)
		ft_free_tmp(data->y_image);
	if (data->side_of_world)
		ft_free_tmp(data->side_of_world);
	if (data->x_image)
		ft_free_tmp(data->x_image);
	if (data->distance_wall)
		ft_free_tmp(data->distance_wall);
	if (data->distance_wall_not_corr)
		ft_free_tmp(data->distance_wall_not_corr);
	if (data->distan_of_sprites)
		ft_free_tmp(data->distan_of_sprites);
	ft_free_tmp(data);
}
