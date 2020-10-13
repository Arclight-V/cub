/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_memory_from_sprite_texture.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:28:53 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/13 19:13:47 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freeing_memory_from_sprite_texture(t_sprite *sprite, int i)
{
	while (i-- > 0)
	{
		ft_free_tmp(sprite[i].img);
	}
	ft_free_tmp(sprite);
}
