/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_validity_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:31:47 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 21:13:11 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			checking_validity_map(t_all *s, char *line)
{
	int			i;

	i = 0;
	ft_skip_spaces(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ')
		checking_resolution(s, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		checking_textures_wall(s, line, NORD);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		checking_textures_wall(s, line, SOUTH);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		checking_textures_wall(s, line, WEST);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		checking_textures_wall(s, line, EAST);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		checking_textures_sprite(s, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		checking_color(s, line, &s->map->floor);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		checking_color(s, line, &s->map->ceil);
	else if (line[i] == '1')
		check_forbid_characters_map(s, line, &i);
	else if (ft_skip_spaces(line, &i) && line[i] != '\0')
		ft_error_output(s, MAP_3);
}
