/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:11:19 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/17 12:48:55 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		drawing_celing(t_data *data, t_win *win, int ceil)
{
	int	y;

	y = -1;
	while (++y < data->celing_h[data->i])
		my_mlx_pixel_put(win, data->i, y, ceil);
}

static void		drawing_floor(t_map *map, t_win *win, int index, int i)
{
	while (i < win->y)
		my_mlx_pixel_put(win, index, i++, map->floor);
}

void			drawing_screen(t_all *s, t_data *data, t_map *map)
{
	data->i = -1;
	while (++data->i < s->win->x)
	{
		s->fd->i = data->celing_h[data->i];
		drawing_celing(data, s->win, map->ceil);
		drawing_walls(s, data, s->wall, -1);
		drawing_floor(s->map, s->win, data->i, s->fd->i);
		drawing_sprites(s, s->data, s->sprite, -1);
	}
}
