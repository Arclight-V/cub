/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystroke.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:56:31 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/17 19:06:09 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	ft_move_forward_back(t_map *map, int i)
{
	map->x_p += i * cos(map->a_p) * 10;
	map->y_p -= i * sin(map->a_p) * 10;
}

static	void	ft_rotate(double *direction, int i)
{
	*direction += (i * 0.03);
	checking_direction(direction);
}

static	void	ft_move_left_right(t_map *map, int i)
{
	map->x_p += i * sin(map->a_p) * 10;
	map->y_p += i * cos(map->a_p) * 10;
}

int				keystroke(int keycode, t_all *s)
{
	if (keycode == W)
		ft_move_forward_back(s->map, 1);
	else if (keycode == A)
		ft_move_left_right(s->map, -1);
	else if (keycode == S)
		ft_move_forward_back(s->map, -1);
	else if (keycode == D)
		ft_move_left_right(s->map, 1);
	else if (keycode == RIGHT)
		ft_rotate(&s->map->a_p, -1);
	else if (keycode == LEFT)
		ft_rotate(&s->map->a_p, 1);
	else if (keycode == ESC)
		ft_error_output(s, END);
	return (0);
}
