/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:40:13 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 17:42:38 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_atoi_mod(const char *nptr, int *i)
{
	int			sign;
	int			res;

	sign = 1;
	res = 0;
	while (ft_isspace(nptr[*i]))
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (ft_isdigit(nptr[*i]))
	{
		res = res * 10 + (nptr[*i] - '0');
		(*i)++;
		if (res > 2560)
		{
			while (ft_isdigit(nptr[*i]))
				(*i)++;
			return (res * sign);
		}
	}
	return (res * sign);
}
