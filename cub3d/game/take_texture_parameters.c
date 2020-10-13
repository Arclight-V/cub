/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_texture_parameters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:17:58 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/13 19:43:31 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	take_texture_parameters(t_all *s, int item)
{
	int i;

	i = -1;
	if (!(s->sprite = (t_sprite *)malloc(item * (sizeof(t_sprite)))))
		ft_error_output(s, MALLOC_13);
	while (++i < item)
	{
		s->sprite[i].img = mlx_xpm_file_to_image(s->win->mlx, s->fd->filename,\
							&s->sprite[i].width, &s->sprite[i].height);
		if (!(s->sprite[i].img))
			ft_error_output(s, TEXTURE_7);
		s->sprite[i].adr = mlx_get_data_addr(s->sprite[i].img,
		&s->sprite[i].bps, &s->sprite[i].size_line, &s->sprite[i].endian);
	}
	i = -1;
	while (++i < 4)
	{
		s->wall[i].img = mlx_xpm_file_to_image(s->win->mlx, s->wall[i].filename\
									, &s->wall[i].width, &s->wall[i].height);
		if (!(s->wall[i].img))
			ft_error_output(s, TEXTURE_8);
		s->wall[i].adr = mlx_get_data_addr(s->wall[i].img, &s->wall[i].bps, \
									&s->wall[i].size_line, &s->wall[i].endian);
	}
}
