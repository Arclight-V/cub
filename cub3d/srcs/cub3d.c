/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:08:43 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 16:31:32 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_all 	*initializing_structures(t_all *s, t_list *head)
{

	if (!(s = initializing_structure_of_structures(s)))
		ft_strerror(s, head, -1);
	if (!(s->map = initializing_map_structure()))
		ft_strerror(s, head, -2);
	if (!(s->fd = initializing_fd_structure()))
		ft_strerror(s, head, -3);
	if (!(s->win = initializing_win_structure()))
		ft_strerror(s, head, -4);
	if (!(s->cnst = initializing_const_values_structure()))
		ft_strerror(s, head, -5);
	if (!(s->wall = initializing_wall_structure(s->wall)))
		ft_strerror(s, head, -6);
	if (!(s->data = initializing_slice_parameters_structure()))
		ft_strerror(s, head, -7);
	return (s);
}


int		checking_borders(char **map, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{	
		j = -1;
		if (i == 0 || i == size)
		{
			while (map[i][++j])
			{
				if (map[i][j] != '1' && map[i][j] != ' ')
					return (-1);
			}
		}
		if (map[i][0] != '1' && map[0][i] != ' ')
			return(-1);
		j = -1;
		while (map[i][++j])
			;
		if (map[i][j - 1] != '1' && map[i][j - 1] != '0')
			return (-1);
	}
	return (1);
}

static void checking_player(char ch, int *player)
{
	if (ch == 'N' || ch == 'S'||\
		ch == 'E' || ch == 'W')
		(*player)++;
}

void		checking_map(char **map, int size, int len, int *error)
{
	int i;
	int	j;
	int player;

	i = 0;
	player = 0;
	if (checking_borders(map, size) < 0)
		*error = -24;
	while (++i < size)
	{
		j = 1;
		while (map[i][j++] && j < len - 1)
		{
			if (map[i][j] == '0' || map[i][j] == '2' || map[i][j] == 'S' || \
				map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W')
			{	
				checking_player(map[i][j], &player);
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || \
					map[i - 1][j] == ' ' || map[i - 1][j] == ' ')
					*error = -24;
			}
		}
	}
	if ((player == 0) || (player > 1))
		*error = -29;
}

int			creating_array_for_ray(t_all *s)
{
	if (!(s->data->wall_h = ft_calloc((s->win->x), sizeof(double))))
		return (-1);
	if (!(s->data->wall_hFull = ft_calloc((s->win->x), sizeof(double))))
		return (-1);
	if (!(s->data->celing_h = ft_calloc((s->win->x), sizeof(int))))
		return (-1);
	if (!(s->data->y_image = ft_calloc((s->win->x), sizeof(int))))
		return (-1);
	if (!(s->data->side_of_world = ft_calloc((s->win->x), sizeof(char))))
		return (-1);
	if (!(s->data->x_image = ft_calloc((s->win->x), sizeof(int))))
		return (-1);
	if (!(s->data->distance_wall = ft_calloc((s->win->x), sizeof(double))))
		return (-1);
	if (!(s->data->distance_wall_not_corr = ft_calloc((s->win->x), sizeof(double))))
		return (-1);
	if (!(s->data->distan_of_sprites = ft_calloc((s->win->x), sizeof(double))))
		return (-1);
	return (0);
}

int			run_game(char *cub)
{
	t_all 	*s;
	t_list	*head;
	int		error;

	error = 0;
	head = NULL;
	// if (!(s = initializing_structures(s, &error)))
	// 	return (ft_strerror(s, head, error));
	s = initializing_structures(s, head);

	if (!(head = parser_of_scene(cub, s, head)) && s->fd->err < 0)
		return (ft_strerror(s, head, s->fd->err));
	if (!(make_map(&head, s->map->size = ft_lstsize(head), s)))
		return (ft_strerror(s, head, s->fd->err));
	checking_map(s->map->map, s->map->size, ft_strlen(head->content), &error);
	// if (error < 0)
	// 	return (ft_strerror(s, head, error));
	error < 0 ? ft_strerror(s, head, error) : 0;
	make_windows(s->win);
	if ((take_texture_parameters(s, s->map->item, s->fd->filename) < 0))
		return (ft_strerror(s, head, s->fd->err));
	if ((creating_array_for_ray(s)))
		return (ft_strerror(s, head, s->fd->err));
	search_player_and_sprites(s->map, s->sprite, 0, 0);
	calculation_constant_values(s);
	if ((loop_hook(s, s->win->mlx, s->win->win)) < 0)
		return (ft_strerror(s, head, -1));
}




int		main (int argc, char **argv)
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