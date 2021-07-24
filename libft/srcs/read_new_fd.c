/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_new_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 10:43:46 by anatashi          #+#    #+#             */
/*   Updated: 2020/08/19 10:48:30 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl		*read_new_fd(int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->remaind = NULL;
	new->next = NULL;
	return (new);
}
