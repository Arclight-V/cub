/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:48:28 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/02 12:08:37 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


int		drawing_screen(t_all *s, t_dataWall *dataWall)
{
	dataWall->index = -1;
	while(++dataWall->index < s->win->x)
	{
		s->map->i = dataWall->PositionWall[dataWall->index];
		drawing_celing(s);
		drawing_walls(s, dataWall);
		drawing_floor(s);
		drawing_sprites(s);
	}
}

int		ray(t_all *s, t_dataWall *dataWall)
{
	if (s->map->angle_start > s->ConstValue->two_pi)
		s->map->angle_start -= s->ConstValue->two_pi ;
	else if (s->map->angle_start < 0)
		s->map->angle_start += s->ConstValue->two_pi;
	calculatingDeltaForHorizontalIntersection(s, s->map->angle_start);
	calculatingDeltaForVerticallIntersection(s, s->map->angle_start);
	checking_coordinates_h(s);
	checking_coordinates_v(s);
	s->map->PD = sqrt(pow((s->map->x_pp - s->map->x_horizont), 2) + pow((s->map->y_pp - s->map->y_horizont), 2));
	s->map->PE = sqrt(pow((s->map->x_pp - s->map->x_vertical), 2) + pow((s->map->y_pp - s->map->y_vertical), 2));
	if (s->map->PD < s->map->PE)
	{
		s->dataWall->distance_wall_not_corr[s->dataWall->index] = s->map->PD;
		s->dataWall->distance_wall[s->dataWall->index] = s->map->PD * cos(s->map->a_p - s->map->angle_start);
		s->map->flagPDPE = 1;
	}
	else
	{
		s->dataWall->distance_wall_not_corr[s->dataWall->index] = s->map->PE;
		s->dataWall->distance_wall[s->dataWall->index] = s->map->PE * cos(s->map->a_p - s->map->angle_start);
		s->map->flagPDPE = 0;
	}
	calculating_wall_length_in_one_slice(s, dataWall);
	return (0);
	
}


void raycasting(t_all *s, t_dataWall *dataWall)
{

	s->map->angle_start = s->map->a_p + s->ConstValue->thiry_degrees;
	while (++dataWall->index < s->win->x)
	{
		ray(s, dataWall);
		s->map->angle_start -= s->ConstValue->delta_ray;
	}
}

int			render_next_frame(t_all *s)
{

	s->dataWall->index = -1;
	raycasting(s, s->dataWall);
	drawing_screen(s, s->dataWall);
	// draw2DMap(s);
	// ft_ray_cast_2(s, s->dataWall);
	// my_mlx_pixel_put(s->win, s->map->x_pp, s->map->y_pp, 0x1456e3);
	// for (int i = 0; i < s->map->item; i++)
	// 	my_mlx_pixel_put(s->win, s->sprite[i].x, s->sprite[i].y, 0x1456e3);
	mlx_put_image_to_window(s->win->mlx, s->win->win, s->win->img, 0, 0);
	return (0);
}

int			make_windows(t_all *s, t_win *win)
{	

    s->win->mlx = mlx_init();
    s->win->win = mlx_new_window(s->win->mlx, s->win->x, s->win->y, "Cub3D");
	s->win->img = mlx_new_image(s->win->mlx, s->win->x, s->win->y);
	s->win->addr = mlx_get_data_addr(s->win->img, &win->bits_per_pixel, &win->line_lenght, &win->endian);
	return (1);
}