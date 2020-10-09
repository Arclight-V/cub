/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:28:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 19:35:40 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_exit(t_all *s, int num)
{
	if (s->win)
		freeing_memory_from_win_structure(s->win);
	if (s->head)
		freeing_memory_from_list(s->head);
	if (s->sprite)
		freeing_memory_from_sprite_texture(s->sprite, s->map->item);
	if (s->map)
		freeing_memory_from_map_structure(s->map);
	if (s->fd)
		freeing_memory_from_fd_structure(s->fd);
	if (s->cnst)
		ft_free_tmp(s->cnst);
	if (s->data)
		freeing_memory_from_data_structure(s->data);
	if (s->wall)
		freeing_memory_form_wall_texture(s->wall);
	ft_free_tmp(s);
	// sleep(10000);
	exit(num);
}
