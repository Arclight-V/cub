/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:48:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 11:47:25 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color_pixel(t_data *data, char *adr, int size_line,\
							int bits_per_pixel)
{
	char	*color;

	color = adr + (data->y_image[data->index] * size_line +\
				   data->x_image[data->index] * (bits_per_pixel / 8));
	return (*(unsigned int*)color);
}

static double	calc_y(t_data *data, int y)
{
	return (floor(y + (data->wall_hFull[data->index] -\
					   data->wall_h[data->index]) / 2));
}

static void		printSliceWall(t_all *s, char *addr, int size_line, \
										 int bits_per_pixel)
{
	int			color;

	color = get_color_pixel(s->data, addr, size_line, bits_per_pixel);	
	my_mlx_pixel_put(s->win, s->data->index, s->fd->i++, color);
	s->data->y_image[s->data->index]++;
}

static void		search_y_texture(t_all *s, double y_slice, int h_texture, \
								 double sliceWnot)
{
	s->data->y_image[s->data->index] = floor(y_slice * (h_texture ) /\
													(sliceWnot));
}

void		drawing_walls(t_all *s, t_data *data, t_wall *wall)
{	
	int y;

	y = -1;
	while (++y < data->wall_h[data->index])
	{
		if (data->side_of_world[data->index] == 'N')
		{
			search_y_texture(s, calc_y(data, y), wall[NORD].height, data->wall_hFull[data->index]);
			printSliceWall(s, wall[NORD].adr, wall[NORD].size_line, wall[NORD].bits_per_pixel);
		}
		else if (data->side_of_world[data->index] == 'E')
		{
			search_y_texture(s, calc_y(data, y), wall[EAST].height, data->wall_hFull[data->index]);
			printSliceWall(s, wall[EAST].adr, wall[EAST].size_line, wall[EAST].bits_per_pixel);
		}
		else if (data->side_of_world[data->index] == 'W')
		{
			search_y_texture(s, calc_y(data, y), wall[WEST].height, data->wall_hFull[data->index]);
			printSliceWall(s, wall[WEST].adr, wall[WEST].size_line, wall[WEST].bits_per_pixel);		
		}
		else if (data->side_of_world[data->index] == 'S')
		{
			search_y_texture(s, calc_y(data, y), wall[SOUTH].height, data->wall_hFull[data->index]);
			printSliceWall(s, wall[SOUTH].adr, wall[SOUTH].size_line, wall[SOUTH].bits_per_pixel);
		}		
	}
}