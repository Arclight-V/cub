/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:48:28 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 17:20:31 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			make_windows(t_win *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->x, win->y, "Cub3D");
	win->img = mlx_new_image(win->mlx, win->x, win->y);
	win->addr = mlx_get_data_addr(win->img, &win->bps, &win->line_lenght,\
														&win->endian);
}
