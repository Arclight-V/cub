/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:08:43 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 19:31:55 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_all 	*initializing_structures(t_all *s, t_list *head)
{

	if (!(s = initializing_structure_of_structures(s)))
		ft_errorstr(s, head, MALLOC_1);
	if (!(s->map = initializing_map_structure()))
		ft_errorstr(s, head, MALLOC_2);
	if (!(s->fd = initializing_fd_structure()))
		ft_errorstr(s, head, MALLOC_3);
	if (!(s->win = initializing_win_structure()))
		ft_errorstr(s, head, MALLOC_4);
	if (!(s->cnst = initializing_const_values_structure()))
		ft_errorstr(s, head, MALLOC_5);
	if (!(s->wall = initializing_wall_structure(s->wall)))
		ft_errorstr(s, head, MALLOC_6);
	if (!(s->data = initializing_slice_parameters_structure()))
		ft_errorstr(s, head, MALLOC_7);
	return (s);
}


void		checking_borders(t_all *s, t_list *head, char **map, int size)
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
					ft_errorstr(s, head, MAP_1);
			}
		}
		if (map[i][0] != '1' && map[0][i] != ' ')
			ft_errorstr(s, head, MAP_1);
		j = -1;
		while (map[i][++j])
			;
		if (map[i][j - 1] != '1' && map[i][j - 1] != ' ')
			ft_errorstr(s, head, MAP_1);
	}
}

static void checking_player(char ch, int *player)
{
	if (ch == 'N' || ch == 'S'||\
		ch == 'E' || ch == 'W')
		(*player)++;
}

void		checking_map(t_all *s, t_list *head, int size, int len)
{
	int i;
	int	j;
	int player;
	char **map;

	map = s->map->map;
	i = 0;
	player = 0;
	checking_borders(s, head, s->map->map, size);
	while (++i < size)
	{
		j = 1;
		while (s->map->map[i][j++] && j < len - 1)
		{
			if (map[i][j] == '0' || map[i][j] == '2' || map[i][j] == 'S' || \
				map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W')
			{	
				checking_player(map[i][j], &player);
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || \
					map[i - 1][j] == ' ' || map[i - 1][j] == ' ')
					ft_errorstr(s, head, MAP_1);
			}
		}
	}
	if ((player == 0) || (player > 1))
		ft_errorstr(s, head, MAP_4);
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
	s = initializing_structures(s, head);
	head = parser_of_scene(s, head, cub);
	make_map(s, head, s->map->size = ft_lstsize(head));
	checking_map(s, head, s->map->size, ft_strlen(head->content));
	make_windows(s->win);
	take_texture_parameters(s, head, s->map->item, s->fd->filename);
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