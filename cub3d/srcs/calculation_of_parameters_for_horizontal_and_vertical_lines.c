/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_of_parameters_for_horizontal_an        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:53:48 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/30 17:29:29 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		checking_coordinates_h(t_all *s)
{
	if ((s->map->x_horizont > 0 && s->map->x_horizont < s->ConstValue->xMapMax) 
		&& (s->map->y_horizont > 0 && s->map->y_horizont < s->ConstValue->yMapMax))
	{
		if (s->map->level[(int)s->map->y_horizont/CUBE_SIZE][(int)s->map->x_horizont/CUBE_SIZE] != '1')
			{
				s->map->y_horizont += s->map->Y_a_h;
				s->map->x_horizont += s->map->X_a_h;
				checking_coordinates_h(s);
			}
	}
}

void		checking_coordinates_v(t_all *s)
{
	if ((s->map->x_vertical > 0 && s->map->x_vertical < s->ConstValue->xMapMax )
		&& (s->map->y_vertical > 0 && s->map->y_vertical < s->ConstValue->yMapMax))
	{
		if (s->map->level[(int)s->map->y_vertical/CUBE_SIZE][(int)s->map->x_vertical/CUBE_SIZE] != '1')
			{
				s->map->y_vertical += s->map->Y_a_v;
				s->map->x_vertical += s->map->X_a_v;
				checking_coordinates_v(s);
			}
	}
}

void	calculatingDeltaForHorizontalIntersection(t_all *s, float a_p)
{	
	double tang;

	tang = tan(a_p);
	if (a_p > 0 && a_p < M_PI )
	{
		s->map->X_a_h = CUBE_SIZE /tang;
		s->map->y_horizont = (int)(s->map->y_pp / CUBE_SIZE) * CUBE_SIZE - 0.0001;
		s->map->x_horizont = s->map->x_pp + (s->map->y_pp - s->map->y_horizont) / tang;
		s->map->Y_a_h = -CUBE_SIZE;
	}
	else if (a_p > M_PI && a_p < s->ConstValue->two_pi)
	{
		s->map->X_a_h = -(CUBE_SIZE /tang);
		s->map->y_horizont = (int)(s->map->y_pp / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
		s->map->x_horizont = s->map->x_pp + (s->map->y_pp - s->map->y_horizont) / tang;
		s->map->Y_a_h = CUBE_SIZE;
	}
}

void	calculatingDeltaForVerticallIntersection(t_all *s, float a_p)
{
	double	tang;

	tang = tan(a_p);

	if (a_p < M_PI_2 || a_p > s->ConstValue->tree_pi_by_two)
	{
		s->map->Y_a_v = -(CUBE_SIZE * tang);
		s->map->x_vertical = (int)(s->map->x_pp / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
		s->map->y_vertical = s->map->y_pp + ((s->map->x_pp - s->map->x_vertical) * tang);
		s->map->X_a_v = CUBE_SIZE;
	}
	else if (a_p > M_PI_2 || a_p < s->ConstValue->tree_pi_by_two)
	{
		s->map->Y_a_v = CUBE_SIZE * tang;
		s->map->x_vertical = (int)(s->map->x_pp / CUBE_SIZE) * CUBE_SIZE - 0.0001;
		s->map->y_vertical = (s->map->y_pp + (s->map->x_pp - s->map->x_vertical) * tang);
		s->map->X_a_v = -CUBE_SIZE;
	}
}