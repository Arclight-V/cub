/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_memory_form_wall_texture.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:34:27 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 19:35:19 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freeing_memory_form_wall_texture(t_wall *wall)
{
	int i;

	i = 4;
	while (--i >= 0)
	{
		ft_free_tmp(wall[i].adr);
		ft_free_tmp(wall[i].img);
	}
	ft_free_tmp(wall);
}
