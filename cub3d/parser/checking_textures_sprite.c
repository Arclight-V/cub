/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_textures_sprite.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:38:41 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 17:44:17 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		checking_textures_sprite(t_all *s, t_list *head, char *line, int *i)
{
	int		xpm;
	int		j;

	if (s->fd->flag_sprite != 0)
		ft_error_output(s, TEXTURE_4);
	(*i)++;
	ft_skip_spaces(line, i);
	if ((xpm = ft_strnstrindex(line, ".xpm")))
	{
		j = xpm + 1;
		ft_skip_spaces(line, &j);
		if (line[j] != '\0')
			ft_error_output(s, TEXTURE_5);
		if (!(s->fd->filename = ft_substr(line, (*i), xpm - (*i) + 1)))
			ft_error_output(s, MALLOC_9);
		if (open(s->fd->filename, O_RDONLY) < 0)
			ft_error_output(s, FD_4);
		s->fd->flag_sprite = 1;
		s->fd->count_ind++;
	}
	else
		ft_error_output(s, TEXTURE_6);
}
