/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:21:20 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/13 18:06:18 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_hook(t_all *s, void *mlx, void *win)
{
	mlx_hook(win, 2, 1L << 0, keystroke, s);
	mlx_hook(win, 17, 1L << 17, ft_close, s);
	mlx_loop_hook(mlx, render_next_frame, s);
	mlx_loop(mlx);
}
