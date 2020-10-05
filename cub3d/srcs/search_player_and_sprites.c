/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_player_and_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:43:30 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/05 17:54:51 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_search_view(t_map *map, int ch, int x, int y)
{
	map->x_p = x;
	map->y_p = y;
	if (ch == 'N')
		map->a_p = M_PI_2;
	else if (ch == 'S')
		map->a_p = TREE_PI_ON_2;
	else if (ch == 'E')
		map->a_p = M_PI;
	else if (ch == 'W')
		map->a_p = TWO_PI;
	
}

static void	rec_coord_of_sprt(t_sprite *sprt, int i, int *x, int *y)
{
	sprt[i].x = *x + 16;
	sprt[i].y = *y + 16;
	*x += CUBE;
	*y += CUBE;
}

void 	search_player_and_sprites(t_map *map, t_sprite *sprite, int x, int y)
{
	int k;
	int i;
	int j;
	int	count_sprites;

	k = CUBE;
	i = -1;
	count_sprites = -1;
	while (++i < map->size)
	{
		j = -1;
		while (map->map[i][++j])
		{
				y = i * CUBE + 1;
				x = j * CUBE;
				k = x + CUBE;
				while (y++ < ( (i + 1) * CUBE))
				{
					while (x++ < k - 1)
						if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
							|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
							ft_search_view(map, map->map[i][j], x, y);
						else if (map->map[i][j] == '2')
							rec_coord_of_sprt(sprite, ++count_sprites, &x, &y);
					x = j * CUBE;
				}
		}
	}
	map->x_p -= 16;
	map->y_p -= 16;
}