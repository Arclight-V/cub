/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:52:39 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 17:55:27 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_max_len(t_all *s, t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		if (s->fd->flag == 0)
		{
			s->fd->max_len = tmp->len;
			tmp = tmp->next;
			s->fd->flag = 1;
		}
		else
		{
			if (s->fd->max_len > tmp->len)
				s->fd->max_len = s->fd->max_len;
			else
				s->fd->max_len = tmp->len;
			tmp = tmp->next;
		}
	}
}
