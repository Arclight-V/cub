/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_screen_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:11:19 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/05 17:53:12 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	drawing_celing(t_dataWall *dataWall, t_win *win, int ceil)
{
	int	y;

	y = -1;
	while (++y < dataWall->celing_h[dataWall->index])
		my_mlx_pixel_put(win, dataWall->index, y, ceil);
}

static void	drawing_floor(t_map *map, t_win *win, int index)
{

	while (map->i < win->y - 1)
		my_mlx_pixel_put(win, index, map->i++, map->floor);
}




int	drawing_screen(t_all *s, t_dataWall *dataWall, t_map *map, t_const *cnst)
{
	dataWall->index = -1;
	while(++dataWall->index < s->win->x)
	{
		s->map->i = dataWall->celing_h[dataWall->index];
		drawing_celing(dataWall, s->win, map->ceil);
		drawing_walls(s, dataWall, s->wall);
		drawing_floor(s->map, s->win, dataWall->index);
		drawing_sprites(s, s->dataWall, s->sprite);
	}
}