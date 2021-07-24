/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_memory_from_fd_structure.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:32:09 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 19:32:57 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freeing_memory_from_fd_structure(t_fd *fd)
{
	ft_free_tmp(fd->filename);
	ft_free_tmp(fd);
}
