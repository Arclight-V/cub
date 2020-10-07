/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:38:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 12:52:02 by anatashi         ###   ########.fr       */
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

static int		ft_strerror_2(t_all *s, t_list *head, int err)
{
	(err == -24) ? ft_errorstr(s, head, MAP_1) : 0;
	(err == -25) ? ft_errorstr(s, head, MAP_2) : 0;
	(err == -26) ? ft_errorstr(s, head, MAP_3) : 0;
	(err == -27) ? ft_errorstr(s, head, MALLOC_11) : 0;
	(err == -28) ? ft_errorstr(s, head, MALLOC_12) : 0;
	(err == -29) ? ft_errorstr(s, head, MAP_4) : 0;


	return (1);

}

int		ft_strerror(t_all *s, t_list *head, int err)
{
	(err == -1) ? ft_errorstr(s, head, MALLOC_1) : 0;
	(err == -2) ? ft_errorstr(s, head, MALLOC_2) : 0;
	(err == -3) ? ft_errorstr(s, head, MALLOC_3) : 0;
	(err == -4) ? ft_errorstr(s, head, MALLOC_4) : 0;
	(err == -5) ? ft_errorstr(s, head, MALLOC_5) : 0;
	(err == -6) ? ft_errorstr(s, head, MALLOC_6) : 0;
	(err == -7) ? ft_errorstr(s, head, MALLOC_7) : 0;
	(err == -8) ? ft_errorstr(s, head, FD_1) : 0;
	(err == -9) ? ft_errorstr(s, head, FD_2) : 0;
	(err == -10) ? ft_errorstr(s, head, RESOLUTION_1) : 0;
	(err == -11) ? ft_errorstr(s, head, RESOLUTION_2) : 0;
	(err == -12) ? ft_errorstr(s, head, TEXTURE_1) : 0;
	(err == -13) ? ft_errorstr(s, head, TEXTURE_2) : 0;
	(err == -14) ? ft_errorstr(s, head, MALLOC_8) : 0;
	(err == -15) ? ft_errorstr(s, head, FD_3) : 0;
	(err == -16) ? ft_errorstr(s, head, TEXTURE_3) : 0;
	(err == -17) ? ft_errorstr(s, head, TEXTURE_4) : 0;
	(err == -18) ? ft_errorstr(s, head, TEXTURE_5) : 0;
	(err == -19) ? ft_errorstr(s, head, MALLOC_9) : 0;
	(err == -20) ? ft_errorstr(s, head, FD_4) : 0;
	(err == -21) ? ft_errorstr(s, head, TEXTURE_6) : 0;
	(err == -22) ? ft_errorstr(s, head, FLOOR_1) : 0;
	(err == -23) ? ft_errorstr(s, head, FLOOR_2) : 0;
	(err < -23) ? ft_strerror_2(s, head, err) : 0;
	return (1);
}
