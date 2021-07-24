/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:40:49 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 21:03:46 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void		checking_color(t_all *s, char *line, int *color)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 1;
	if (*color >= 0)
		ft_error_output(s, FLOOR_1);
	r = ft_atoi_mod(line, &i);
	if (ft_skip_spaces(line, &i) && line[i] != ',')
		ft_error_output(s, FLOOR_2);
	i++;
	g = ft_atoi_mod(line, &i);
	if (ft_skip_spaces(line, &i) && line[i] != ',')
		ft_error_output(s, FLOOR_2);
	i++;
	b = ft_atoi_mod(line, &i);
	ft_skip_spaces(line, &i);
	if (line[i] != '\0' || r > 255 || g > 255 || b > 255)
		ft_error_output(s, FLOOR_2);
	*color = create_trgb(0, r, g, b);
	s->fd->count_ind++;
}
