/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_indentifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:59:41 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/03 12:00:57 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
		ft_free_tmp(filename);
		s->fd->count_ind++;
		return (0);
	}
	else
		return (-7);
}


int			checking_textures_sprite(t_all *s, char *line, int *i)
{

	int			xpm;
	int			j;

	if (s->fd->flag_sprite != 0)
		return (-8);
	(*i)++;
	ft_skip_spaces(line, i);
	if ((xpm = ft_strnstrindex(line, ".xpm")))
	{
		j = xpm + 1;
		ft_skip_spaces(line, &j);
		if (line[j] != '\0')
			return (-9);
		if (!(s->fd->filename = ft_substr(line, (*i), xpm - (*i) + 1)))
			return (-10);
		if (open(s->fd->filename, O_RDONLY) < 0)
			return (-11);
		s->fd->flag_sprite = 1;
		s->fd->count_ind++;
		return (0);
	}
	else
		return (-12);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		checking_color(int *color, char *line, int *i, int *count_ind)
{
	int	r;
	int	g;
	int	b;

	if (*color >= 0)
		return (-13);
	(*i)++;
	r = ft_atoi_mod(line, i);
	(*i)++;
	g = ft_atoi_mod(line, i);
	(*i)++;
	b = ft_atoi_mod(line, i);
	ft_skip_spaces(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		return (-14);
	*color = create_trgb(0, r, g, b);
	(*count_ind)++;
	return (0);

}