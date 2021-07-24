/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:08:43 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/17 19:05:58 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	run_game(char *cub)
{
	t_all	*s;

	s = NULL;
	s = initializing_structures(s);
	s->head = parser_of_scene(s, s->head, cub);
	s->head = ft_add_space(s, s->head);
	make_map(s, s->map->size = ft_lstsize(s->head));
	checking_map(s, s->map->size);
	make_windows(s->win);
	take_texture_parameters(s, s->map->item);
	creating_array_for_ray(s);
	search_player_and_sprites(s->map, s->sprite, 0, 0);
	calculation_constant_values(s);
	loop_hook(s, s->win->mlx, s->win->win);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(ft_strnstrindex(argv[1], ".cub")))
		{
			ft_putendl_fd("Error : map format needs to be.'cub'", 2);
			return (0);
		}
		run_game(argv[1]);
	}
	else if (argc == 3)
	{
		if (ft_strnstrindex(argv[2], "--save"))
			rendered_image_in_bmp(argv[1]);
		ft_putendl_fd("Error : only the --save option is available", 2);
	}
	else
		ft_putendl_fd("Error : Invalid arguments", 2);
	return (0);
}
