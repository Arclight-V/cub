/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:13:33 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/30 18:48:11 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int				ft_forb_char_map(t_list **head, char *line, t_all *s, int *i)
{
	while (line[*i])
	{
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
			|| (line[*i] == 'S' || line[*i] == 'E' || line[*i] == 'W')
			|| line[*i] == ' ')
			;
		else if (line[*i] == '2')
		{
			s->map->item++;
		}
		else if (line[*i] != '\0')
		{
			ft_free_tmp(line);
			ft_lstclear(head,lstdelone_f);
			return (-92);
		}
		(*i)++;
	}
	s->err->num = 0;
	return (1);
}
