/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:38:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 20:09:38 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strnstrindex(char *big, char *little)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (big == NULL)
		return (0);
	while (big[++i])
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (little[j] && big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return (i + j - 1);
		}
	}
	return (0);
}

int		ft_skip_spaces(char *line, int *i)
{

	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

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
				while(ft_isdigit(nptr[*i]))
					(*i)++;
				return (res * sign);
			}
	}
	return (res * sign);
}
