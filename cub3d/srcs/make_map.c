/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:45:13 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 12:26:31 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**make_map(t_list **head, int size, t_all *s)
{
	t_list	*tmp;
	int	i;
	int	j;

	tmp = *head;
	i = -1;
	j = -1;
	if (!(s->map->map = ft_calloc(size + 1, sizeof(char *))))
	{
		s->fd->err = -28;
		return (NULL);
	}
	while (tmp)
	{
		s->map->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	while (s->map->map[++j])
		ft_putendl(s->map->map[j]);
	return (s->map->map);
}