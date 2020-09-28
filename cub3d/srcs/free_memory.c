/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:43:07 by anatashi          #+#    #+#             */
/*   Updated: 2020/08/23 09:46:56 by anatashi         ###   ########.fr       */
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
