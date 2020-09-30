/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:08:43 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/30 19:32:51 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_all		*initializing_structures(t_all *s)
{

	if (!(s = initializing_structure_of_structures(s)))
		return (ft_errorstr(MALLOC_1, 0));
	if (!(s->map = initializing_map_structure()))
		return (ft_errorstr(MALLOC_2, 0));
	if (!(s->err = initializing_err_structure()))
		return( ft_errorstr(MALLOC_3, 0));
	if (!(s->fd = initializing_fd_structure()))
		return (ft_errorstr(MALLOC_4, 0));
	if (!(s->win = initializing_win_structure()))
		return (ft_errorstr(MALLOC_5, 0));
	if (!(s->ConstValue = initializing_const_values_structure()))
		return (ft_errorstr(MALLOC_6, 0));
	if (!(s->wall = initializing_wall_structure(s->wall)))
		return(ft_errorstr(MALLOC_7, 0));
	if (!(s->dataWall = initializing_slice_parameters_structure()))
		return(ft_errorstr(MALLOC_11, 0));	
	return (s);
}


int			run_game(char *cub)
{
	t_all 	*s;
	t_list	*head;

	// head = NULL;
	s = initializing_structures(s);
	head = parser_of_scene(cub, s, head);
	make_map(&head, s->map->size = ft_lstsize(head), s);
	make_windows(s, s->win);
	take_texture_parameters_sprite(s, s->map->item, s->fd->filename);
	search_player_and_sprites(s);
	calculation_constant_values(s);
	loop_hook(s, s->win->mlx, s->win->win);
}

int		main (int argc, char **argv)
{
	if (argc == 2)
		run_game(argv[1]);
	else
		ft_putendl_fd("Error : Invalid arguments", 2);
	return (0);
	
}