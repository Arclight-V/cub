/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:00:42 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/05 18:24:12 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		draw_square(t_all *s, int x, int y)
{
	int i = x - 2;
	int	j = y - 2;
	while (i != x + 2)
	{
		j = y - 2;
		while(j != y + 2)
		{
			my_mlx_pixel_put(s->win, i, j, 0x1456e3);
			j++;
		}
		i++;
	}
}

int			drawRayToWall(t_all *s, int xPlayer, int yPlayer, int xWall, int yWall)
{
	int	dx = xWall - xPlayer;
	int	dy = yWall - yPlayer;
	int		steps;
	float x_increment;
	float y_increment;
	float x = xPlayer;
	float y = yPlayer;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x_increment = dx / (float)steps;
	y_increment = dy / (float)steps;
	int i = 0;
	while (i < steps)
	{
		x +=x_increment;
		y += y_increment;
		my_mlx_pixel_put(s->win, round(x), round(y), 0x1456e3);
		i++;
	}
}

void 		draw2DMap(t_all *s)
{
	int k;
	int i;
	int j;
	int x;
	int y = -1;
	i = -1;
	k = CUBE;
	int a = 1;
	while (++i < s->map->size)
	{
		{
			while (++y < (i + 1) * CUBE)
			{
				x = -1;
				j = 0;
				while (s->map->map[i][j])
				{
					while (++x < (j + 1) * CUBE)
					{
						if (s->map->map[i][j] == '1')
						{
							if ((x + 1) == ((j + 1) * CUBE))
							{
								my_mlx_pixel_put(s->win, x, y, 0xaa0000);
								my_mlx_pixel_put(s->win, x + 1, y, 0xaa0000);
							}
							else
								my_mlx_pixel_put(s->win, x, y, 0x878794);
						}
						else if (s->map->map[i][j] == '0' || s->map->map[i][j] == 'N' ||
								s->map->map[i][j] == '2' || s->map->map[i][j] == 'W' ||
								s->map->map[i][j] == 'U' || s->map->map[i][j] == 'S')
						{	
							if ((x + 1) == ((j + 1) * CUBE))
							{
								my_mlx_pixel_put(s->win, x, y, 0xaa0000);
								my_mlx_pixel_put(s->win, x + 1, y, 0xaa0000);
							}
							else
								my_mlx_pixel_put(s->win, x, y, 0x36054d);
						}
					}
					j++;
				}
				if ((y + 1) == ((i + 1) * CUBE))
				{
					x = -1;
					j--;
					while (++x < (j + 1) * CUBE)
					{
						my_mlx_pixel_put(s->win, x, y, 0xaa0000);
						my_mlx_pixel_put(s->win, x, y + 1, 0xaa0000);
					}
				}
			}
		}
	}
}
