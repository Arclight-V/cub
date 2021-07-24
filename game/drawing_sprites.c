/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:02:48 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 20:45:32 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_color_pixel_sprite(t_sprite *sprite, int ofset_x, int i,\
										int y)
{
	char		*color;

	color = sprite[i].adr + (y * sprite[i].size_line + ofset_x *\
							(sprite[i].bps >> 3));
	return (*(unsigned int*)color);
}

static int		print_pixel_of_sprite(t_all *s, int j, int i, int y)
{
	int			color_pixel;
	int			offset_x;
	double		y_sprite;

	if (s->sprite[i].hight_coor == 0)
		return (s->fd->i + 1);
	offset_x = floor((double)j * ((double)s->sprite[i].width /\
									s->sprite[i].sprite_width));
	y_sprite = floor(y + ((s->sprite[i].hight -\
							s->sprite[i].hight_coor) / 2));
	color_pixel = get_color_pixel_sprite(s->sprite, offset_x, i,\
						floor(y_sprite * (s->sprite[i].height) / \
						(s->sprite[i].hight)));
	if (color_pixel <= 0)
		return (s->fd->i + 1);
	my_mlx_pixel_put(s->win, s->data->i, s->fd->i, color_pixel);
	return (s->fd->i + 1);
}

int				drawing_sprites(t_all *s, t_data *data, t_sprite *sprite, int i)
{
	int			j;
	int			k;
	int			y;

	calculation_of_parameters_of_sprites(s, data, sprite, s->cnst);
	while (++i < s->map->item)
	{
		j = -1;
		k = data->distan_of_sprites[i];
		while (++j < sprite[k].sprite_width)
		{
			if ((sprite[k].h_offset + j) == data->i)
			{
				s->fd->i = sprite[k].position_sprite;
				if (sprite[k].distance < data->distance_wall_not_corr[data->i])
				{
					y = -1;
					while (++y < sprite[k].hight_coor)
						s->fd->i = print_pixel_of_sprite(s, j, k, y);
				}
			}
		}
	}
	return (1);
}
