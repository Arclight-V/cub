/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_initialization_two.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:58:50 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 11:58:40 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_wall		*initializing_wall_structure(t_wall *wall)
{
	int		i;

	i = -1;
	if (!(wall = (t_wall *)malloc(4 * (sizeof(t_wall)))))
		return (NULL);
	while (++i < 4)
	{
		wall[i].adr = NULL;
		wall[i].bits_per_pixel = 0;
		wall[i].endian = 0;
		wall[i].height = 0;
		wall[i].img = 0;
		wall[i].size_line = 0;
		wall[i].width = 0;
		wall[i].filename = NULL;
	}
	return (wall);
}

t_sprite	*ft_creat_sprite_s(void)
{
	t_sprite *sprite;

	if (!(sprite = (t_sprite *)malloc(sizeof(t_sprite))))
		return (NULL);
	sprite->adr = NULL;
	sprite->bits_per_pixel = 0;
	sprite->endian = 0;
	sprite->height = 0;
	sprite->img = 0;
	sprite->size_line = 0;
	sprite->width = 0;
	sprite->x = 0;
	sprite->y = 0;
	sprite->sprite_angle = 0.0;
	sprite->distance = 0.0;
	sprite->size_line = 0;
	sprite->sprite_screen_size_full = 0.0;
	sprite->sprite_screen_size_half = 0.0;
	sprite->sprite_screen_size_coor = 0.0;
	sprite->position_sprite = 0;
	sprite->h_offset = 0;
	sprite->v_offset = 0;
	return (sprite);
}

t_data		*initializing_slice_parameters_structure(void)
{
	t_data	*data;
	int		index;

	index = -1;
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->index = -1;
	data->wall_h = NULL;
	data->wall_hFull = NULL;
	data->celing_h = NULL;
	data->y_image = NULL;
	data->side_of_world = NULL;
	data->x_image = NULL;
	data->distance_wall = NULL;
	data->distance_wall_not_corr = NULL;
	data->distan_of_sprites = NULL;
	return (data);
}
