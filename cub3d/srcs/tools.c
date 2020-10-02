/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:38:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/02 12:03:42 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strnstrindex(char *big, char *little)
{
	size_t	i;
	size_t	j;

	i = -1;
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

int		ft_strerror(int err)
{
	
	(err == -10) ? write(2, "Error : Malloc fail (ft_creat_map_s)\n", 36) : 0;
	(err == -11) ? write(2, "Error : Malloc fail (ft_creat_err_s)\n", 36) : 0;
	(err == -12) ? write(2, "Error : Malloc fail (ft_creat_fd_s)\n", 35) : 0;
	(err == -13) ? write(2, "Error : Malloc fail (ft_creat_all_s)\n", 36) : 0;
	(err == -14) ? write(2, "Error : Malloc fail (ft_make_map)\n", 34) : 0;
	(err == -15) ? write(2, "Error : Malloc fail (creating a list from fd)\n", 45) : 0;

	// (err == -3) ? write(2, "Error : Malloc fail (creating a two-dimensional array of pointers)\n", 35) : 0;
	
	
	// (err == -5) ? write(2, "Error : Floor/ceiling specified twice\n", 38) : 0;
	// (err == -6) ? write(2, "Error : Invalid floor/ceiling line\n", 35) : 0;
	// (err == -7) ? write(2, "Error : Texture path specified twice\n", 37) : 0;
	// (err == -8) ? write(2, "Error : Malloc fail (texture path)\n", 35) : 0;
	// (err == -9) ? write(2, "Error : Invalid texture image\n", 30) : 0;
	// (err == -11) ? write(2, "Error : Malloc fail (map table)\n", 32) : 0;
	// (err == -12) ? write(2, "Error : Invalid map\n", 20) : 0;
	(err == -13) ? write(2, "Error : Map isn't a rectangle\n", 30) : 0;
	(err == -14) ? write(2, "Error : No resolution specified\n", 32) : 0;
	(err == -15) ? write(2, "Error : Missing texture\n", 24) : 0;
	(err == -16) ? write(2, "Error : Missing floor/ceiling color\n", 26) : 0;
	(err == -17) ? write(2, "Error : No starting position\n", 29) : 0;
	(err == -18) ? write(2, "Error : Multiple starting positions\n", 36) : 0;
	(err == -19) ? write(2, "Error : Map isn't surrounded by walls\n", 38) : 0;
	
	(err == -90) ? write(2, "Error : Couldn't parse file (GNL)\n", 34) : 0;
	(err == -91) ? write(2, "Error : Couldn't read fd\n", 25) : 0;
	(err == -92) ? write(2, "Error : Invalid line in file\n", 29) : 0;
	(err == -1) ? ft_errorstr(RESOLUTION_1, 0) : 0;
	(err == -2) ? ft_errorstr(RESOLUTION_2, 0) : 0;
	(err == -3) ? ft_errorstr(TEXTURE_1, 0) : 0;
	(err == -4) ? ft_errorstr(TEXTURE_2, 0) : 0;
	(err == -5) ? ft_errorstr(MALLOC_12, 0) : 0;
	(err == -6) ? ft_errorstr(FD_2, 0) : 0;
	(err == -7) ? ft_errorstr(TEXTURE_3, 0) : 0;
	(err == -8) ? ft_errorstr(TEXTURE_4, 0) : 0;
	(err == -9) ? ft_errorstr(TEXTURE_5, 0) : 0;
	(err == -10) ? ft_errorstr(MALLOC_13, 0) : 0;
	(err == -11) ? ft_errorstr(FD_3, 0) : 0;
	(err == -12) ? ft_errorstr(TEXTURE_6, 0) : 0;
	
	(err == -13) ? ft_errorstr(FLOOR_1, 0) : 0;
	(err == -14) ? ft_errorstr(FLOOR_2, 0) : 0;


	return (-1);
}
