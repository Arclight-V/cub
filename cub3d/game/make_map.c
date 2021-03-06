/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:45:13 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 19:40:28 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		make_map(t_all *s, int size)
{
	t_list	*tmp;
	int		i;
	int		j;

	tmp = s->head;
	i = -1;
	j = -1;
	if (!(s->map->map = ft_calloc(size + 1, sizeof(char *))))
		ft_error_output(s, MALLOC_12);
	while (tmp)
	{
		s->map->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	while (s->map->map[++j])
		ft_putendl(s->map->map[j]);
}
