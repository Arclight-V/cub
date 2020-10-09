/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersection_with_wall.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:51:38 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 22:03:23 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_intersection_with_wall(t_map *m, t_const *cnst)
{
	if ((m->x_vertical > 0 && m->x_vertical < cnst->x_max)
		&& (m->y_vertical > 0 && m->y_vertical < cnst->y_max))
	{
		if (m->map[(int)m->y_vertical >> 6][(int)m->x_vertical >> 6] != '1')
		{
			m->y_vertical += m->Y_a_v;
			m->x_vertical += m->X_a_v;
			vertical_intersection_with_wall(m, cnst);
		}
	}
}
