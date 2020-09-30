/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_of_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:56:31 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/30 16:01:16 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_forward_back(t_all *s, int i)
{
	s->map->x_pp += i * cos(s->map->a_p) * 10;
	s->map->y_pp -= i * sin(s->map->a_p) * 10;
}

void			ft_rotate(t_all *s, int i)
{
	s->map->a_p = s->map->a_p + i * 0.04;
	if (s->map->a_p > s->ConstValue->two_pi)
		s->map->a_p -= s->ConstValue->two_pi;
	else if (s->map->a_p < 0)
		s->map->a_p += s->ConstValue->two_pi;
}

void	ft_move_left_right(t_all *s, int i)
{
	s->map->x_pp += i * sin(s->map->a_p) * 10;	
	s->map->y_pp += i * cos(s->map->a_p) * 10;
}

int			ft_key(int keycode, t_all *s)
{
	if (keycode == W)
		ft_move_forward_back(s, 1);
	else if (keycode == A)
		ft_move_left_right(s, -1);
	else if (keycode == S)
		ft_move_forward_back(s, -1);
	else if (keycode == D)
		ft_move_left_right(s, 1);
	else if (keycode == RIGHT)
		ft_rotate(s, -1);
	else if (keycode == LEFT)
		ft_rotate(s, 1);
	else if (keycode == UP)
		s->dataWall->PositionWall[s->dataWall->index]--;
	else if (keycode == ESC)
		mlx_destroy_window(s->win->mlx, s->win->win);
	return (0);
}
