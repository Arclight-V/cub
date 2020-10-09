/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:50:47 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 17:21:17 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			render_next_frame(t_all *s)
{
	s->data->i = -1;
	raycasting(s, s->data, s->map, s->cnst);
	drawing_screen(s, s->data, s->map, s->cnst);
	mlx_put_image_to_window(s->win->mlx, s->win->win, s->win->img, 0, 0);
	mlx_do_sync(s->win->mlx);
	return (0);
}
