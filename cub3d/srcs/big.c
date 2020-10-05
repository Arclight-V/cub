/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:33:52 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/05 18:25:22 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_max_len(t_list **head, t_all *s)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (s->fd->flag == 0)
		{
			s->fd->max_len = tmp->len;
			tmp = tmp->next;
			s->fd->flag = 1;
		}
		else
		{
			s->fd->max_len = (s->fd->max_len > tmp->len) ? s->fd->max_len : tmp->len;
			tmp = tmp->next;
		}
	}
}

t_list		*ft_add_space(t_list **head, t_all *s)
{
	t_list 	*tmp;
	char	*tmp_str;

	tmp = *head;
	ft_max_len(head, s);
	while (tmp)
	{
		if (tmp->len < s->fd->max_len)
		{	
			tmp_str = tmp->content;
			tmp->len = s->fd->max_len - tmp->len;
			if (!(tmp->content = ft_str_add_char(tmp->content, tmp->len, '1')))
				return (NULL);
			ft_free_tmp(tmp_str);
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (*head);
}












void            my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
    char    *dst;

    dst = win->addr + (y * win->line_lenght + x * (win->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	calculating_offsetx_in_texture(t_all *s, t_dataWall *dataWall, t_map *map, char ch)
{
	dataWall->side_of_world[dataWall->index] = ch;
	if (map->flagPDPE == 1 && ch == 'N')
		dataWall->x_image[dataWall->index] = floor(fmod(map->x_horizont, CUBE) * s->cnst->ratio_of_texture_height_to_CUBE_NORD);
	else if (ch == 'W')
		dataWall->x_image[dataWall->index] = floor(fmod(map->y_vertical, CUBE) * s->cnst->ratio_of_texture_height_to_CUBE_WEST);
	else if (ch == 'S')
		dataWall->x_image[dataWall->index] = floor(fmod(map->x_horizont, CUBE) * s->cnst->ratio_of_texture_height_to_CUBE_South);
	else if (ch == 'E')
		dataWall->x_image[dataWall->index] = floor(fmod(map->y_vertical, CUBE) * s->cnst->ratio_of_texture_height_to_CUBE_EAST);
}

void	calculating_wall_length_in_one_slice(t_all *s, t_dataWall *dataWall, t_map *map, t_const *cnst)
{
	dataWall->wall_hFull[dataWall->index] = CUBE / dataWall->distance_wall[dataWall->index] * cnst->DistanceProjectionPlan;
	dataWall->wall_h[dataWall->index] = dataWall->wall_hFull[dataWall->index] > s->win->y ? s->win->y : dataWall->wall_hFull[dataWall->index];
	dataWall->celing_h[dataWall->index] = floor((cnst->CenterProjection - dataWall->wall_h[dataWall->index] / 2));
	if (map->angle_start > 0 && map->angle_start < M_PI)
	{
		if (map->flagPDPE == 1)
			calculating_offsetx_in_texture(s, dataWall, map, 'N');
		else if (map->angle_start < M_PI_2 && map->flagPDPE == 0)
			calculating_offsetx_in_texture(s, dataWall, map, 'E');
		else
			calculating_offsetx_in_texture(s, dataWall, map, 'W');
	}
	else
	{
		if (map->flagPDPE == 1)
			calculating_offsetx_in_texture(s, dataWall, map, 'S');
		else if (map->angle_start > TREE_PI_ON_2 && map->flagPDPE == 0)
			calculating_offsetx_in_texture(s, dataWall, map, 'E');
		else
			calculating_offsetx_in_texture(s, dataWall, map,'W');
	}	
}


	




void		calculation_constant_values(t_all *s)
{
	s->cnst->DistanceProjectionPlan = floor((float)s->win->x / 2) / tan(FOV / 2);
	s->cnst->CenterProjection = floor((float)s->win->y / 2);
	s->cnst->delta_ray = FOV / s->win->x;
	s->cnst->ratio_of_texture_height_to_CUBE_NORD = s->wall[NORD].width / CUBE;
	s->cnst->ratio_of_texture_height_to_CUBE_South = s->wall[SOUTH].width / CUBE;
	s->cnst->ratio_of_texture_height_to_CUBE_WEST = s->wall[WEST].width / CUBE;
	s->cnst->ratio_of_texture_height_to_CUBE_EAST = s->wall[EAST].width / CUBE;
	s->cnst->xMapMax = s->fd->max_len * CUBE - 1;
	s->cnst->yMapMax = s->map->size * CUBE - 1;
}

int	take_texture_parameters_sprite(t_all *s, int item, char *filename)
{
	int i;
	
	i = -1;
	if (!(s->sprite = (t_sprite *)malloc(item * (sizeof(t_sprite)))))
	{
		s->fd->err = -1;
		return (-1);
	}
	while (++i < item)
	{
		s->sprite[i].img = mlx_xpm_file_to_image(s->win->mlx, filename, &s->sprite[i].width, &s->sprite[i].height);
		s->sprite[i].adr = mlx_get_data_addr(s->sprite[i].img, &s->sprite[i].bits_per_pixel, &s->sprite[i].size_line, &s->sprite[i].endian);
	}
	return (0);
}

