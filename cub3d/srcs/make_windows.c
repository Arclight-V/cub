/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:48:28 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/06 11:28:07 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	checking_direction(double *direction)
{
	if (*direction > TWO_PI)
		*direction -= TWO_PI;
	else if (*direction < 0)
		*direction += TWO_PI;
}

void raycasting(t_all *s, t_data *data, t_map *map, t_const *cnst)
{
	map->angle_start = map->a_p + M_PI_6;
	while (++data->index < s->win->x)
	{
		checking_direction(&map->angle_start);
		first_horisont_intersection(map);
		first_vertical_intersection(map);
		horizontal_intersection_with_wall(map, cnst);
		vertical_intersection_with_wall(map, cnst);
		calculating_nearest_distance_to_wall(map, data);
		calculating_wall_length_in_one_slice(s, data, map, cnst);	
		map->angle_start -= cnst->delta_ray;
	}
}

int			render_next_frame(t_all *s)
{

	s->data->index = -1;
	raycasting(s, s->data, s->map, s->cnst);
	if ((drawing_screen(s, s->data, s->map, s->cnst)) < 0)
		return (-1);
	mlx_put_image_to_window(s->win->mlx, s->win->win, s->win->img, 0, 0);
	// mlx_destroy_image(s->win->mlx, s->win->img);
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