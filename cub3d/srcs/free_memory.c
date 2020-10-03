/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:43:07 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/03 12:00:53 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	ft_freearrmap(char **map)
{
	if (map)
	{
		free(map);
		map = NULL;
	}
}

void	lstdelone_f(void *d) 
{	
	if (d)
	{
		free(d);
		d = NULL;
	}
}

void	free_memory_from_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{	
		ft_free_tmp(tmp->content);
		tmp = tmp->next;
	}
	free(head);
}
