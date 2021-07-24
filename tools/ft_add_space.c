/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:21:14 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 17:44:17 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list		*ft_add_space(t_all *s, t_list *head)
{
	t_list	*tmp;
	char	*tmp_str;

	tmp = head;
	ft_max_len(s, head);
	while (tmp)
	{
		if (tmp->len < s->fd->max_len)
		{
			tmp_str = tmp->content;
			tmp->len = s->fd->max_len - tmp->len;
			if (!(tmp->content = ft_str_add_char(tmp->content, tmp->len, ' ')))
				ft_error_output(s, MALLOC_11);
			ft_free_tmp(tmp_str);
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (head);
}
