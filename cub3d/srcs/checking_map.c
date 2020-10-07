/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:13:33 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 18:22:11 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void			ft_forb_char_map(t_all *s, t_list *head, char *line, int *i)
{
	if (s->fd->count_ind >= 8)
	{
		while (line[*i])
		{
			if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N') || \
				(line[*i] == 'S' || line[*i] == 'E' || line[*i] == 'W') || \
				line[*i] == ' ')
				(*i)++;
			else if (line[*i] == '2')
			{
				s->map->item++;
				(*i)++;
			}
			else if (line[*i] != '\0')
				ft_errorstr(s, head, MAP_1);
			s->fd->count_ind++;
		}
	}
	else
		ft_errorstr(s, head, MAP_2);
}
