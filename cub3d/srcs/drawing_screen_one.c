/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_screen_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:11:19 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 11:47:17 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	drawing_celing(t_data *data, t_win *win, int ceil)
{
	int	y;

	y = -1;
	while (++y < data->celing_h[data->index])
		my_mlx_pixel_put(win, data->index, y, ceil);
}

static void	drawing_floor(t_map *map, t_win *win, int index, int i)
{

	while (i < win->y - 1)
		my_mlx_pixel_put(win, index, i++, map->floor);
}

int	drawing_screen(t_all *s, t_data *data, t_map *map, t_const *cnst)
{

	data->index = -1;
	while(++data->index < s->win->x)
	{
		s->fd->i = data->celing_h[data->index];
		drawing_celing(data, s->win, map->ceil);
		drawing_walls(s, data, s->wall);
		drawing_floor(s->map, s->win, data->index, s->fd->i);
		if ((drawing_sprites(s, s->data, s->sprite)) < 0)
			return (-1);
	}
	return (1);
}