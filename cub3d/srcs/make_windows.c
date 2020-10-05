/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:48:28 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/05 12:42:54 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


int		drawing_screen(t_all *s, t_dataWall *dataWall, t_map *map, t_const *cnst)
{
	dataWall->index = -1;
	while(++dataWall->index < s->win->x)
	{
		s->map->i = dataWall->celing_h[dataWall->index];
		drawing_celing(dataWall, s->win, map->ceil);
		drawing_walls(s, dataWall);
		drawing_floor(s);
		drawing_sprites(s);
	}
}

void	checking_direction(double *direction, double two_PI)
{
	if (*direction > two_PI)
		*direction -= two_PI;
	else if (*direction < 0)
		*direction += two_PI;
}

void raycasting(t_all *s, t_dataWall *dataWall, t_map *map, t_const *cnst)
{
	map->angle_start = map->a_p + cnst->thiry_degrees;
	while (++dataWall->index < s->win->x)
	{
		checking_direction(&map->angle_start, cnst->two_PI);
		first_horisont_intersection(map);
		first_vertical_intersection(map, cnst->tree_PI_on_two);
		horizontal_intersection_with_wall(map, cnst);
		vertical_intersection_with_wall(map, cnst);
		calculating_nearest_distance_to_wall(map, dataWall);
		calculating_wall_length_in_one_slice(s, dataWall, map, cnst);	
		map->angle_start -= cnst->delta_ray;
	}
}

int			render_next_frame(t_all *s)
{

	s->dataWall->index = -1;
	raycasting(s, s->dataWall, s->map, s->cnst);
	drawing_screen(s, s->dataWall, s->map, s->cnst);
	// draw2DMap(s);
	// ft_ray_cast_2(s, s->dataWall);
	// my_mlx_pixel_put(s->win, s->map->x_p, s->map->y_p, 0x1456e3);
	// for (int i = 0; i < s->map->item; i++)
	// 	my_mlx_pixel_put(s->win, s->sprite[i].x, s->sprite[i].y, 0x1456e3);
	mlx_put_image_to_window(s->win->mlx, s->win->win, s->win->img, 0, 0);
	mlx_do_sync(s->win->mlx);
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