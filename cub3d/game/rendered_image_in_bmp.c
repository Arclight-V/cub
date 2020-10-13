/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendered_image_in_bmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:17:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/13 10:15:29 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bitmap_file_header	init_bmp_file_header_struct(int file_size)
{
	t_bitmap_file_header bmp_file;

	bmp_file.type[0] = 'B';
	bmp_file.type[1] = 'M';
	bmp_file.syze = file_size;
	bmp_file.rezerved1 = 0;
	bmp_file.rezerved2 = 0;
	bmp_file.off_bits = 0;
	return (bmp_file);
}

static t_bitmap_info_header	init_bmp_info_header_struct(int w, int h, int size)
{
	t_bitmap_info_header bmp_info;

	bmp_info.size = sizeof(bmp_info);
	bmp_info.width = w;
	bmp_info.heigt = -h;
	bmp_info.planes = 1;
	bmp_info.bit_count = 32;
	bmp_info.compression = 0;
	bmp_info.size_image = size;
	bmp_info.x_pels_per_meter = 0;
	bmp_info.y_pels_per_meter = 0;
	bmp_info.clr_used = 0;
	bmp_info.clr_important = 0;
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
	s->data->i = -1;
	raycasting(s, s->data, s->map, s->cnst);
	drawing_screen(s, s->data, s->map);
}

void						rendered_image_in_bmp(char *cub)
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
	render_frame(s);
	save_bmp(s->win->x, s->win->y, s->win->addr);
	game_exit(s, 0);
}
