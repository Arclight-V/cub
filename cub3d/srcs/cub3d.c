/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:08:43 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/05 09:59:01 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_all		*initializing_structures(t_all *s, int *error)
{

	if (!(s = initializing_structure_of_structures(s)))
		*error = -1;
	if (!(s->map = initializing_map_structure()))
		*error = -2;
	if (!(s->fd = initializing_fd_structure()))
		*error = -4;
	if (!(s->win = initializing_win_structure()))
		*error = -5;
	if (!(s->cnst = initializing_const_values_structure()))
		*error = -6;
	if (!(s->wall = initializing_wall_structure(s->wall)))
		*error = -7;
	if (!(s->dataWall = initializing_slice_parameters_structure()))
		*error = -8;
	*error = 0;
	return (s);
}


int		checking_borders(char **map, int size)
{
	int i;
	int j;

	i = -1;
	while (++i <= size)
	{	
		j = -1;
		if (i == 0 || i == size)
		{
			while (map[i][++j])
			{
				if (map[i][j] != '1' || map[i][j] != ' ')
					return (-1);
			}
		}
		while (map[i][++j])
			;
		if (map[i][0] != '1' || map[0][i] != ' ')
			return(-1);
		if (map[i][j - 1] != '1' || map[i][j - 1] != '0')
			return (-1);
	}
	return (1);
}

int 	checking_space(char **m, int size, int i, int j)
{
}

int		checking_map(char **map, int size, int len)
{
	int i;
	int	j;

	i = 0;
	if (checking_borders(map, size) < 0)
		return (-4444444);
	while (++i < size)
	{
		j = 1;
		while (map[i][j++] && j < len - 1)
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || \
					map[i - 1][j] == ' ' || map[i - 1][j] == ' ')
					return (-1);
			}
		}
	}
}

int			creating_array_for_ray(t_all *s)
{
	if (!(s->dataWall->wall_h = ft_calloc((s->win->x), sizeof(double))))
		return (-1);
	if (!(s->dataWall->wall_hFull = ft_calloc((s->win->x), sizeof(double))))
		return (-1);
	if (!(s->dataWall->celing_h = ft_calloc((s->win->x), sizeof(int))))
		return (-1);
	if (!(s->dataWall->y_image = ft_calloc((s->win->x), sizeof(int))))
		return (-1);
	if (!(s->dataWall->side_of_world = ft_calloc((s->win->x), sizeof(char))))
		return (-1);
	if (!(s->dataWall->x_image = ft_calloc((s->win->x), sizeof(int))))
		return (-1);
	if (!(s->dataWall->distance_wall = ft_calloc((s->win->x), sizeof(double))))
		return (-1);
	if (!(s->dataWall->distance_wall_not_corr = ft_calloc((s->win->x), sizeof(double))))
		return (-1);
	if (!(s->dataWall->distan_of_sprites = ft_calloc((s->win->x), sizeof(double))))
		return (-1);
	return (0);
}

int			run_game(char *cub)
{
	t_all 	*s;
	t_list	*head;
	int		error;

	head = NULL;
	if (!(s = initializing_structures(s, &error)))
		return (ft_strerror(error));
	if (!(head = parser_of_scene(cub, s, head)) && s->fd->err < 0)
		return (ft_strerror(s->fd->err));
	if (!(make_map(&head, s->map->size = ft_lstsize(head), s)))
		return (ft_strerror(s->fd->err));
	error = checking_map(s->map->map, s->map->size, ft_strlen(head->content));
	make_windows(s, s->win);
	if ((take_texture_parameters_sprite(s, s->map->item, s->fd->filename) < 0))
		return (ft_strerror(s->fd->err));
	if ((creating_array_for_ray(s)))
		return (ft_strerror(s->fd->err));
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