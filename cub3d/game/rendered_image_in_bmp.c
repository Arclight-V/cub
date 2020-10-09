/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendered_image_in_bmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:17:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 13:35:09 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bitmap_file_header	init_bmp_file_header_struct(int file_size)
{
	t_bitmap_file_header bmp_file;

	bmp_file.bfType[0] = 'B';
	bmp_file.bfType[1] = 'M';
	bmp_file.bfSyze = file_size;
	bmp_file.bfRezerved1 = 0;
	bmp_file.bfRezerved2 = 0;
	bmp_file.bfOffBits = 0;
	return (bmp_file);
}

static t_bitmap_info_header	init_bmp_info_header_struct(int w, int h, int size)
{
	t_bitmap_info_header bmp_info;

	bmp_info.biSize = sizeof(bmp_info);
	bmp_info.biWidth = w;
	bmp_info.biHeigt = -h + 1;
	bmp_info.biPlanes = 1;
	bmp_info.biBitCount = 32;
	bmp_info.biCompression = 0;
	bmp_info.biSizeImage = size;
	bmp_info.biXPelsPerMeter = 0;
	bmp_info.biYPelsPerMeter = 0;
	bmp_info.biClrUsed = 0;
	bmp_info.biClrImportant = 0;
	return (bmp_info);
}

static void					save_bmp(int width, int height, char *addr)
{
	int8_t					fd;
	t_bitmap_file_header	bmp_file;
	t_bitmap_info_header	bmp_info;
	int						image_size;
	int						file_size;

	image_size = height * width;
	file_size = image_size;
	bmp_file = init_bmp_file_header_struct(file_size);
	bmp_info = init_bmp_info_header_struct(width, height, file_size);
	fd = open("Cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write(fd, &bmp_file, 14);
	write(fd, &bmp_info, sizeof(bmp_info));
	write(fd, addr, image_size * 4);
	close(fd);
}

static void					render_frame(t_all *s)
{
	s->data->index = -1;
	raycasting(s, s->data, s->map, s->cnst);
	if ((drawing_screen(s, s->data, s->map, s->cnst)) < 0)
		ft_error_output(s, MALLOC_22);
}

void						rendered_image_in_bmp(char *cub)
{
	t_all	*s;

	s = initializing_structures(s);
	s->head = parser_of_scene(s, s->head, cub);
	s->head = ft_add_space(s, s->head);
	make_map(s, s->map->size = ft_lstsize(s->head));
	checking_map(s, s->map->size, ft_strlen(s->head->content));
	make_windows(s->win);
	take_texture_parameters(s, s->wall, s->map->item);
	creating_array_for_ray(s);
	search_player_and_sprites(s->map, s->sprite, 0, 0);
	calculation_constant_values(s);
	render_frame(s);
	save_bmp(s->win->x, s->win->y, s->win->addr);
	game_exit(s, 0);
}
