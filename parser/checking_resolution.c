/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:33:26 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 20:49:19 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checking_resolution(t_all *s, char *line, int *i)
{
	if (s->win->x != 0 || s->win->y != 0)
		ft_error_output(s, RESOLUTION_1);
	(*i)++;
	s->win->x = ft_atoi_mod(line, i);
	s->win->y = ft_atoi_mod(line, i);
	if (s->win->x > 2560)
		s->win->x = 2560;
	if (s->win->y > 1400)
		s->win->y = 1400;
	ft_skip_spaces(line, i);
	if (s->win->x <= 0 || s->win->y <= 0 || line[*i] != '\0')
		ft_error_output(s, RESOLUTION_2);
	s->fd->count_ind++;
}
