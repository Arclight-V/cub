/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:26:39 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 17:44:17 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		*ft_creat_list(t_all *s, t_list *head, char *line)
{
	t_list	*new;

	new = NULL;
	checking_validity_map(s, head, line);
	if (s->fd->count_ind > 8)
	{
		if (!(new = ft_lstnew(line)))
			ft_error_output(s, MALLOC_10);
		ft_lstadd_back(&head, new);
		return (head);
	}
	ft_free_tmp(line);
	return (head);
}
