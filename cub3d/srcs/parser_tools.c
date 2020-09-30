/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:59:41 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/30 12:31:06 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int				ft_forb_char_map(t_list **head, char *line, t_all *s, int *i)
{
	while (line[*i])
	{
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
			|| (line[*i] == 'S' || line[*i] == 'E' || line[*i] == 'W')
			|| line[*i] == ' ')
			;
		else if (line[*i] == '2')
		{
			s->map->item++;
		}
		else if (line[*i] != '\0')
		{
			ft_free_tmp(line);
			ft_lstclear(head,lstdelone_f);
			return (-92);
		}
		(*i)++;
	}
	s->err->num = 0;
	return (1);
}

int				checking_resolution(t_all *s, char *line, int *i)
{
	if (s->win->x != 0 || s->win->y != 0)
		return(-1);
	(*i)++;
	s->win->x = ft_atoi_mod(line, i);
	s->win->y = ft_atoi_mod(line, i);
	if (s->win->x > 2560)
		s->win->x = 2560;
	if (s->win->y > 1400)
		s->win->y = 1400;
	ft_skip_spaces(line, i);
	if (s->win->x <= 0 || s->win->y <= 0 || line[*i] != '\0')
		return (-2);
	s->fd->count_ind++;
	return (0);
}



void			take_texture_parameters(t_win *win, t_wall *wall, int i, char *filename)
{
	wall[i].img = mlx_xpm_file_to_image(win, filename, &wall[i].width, &wall[i].height);
	wall[i].adr = mlx_get_data_addr(wall[i].img, &wall[i].bits_per_pixel, &wall[i].size_line, &wall[i].endian);
}


int				checking_textures_wall(t_all *s, char *line, int *i, int num)
{
	int			xpm;
	char 		*filename;
	int			j;

	if (s->wall[num].adr != NULL)
		return (-3);
	(*i) += 2;
	ft_skip_spaces(line, i);
	if ((xpm = ft_strnstrindex(line, ".xpm")))
	{
		j = xpm + 1;
		ft_skip_spaces(line, &j);
		if (line[j] != '\0')
			return (-4);
		if (!(filename = ft_substr(line, (*i), xpm - (*i) + 1)))
			return (-5);
		if (open(filename, O_RDONLY) < 0)
			return (-6);
		take_texture_parameters(s->win, s->wall, num, filename);
		return (0);		
	}
	else
		return (-7);
	
	
}


int			checking_sprites(t_all *s)
{
	int		fd;
	int		i;
	char	*file_name_SPRITE = "./textures/SPRITE.xpm";

	i = -1;
	// free(s->sprite);
	if ((fd = open(file_name_SPRITE, O_RDONLY)) < 0)
		return (-1);
	if (!(s->sprite = (t_sprite *)malloc(s->map->item * (sizeof(t_sprite)))))
		return (-1);
	while (++i < s->map->item)
	{
		s->sprite[i].img = mlx_xpm_file_to_image(s->win->mlx, file_name_SPRITE, &s->sprite[i].width, &s->sprite[i].height);
		s->sprite[i].adr = mlx_get_data_addr(s->sprite[i].img, &s->sprite[i].bits_per_pixel, &s->sprite[i].size_line, &s->sprite[i].endian);
	}
	return (1);
}
