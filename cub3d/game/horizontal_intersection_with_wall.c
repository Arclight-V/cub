/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersection_with_wall.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:47:21 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 22:03:23 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_intersection_with_wall(t_map *m, t_const *cnst)
{
	if ((m->x_horizont > 0 && m->x_horizont < cnst->x_max) && \
		(m->y_horizont > 0 && m->y_horizont < cnst->y_max))
	{
		if (m->map[(int)m->y_horizont >> 6][(int)m->x_horizont >> 6] != '1')
		{
			m->y_horizont += m->Y_a_h;
			m->x_horizont += m->X_a_h;
			horizontal_intersection_with_wall(m, cnst);
		}
	}
}
