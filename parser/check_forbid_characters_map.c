/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_forbid_characters_map.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:13:33 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 21:06:50 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_forbid_characters_map(t_all *s, char *line, int *i)
{
	int j;

	j = 0;
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
				ft_error_output(s, MAP_1);
			s->fd->count_ind++;
		}
	}
	else
		ft_error_output(s, MAP_2);
}
