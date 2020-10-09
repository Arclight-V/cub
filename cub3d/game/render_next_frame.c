/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:50:47 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 11:55:29 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


int			render_next_frame(t_all *s)
{

	s->data->index = -1;
	raycasting(s, s->data, s->map, s->cnst);
	if ((drawing_screen(s, s->data, s->map, s->cnst)) < 0)
		return (-1);
	mlx_put_image_to_window(s->win->mlx, s->win->win, s->win->img, 0, 0);
	mlx_do_sync(s->win->mlx);
	return (0);
}