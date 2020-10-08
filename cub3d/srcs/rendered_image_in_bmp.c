/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendered_image_in_bmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:17:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 20:24:22 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static t_bitmap_file_header initializing_bmp_file_header_structure(int file_size)
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

static t_bitmap_info_header initializing_bmp_info_header_structure(int width, int height, int file_size)
{
	t_bitmap_info_header bmp_info;

	bmp_info.biSize = sizeof(bmp_info);
	bmp_info.biWidth = width;
	bmp_info.biHeigt = -height;
	bmp_info.biPlanes = 1;
	bmp_info.biBitCount = 32;
	bmp_info.biCompression = 0;
	bmp_info.biSizeImage = file_size;
	bmp_info.biXPelsPerMeter = 0;
	bmp_info.biYPelsPerMeter = 0;
	bmp_info.biClrUsed = 0;
	bmp_info.biClrImportant = 1078;
	return (bmp_info);
}

static void	save_bmp(int width, int height, char *addr)
{
	int8_t						fd;
	t_bitmap_file_header	bmp_file;
	t_bitmap_info_header	bmp_info;
	int						image_size;
	int						file_size;

	image_size	= height * width;
	file_size = 54 + 4 * image_size;
	bmp_file = initializing_bmp_file_header_structure(file_size);
	bmp_info = initializing_bmp_info_header_structure(width, height, file_size);
	fd = open("Cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write(fd, &bmp_file, 14);
	write(fd, &bmp_info, sizeof(bmp_info));
	write(fd, addr, image_size * 4);
	close(fd);
}

static void	render_frame(t_all *s, t_list *head)
{

	s->data->index = -1;
	raycasting(s, s->data, s->map, s->cnst);
	if ((drawing_screen(s, s->data, s->map, s->cnst)) < 0)
		ft_errorstr(s, head, MALLOC_22);
}

void rendered_image_in_bmp(char *cub)
{
	t_all 	*s;
	t_list	*head;
	int		error;

	error = 0;
	head = NULL;
	s = initializing_structures(s, head);
	head = parser_of_scene(s, head, cub);
	make_map(s, head, s->map->size = ft_lstsize(head));
	checking_map(s, head, s->map->size, ft_strlen(head->content));
	make_windows(s->win);
	take_texture_parameters(s, head, s->map->item, s->fd->filename);
	creating_array_for_ray(s, head);
	search_player_and_sprites(s->map, s->sprite, 0, 0);
	calculation_constant_values(s);
	render_frame(s, head);
	save_bmp(s->win->x, s->win->y, s->win->addr);
	game_exit(s, head, 0);
}