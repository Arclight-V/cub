/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendered_image_in_bmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:17:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/17 17:40:00 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int			my_get_color(t_win *win, int x, int y)
{
	char	*dst;

	dst = win->addr + (y * win->line_lenght + x * (win->bps / 8));
	return (*(unsigned int*)dst);
}

static	void		init_header(t_all *s, unsigned char *header_bmp,
								int file_size, int width)
{
	header_bmp[0] = (unsigned char)'B';
	header_bmp[1] = (unsigned char)'M';
	header_bmp[2] = (unsigned char)file_size;
	header_bmp[3] = (unsigned char)(file_size >> 8);
	header_bmp[4] = (unsigned char)(file_size >> 16);
	header_bmp[5] = (unsigned char)(file_size >> 24);
	header_bmp[10] = (unsigned char)54;
	header_bmp[14] = (unsigned char)40;
	header_bmp[18] = (unsigned char)width;
	header_bmp[19] = (unsigned char)(width >> 8);
	header_bmp[20] = (unsigned char)(width >> 16);
	header_bmp[21] = (unsigned char)(width >> 24);
	header_bmp[22] = (unsigned char)s->win->y;
	header_bmp[23] = (unsigned char)(s->win->y >> 8);
	header_bmp[24] = (unsigned char)(s->win->y >> 16);
	header_bmp[25] = (unsigned char)(s->win->y >> 24);
	header_bmp[26] = (unsigned char)1;
	header_bmp[28] = (unsigned char)24;
}

static void			get_screenshot(t_all *s, int fd, int res)
{
	int color;
	int x;
	int y;
	int size_x;

	color = 0;
	x = 0;
	y = s->win->y - 1;
	size_x = res;
	while (y >= 0)
	{
		while (x < size_x)
		{
			color = my_get_color(s->win, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
		x = 0;
	}
}

static void			save_bmp(t_all *s, int width, int height)
{
	int				fd;
	int				file_size;
	int				count;
	unsigned char	header_bmp[54];

	count = 0;
	if (width % 4)
		width -= width % 4;
	file_size = width * height + 54;
	fd = open("Cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	while (count < 54)
	{
		header_bmp[count] = (unsigned char)0;
		count++;
	}
	init_header(s, header_bmp, file_size, width);
	write(fd, header_bmp, 54);
	get_screenshot(s, fd, width);
	close(fd);
}

void				rendered_image_in_bmp(char *cub)
{
	t_all	*s;

	s = NULL;
	s = initializing_structures(s);
	s->head = parser_of_scene(s, s->head, cub);
	s->head = ft_add_space(s, s->head);
	make_map(s, s->map->size = ft_lstsize(s->head));
	checking_map(s, s->map->size);
	s->win->mlx = mlx_init();
	s->win->img = mlx_new_image(s->win->mlx, s->win->x, s->win->y);
	s->win->addr = mlx_get_data_addr(s->win->img, &s->win->bps,
					&s->win->line_lenght, &s->win->endian);
	take_texture_parameters(s, s->map->item);
	creating_array_for_ray(s);
	search_player_and_sprites(s->map, s->sprite, 0, 0);
	calculation_constant_values(s);
	s->data->i = -1;
	raycasting(s, s->data, s->map, s->cnst);
	drawing_screen(s, s->data, s->map);
	save_bmp(s, s->win->x, s->win->y);
	game_exit(s, 0);
}
