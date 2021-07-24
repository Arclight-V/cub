/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:59:46 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 21:10:17 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	checking_borders(t_all *s, char **map, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (map[i][++j])
		{
			if (i == 0 || i == (size - 1))
			{
				if (map[i][j] != '1' && map[i][j] != ' ')
					ft_error_output(s, MAP_1);
			}
			if (map[1][j] == '0' && map[0][j] != '1')
				ft_error_output(s, MAP_1);
			if (map[size - 2][j] == '0' && map[size - 1][j] != '1')
				ft_error_output(s, MAP_1);
		}
		if (map[i][0] != '1' && map[i][0] != ' ')
			ft_error_output(s, MAP_1);
		if (map[i][j - 1] != '1' && map[i][j - 1] != ' ')
			ft_error_output(s, MAP_1);
	}
}

static void	checking_player(char ch, int *player)
{
	if (ch == 'N' || ch == 'S' ||\
		ch == 'E' || ch == 'W')
		(*player)++;
}

static void	checking_empty_line(t_all *s, char **map, int size)
{
	int i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		if (ft_skip_spaces(&map[i][j], &j) && map[i][j] == '\0')
			ft_error_output(s, MAP_1);
	}
}

void		checking_map(t_all *s, int size)
{
	int		i;
	int		j;
	char	**map;

	map = s->map->map;
	i = 0;
	checking_borders(s, s->map->map, size);
	checking_empty_line(s, s->map->map, size);
	while (++i < size)
	{
		j = 1;
		while (s->map->map[i][j])
		{
			checking_player(map[i][j], &s->fd->player);
			if (map[i][j] == '0' || map[i][j] == '2' || map[i][j] == 'S' || \
				map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W')
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || \
					map[i - 1][j] == ' ' || map[i - 1][j] == ' ')
					ft_error_output(s, MAP_1);
			j++;
		}
	}
	if ((s->fd->player == 0) || (s->fd->player > 1))
		ft_error_output(s, MAP_4);
}
