/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:48:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/05 17:59:30 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color_pixel(t_dataWall *dataWall, char *adr, int size_line,\
							int bits_per_pixel)
{
	char	*color;

	color = adr + (dataWall->y_image[dataWall->index] * size_line +\
				   dataWall->x_image[dataWall->index] * (bits_per_pixel / 8));
	return (*(unsigned int*)color);
}

static double	calc_y(t_dataWall *dataWall, int y)
{
	return (floor(y + (dataWall->wall_hFull[dataWall->index] -\
					   dataWall->wall_h[dataWall->index]) / 2));
}

static void		printSliceWall(t_all *s, char *addr, int size_line, \
										 int bits_per_pixel)
{
	int			color;

	color = get_color_pixel(s->dataWall, addr, size_line, bits_per_pixel);	
	my_mlx_pixel_put(s->win, s->dataWall->index, s->map->i++, color);
	s->dataWall->y_image[s->dataWall->index]++;
}

static void		search_y_texture(t_all *s, double y_slice, int h_texture, \
								 double sliceWnot)
{
	s->dataWall->y_image[s->dataWall->index] = floor(y_slice * (h_texture ) /\
													(sliceWnot));
}

void		drawing_walls(t_all *s, t_dataWall *dataWall, t_wall *wall)
{	
	int y;

	y = -1;
	while (++y < dataWall->wall_h[dataWall->index])
	{
		if (dataWall->side_of_world[dataWall->index] == 'N')
		{
			search_y_texture(s, calc_y(dataWall, y), wall[NORD].height, dataWall->wall_hFull[dataWall->index]);
			printSliceWall(s, wall[NORD].adr, wall[NORD].size_line, wall[NORD].bits_per_pixel);
		}
		else if (dataWall->side_of_world[dataWall->index] == 'E')
		{
			search_y_texture(s, calc_y(dataWall, y), wall[EAST].height, dataWall->wall_hFull[dataWall->index]);
			printSliceWall(s, wall[EAST].adr, wall[EAST].size_line, wall[EAST].bits_per_pixel);
		}
		else if (dataWall->side_of_world[dataWall->index] == 'W')
		{
			search_y_texture(s, calc_y(dataWall, y), wall[WEST].height, dataWall->wall_hFull[dataWall->index]);
			printSliceWall(s, wall[WEST].adr, wall[WEST].size_line, wall[WEST].bits_per_pixel);		
		}
		else if (dataWall->side_of_world[dataWall->index] == 'S')
		{
			search_y_texture(s, calc_y(dataWall, y), wall[SOUTH].height, dataWall->wall_hFull[dataWall->index]);
			printSliceWall(s, wall[SOUTH].adr, wall[SOUTH].size_line, wall[SOUTH].bits_per_pixel);
		}		
	}
}