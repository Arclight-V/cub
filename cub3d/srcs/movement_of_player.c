/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_of_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:56:31 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 10:13:31 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_forward_back(t_map *map, int i)
{
	map->x_p += i * cos(map->a_p) * 10;
	map->y_p -= i * sin(map->a_p) * 10;
}

void			ft_rotate(double *direction, int i)
{
	
	*direction += (i * 0.03);
	checking_direction(direction);

}

void	ft_move_left_right(t_map *map, int i)
{
	map->x_p += i * sin(map->a_p) * 10;	
	map->y_p += i * cos(map->a_p) * 10;
}


int			keystroke(int keycode, t_all *s)
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
		ft_errorstr(s, END);
	else if (keycode == UP)
		s->data->celing_h[s->data->index]--;
	return (0);
}
