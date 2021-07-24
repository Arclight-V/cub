/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_memory_from_map_structure.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:30:13 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 20:36:41 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freeing_memory_from_map_structure(t_map *map)
{
	free(map->map);
	free(map);
	map = NULL;
}
