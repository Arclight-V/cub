/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_initialization_two.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:58:50 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 17:05:45 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		creating_array_for_ray(t_all *s)
{
	if (!(s->data->wall_h = ft_calloc((s->win->x), sizeof(double))))
		ft_error_output(s, MALLOC_14);
	if (!(s->data->wall_hFull = ft_calloc((s->win->x), sizeof(double))))
		ft_error_output(s, MALLOC_15);
	if (!(s->data->celing_h = ft_calloc((s->win->x), sizeof(int))))
		ft_error_output(s, MALLOC_16);
	if (!(s->data->y_image = ft_calloc((s->win->x), sizeof(int))))
		ft_error_output(s, MALLOC_17);
	if (!(s->data->side_of_world = ft_calloc((s->win->x), sizeof(char))))
		ft_error_output(s, MALLOC_18);
	if (!(s->data->x_image = ft_calloc((s->win->x), sizeof(int))))
		ft_error_output(s, MALLOC_19);
	if (!(s->data->distance_wall = ft_calloc((s->win->x), sizeof(double))))
		ft_error_output(s, MALLOC_20);
	if (!(s->data->distance_wall_not_corr = ft_calloc((s->win->x), sizeof(double))))
		ft_error_output(s, MALLOC_21);
	if (!(s->data->distan_of_sprites = ft_calloc((s->win->x), sizeof(double))))
		ft_error_output(s, MALLOC_22);
}

t_wall		*initializing_wall_structure(t_wall *wall)
{
	int		i;

	i = -1;
	if (!(wall = (t_wall *)malloc(4 * (sizeof(t_wall)))))
		return (NULL);
	while (++i < 4)
	{
		wall[i].adr = NULL;
		wall[i].bps = 0;
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
	sprite->bps = 0;
	sprite->endian = 0;
	sprite->height = 0;
	sprite->img = 0;
	sprite->size_line = 0;
	sprite->width = 0;
	sprite->x = 0;
	sprite->y = 0;
	sprite->angle = 0.0;
	sprite->distance = 0.0;
	sprite->size_line = 0;
	sprite->hight = 0.0;
	sprite->hight_half = 0.0;
	sprite->hight_coor = 0.0;
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
	data->i = -1;
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

t_all		*initializing_structures(t_all *s)
{
	if (!(s = initializing_structure_of_structures(s)))
		ft_error_output(s, MALLOC_1);
	if (!(s->map = initializing_map_structure()))
		ft_error_output(s, MALLOC_2);
	if (!(s->fd = initializing_fd_structure()))
		ft_error_output(s, MALLOC_3);
	if (!(s->win = initializing_win_structure()))
		ft_error_output(s, MALLOC_4);
	if (!(s->cnst = initializing_const_values_structure()))
		ft_error_output(s, MALLOC_5);
	if (!(s->wall = initializing_wall_structure(s->wall)))
		ft_error_output(s, MALLOC_6);
	if (!(s->data = initializing_slice_parameters_structure()))
		ft_error_output(s, MALLOC_7);
	return (s);
}
