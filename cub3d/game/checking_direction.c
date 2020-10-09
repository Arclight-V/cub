/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_direction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:48:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 17:18:08 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checking_direction(double *direction)
{
	if (*direction > TWO_PI)
		*direction -= TWO_PI;
	else if (*direction < 0)
		*direction += TWO_PI;
}
