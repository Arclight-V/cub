/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_memory_from_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:27:16 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 20:36:13 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freeing_memory_from_list(t_list *head)
{
	ft_lstclear(&head, ft_lstdelone_f);
	ft_free_tmp(head);
}
