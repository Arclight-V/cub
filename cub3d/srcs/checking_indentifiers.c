/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_indentifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:59:41 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/08 13:07:45 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	checking_resolution(t_all *s, t_list *head, char *line, int *i)
{
	if (s->win->x != 0 || s->win->y != 0)
		ft_errorstr(s, RESOLUTION_1);
	(*i)++;
	s->win->x = ft_atoi_mod(line, i);
	s->win->y = ft_atoi_mod(line, i);
	if (s->win->x > 2560)
		s->win->x = 2560;
	if (s->win->y > 1400)
		s->win->y = 1400;
	ft_skip_spaces(line, i);
	if (s->win->x <= 0 || s->win->y <= 0 || line[*i] != '\0')
		ft_errorstr(s, RESOLUTION_2);
	s->fd->count_ind++;
}

void	checking_textures_wall(t_all *s, t_list *head, char *line, int num)
{
	int			xpm;
	int			j;
	int			i;

	i = 2;
	if (s->wall[num].filename)
		ft_errorstr(s, TEXTURE_1);
	ft_skip_spaces(line, &i);
	if ((xpm = ft_strnstrindex(line, ".xpm")))
	{
		j = xpm + 1;
		ft_skip_spaces(line, &j);
		if (line[j] != '\0')
			ft_errorstr(s, TEXTURE_2);
		if (!(s->wall[num].filename = ft_substr(line, i, xpm - i + 1)))
			ft_errorstr(s, MALLOC_8);
		if (open(s->wall[num].filename, O_RDONLY) < 0)
			ft_errorstr(s, FD_3);
		s->fd->count_ind++;
	}
	else
		ft_errorstr(s, TEXTURE_3);
}


void			checking_textures_sprite(t_all *s, t_list *head, char *line, int *i)
{
	int			xpm;
	int			j;

	if (s->fd->flag_sprite != 0)
		ft_errorstr(s, TEXTURE_4);
	(*i)++;
	ft_skip_spaces(line, i);
	if ((xpm = ft_strnstrindex(line, ".xpm")))
	{
		j = xpm + 1;
		ft_skip_spaces(line, &j);
		if (line[j] != '\0')
			ft_errorstr(s, TEXTURE_5);
		if (!(s->fd->filename = ft_substr(line, (*i), xpm - (*i) + 1)))
			ft_errorstr(s, MALLOC_9);
		if (open(s->fd->filename, O_RDONLY) < 0)
			ft_errorstr(s, FD_4);
		s->fd->flag_sprite = 1;
		s->fd->count_ind++;
	}
	else
		ft_errorstr(s, TEXTURE_6);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	checking_color(t_all *s, t_list *head, char *line, int *color)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 1;
	if (*color >= 0)
		ft_errorstr(s, FLOOR_1);
	r = ft_atoi_mod(line, &i);
	if (ft_skip_spaces(line, &i) && line[i] != ',')
		ft_errorstr(s, FLOOR_2);
	i++;
	g = ft_atoi_mod(line, &i);
	if (ft_skip_spaces(line, &i) && line[i] != ',')
		ft_errorstr(s, FLOOR_2);
	i++;
	b = ft_atoi_mod(line, &i);
	ft_skip_spaces(line, &i);
	if (line[i] != '\0' || r > 255 || g > 255 || b > 255)
		ft_errorstr(s, FLOOR_2);
	*color = create_trgb(0, r, g, b);
	s->fd->count_ind++;
}