/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:59:41 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/29 10:41:27 by anatashi         ###   ########.fr       */
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

int				ft_checking_resolution(t_list **head, char *line, t_all *s, int *i)
{
	if (s->win->x != 0 || s->win->y != 0)
		return(-93);
	(*i)++;
	s->win->x = ft_atoi_mod(line, i);
	s->win->y = ft_atoi_mod(line, i);
	if (s->win->x > 2560)
		s->win->x = 2560;
	if (s->win->y > 1400)
		s->win->y = 1400;
	ft_skip_spaces(line, i);
	if (s->win->x <= 0 || s->win->y <= 0 || line[*i] != '\0')
		return (-94);
	s->fd->count_ind++;
	return (0);
}

// change the following function to a parser


int				ft_checking_textures(t_all *s)
{
	int fd;
	char *filenameNORD = "./textures/WALL_NORD.xpm"; 
	char *filenameSouth = "./textures/WALL_SOUTH.xpm";
	char *filenameWest = "./textures/WALL_WEST.xpm";
	char *filenameEast = "./textures/WALL_EAST.xpm";

	if ((fd = open(filenameNORD, O_RDONLY)) < 0)
		return (-1);
	s->nord->img = mlx_xpm_file_to_image(s->win->mlx, filenameNORD, &s->nord->width, &s->nord->height);
	s->nord->adr = mlx_get_data_addr(s->nord->img, &s->nord->bits_per_pixel, &s->nord->size_line, &s->nord->endian);
	

	if ((fd = open(filenameSouth, O_RDONLY)) < 0)
		return (-1);
	s->south->img = mlx_xpm_file_to_image(s->win->mlx, filenameSouth, &s->south->width, &s->south->height);
	s->south->adr = mlx_get_data_addr(s->south->img, &s->south->bits_per_pixel, &s->south->size_line, &s->south->endian);
	

	if ((fd = open(filenameWest, O_RDONLY)) < 0)
		return (-1);
	s->west->img = mlx_xpm_file_to_image(s->win->mlx, filenameWest, &s->west->width, &s->west->height);
	s->west->adr = mlx_get_data_addr(s->west->img, &s->west->bits_per_pixel, &s->west->size_line, &s->west->endian);
	

	if ((fd = open(filenameEast, O_RDONLY)) < 0)
		return (-1);
	s->east->img = mlx_xpm_file_to_image(s->win->mlx, filenameEast, &s->east->width, &s->east->height);
	s->east->adr = mlx_get_data_addr(s->east->img, &s->east->bits_per_pixel, &s->east->size_line, &s->east->endian);
	
	return (1);

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
