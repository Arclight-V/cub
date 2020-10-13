/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:03:26 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/13 19:36:35 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_all *s)
{
	mlx_destroy_window(s->win->mlx, s->win->win);
	s->win->win = NULL;
	mlx_destroy_image(s->win->mlx, s->win->img);
	s->win->img = NULL;
	game_exit(s, 0);
	return (1);
}
