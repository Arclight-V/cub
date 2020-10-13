/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_memory_from_win_structure.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:25:14 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/13 18:04:46 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freeing_memory_from_win_structure(t_win *win)
{
	if (win->win)
	{
		mlx_destroy_window(win->mlx, win->win);
		win->win = NULL;
	}
	if (win->img)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = NULL;
	}
	ft_free_tmp(win);
}
