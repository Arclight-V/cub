/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:28:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/06 16:40:57 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void 	freeing_memory_from_map_structure(t_map *map)
{
	int	i;

	i = -1;
	// while (map->map[++i])
		// ft_free_tmp(map->map[i]);
	free(map->map);
	free(map);
	map = NULL;
}
static void freeing_memory_from_list(t_list *head)
{
	t_list *tmp;

	// tmp = head;
	// while (tmp->next)
	// {

	// 	ft_free_tmp(tmp->content);
	// 	tmp = tmp->next;
	// }
	ft_lstclear(&head,ft_lstdelone_f);
	ft_free_tmp(head);
}

static void freeing_memory_from_fd_structure(t_fd *fd)
{
	ft_free_tmp(fd->filename);
	free(fd);
	fd = NULL;
}

static void freeing_memory_from_win_structure(t_win *win)
{
	ft_free_tmp(win->addr);
	mlx_destroy_window(win->mlx, win->win);
	// mlx_destroy_image(win->mlx, win->img);
	ft_free_tmp(win->mlx);
	// ft_free_tmp(win->win);
	ft_free_tmp(win->img);
	ft_free_tmp(win);
}

static void freeing_memory_from_data_structure(t_data *data)
{
	if (data->wall_h)
		ft_free_tmp(data->wall_h);
	if (data->wall_hFull)
		ft_free_tmp(data->wall_hFull);
	if (data->celing_h)
		ft_free_tmp(data->celing_h);
	if (data->y_image)
		ft_free_tmp(data->y_image);
	if (data->side_of_world)
		ft_free_tmp(data->side_of_world);
	if (data->x_image)
		ft_free_tmp(data->x_image);
	if (data->distance_wall)
		ft_free_tmp(data->distance_wall);
	if (data->distance_wall_not_corr)
		ft_free_tmp(data->distance_wall_not_corr);
	if (data->distan_of_sprites)
		ft_free_tmp(data->distan_of_sprites);
	ft_free_tmp(data);
}

static void freeing_memory_from_sprite_texture(t_sprite *sprite, int i)
{
	while (i-- > 0)
	{
		ft_free_tmp(sprite[i].adr);
		ft_free_tmp(sprite[i].img);
	}
	ft_free_tmp(sprite);
}

static void freeing_memory_form_wall_texture(t_wall *wall)
{
	int i;

	i = 4;
	while (--i >= 0)
	{
		ft_free_tmp(wall[i].adr);
		ft_free_tmp(wall[i].img);
	}
	ft_free_tmp(wall);
}

int	game_exit(int num, t_all *s, t_list *head)
{
	if (head)
		freeing_memory_from_list(head);
	if (s->sprite)
		freeing_memory_from_sprite_texture(s->sprite, s->map->item);
	if (s->map)
		freeing_memory_from_map_structure(s->map);
	if (s->fd)
		freeing_memory_from_fd_structure(s->fd);
	if (s->win)
		freeing_memory_from_win_structure(s->win);
	if (s->cnst)
		ft_free_tmp(s->cnst);
	if (s->data)
		freeing_memory_from_data_structure(s->data);
	if (s->wall)
		freeing_memory_form_wall_texture(s->wall);
	ft_free_tmp(s);
	sleep(1000);
	exit(num);
}
