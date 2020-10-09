/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:48:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 16:25:20 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	calc_y(t_data *data, int y)
{
	return (floor(y + (data->wall_hFull[data->i] -\
						data->wall_h[data->i]) / 2));
}

static	void	pix_put_wall(t_all *s, char *addr, int size_line, \
										int bps)
{
	int			color;

	color = get_color_pixel(s->data, addr, size_line, bps);
	my_mlx_pixel_put(s->win, s->data->i, s->fd->i++, color);
	s->data->y_image[s->data->i]++;
}

static void		y_textur(t_all *s, double y_slice, int h_texture, \
								double wall_h)
{
	s->data->y_image[s->data->i] = floor(y_slice * (h_texture) /\
													(wall_h));
}

void			drawing_walls(t_all *s, t_data *d, t_wall *wall, int y)
{
	while (++y < d->wall_h[d->i])
	{
		if (d->side_of_world[d->i] == 'N')
		{
			y_textur(s, calc_y(d, y), wall[0].height, d->wall_hFull[d->i]);
			pix_put_wall(s, wall[0].adr, wall[0].size_line, wall[0].bps);
		}
		else if (d->side_of_world[d->i] == 'E')
		{
			y_textur(s, calc_y(d, y), wall[3].height, d->wall_hFull[d->i]);
			pix_put_wall(s, wall[3].adr, wall[3].size_line, wall[3].bps);
		}
		else if (d->side_of_world[d->i] == 'W')
		{
			y_textur(s, calc_y(d, y), wall[2].height, d->wall_hFull[d->i]);
			pix_put_wall(s, wall[2].adr, wall[2].size_line, wall[2].bps);
		}
		else
		{
			y_textur(s, calc_y(d, y), wall[1].height, d->wall_hFull[d->i]);
			pix_put_wall(s, wall[1].adr, wall[1].size_line, wall[1].bps);
		}
	}
}
