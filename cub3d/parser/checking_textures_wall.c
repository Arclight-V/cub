/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_textures_wall.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:36:29 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 17:44:17 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checking_textures_wall(t_all *s, t_list *head, char *line, int num)
{
	int			xpm;
	int			j;
	int			i;

	i = 2;
	if (s->wall[num].filename)
		ft_error_output(s, TEXTURE_1);
	ft_skip_spaces(line, &i);
	if ((xpm = ft_strnstrindex(line, ".xpm")))
	{
		j = xpm + 1;
		ft_skip_spaces(line, &j);
		if (line[j] != '\0')
			ft_error_output(s, TEXTURE_2);
		if (!(s->wall[num].filename = ft_substr(line, i, xpm - i + 1)))
			ft_error_output(s, MALLOC_8);
		if (open(s->wall[num].filename, O_RDONLY) < 0)
			ft_error_output(s, FD_3);
		s->fd->count_ind++;
	}
	else
		ft_error_output(s, TEXTURE_3);
}
