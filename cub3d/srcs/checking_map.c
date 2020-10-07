/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:13:33 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 10:55:51 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int				ft_forb_char_map(t_list **head, char *line, t_all *s, int *i)
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
				return (-24);
			s->fd->count_ind++;
		}
		return (0);
	}
	return (-25);
}
