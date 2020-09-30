/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:45:13 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/30 17:29:39 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		**make_map(t_list **head, int size, t_all *s)
{
	s->map->level = ft_calloc(size + 1, sizeof(char *));
	int		i = -1;
	size_t	j = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		s->map->level[++i] = tmp->content;
		tmp = tmp->next;
	}
	while (s->map->level[++j])
		ft_putendl(s->map->level[j]);
	return (s->map->level);
}