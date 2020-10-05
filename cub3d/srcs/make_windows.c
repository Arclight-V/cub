/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:48:28 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/05 15:52:53 by anatashi         ###   ########.fr       */
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
		drawing_walls(s, dataWall, s->wall);
		drawing_floor(s->map, s->win, dataWall->index);
		drawing_sprites(s, s->dataWall, s->sprite);
	}
}

void	checking_direction(double *direction)
{
	if (*direction > TWO_PI)
		*direction -= TWO_PI;
	else if (*direction < 0)
		*direction += TWO_PI;
}

void raycasting(t_all *s, t_dataWall *dataWall, t_map *map, t_const *cnst)
{
	map->angle_start = map->a_p + cnst->thiry_degrees;
	while (++dataWall->index < s->win->x)
	{
		checking_direction(&map->angle_start);
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
	if ((drawing_screen(s, s->dataWall, s->map, s->cnst)) < 0)
		return (-1);
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