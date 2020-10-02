/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:33:52 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/02 14:14:25 by anatashi         ###   ########.fr       */
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

// /*
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
// */







int				checking_validity_map(t_list *head, char *line, t_all *s)
{
	int			i;

	i = 0;
	ft_skip_spaces(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ')
		return (s->err->num = checking_resolution(s, line, &i));
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (s->err->num = checking_textures_wall(s, line, &i, NORD));
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (s->err->num = checking_textures_wall(s, line, &i, SOUTH));
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		return (s->err->num = checking_textures_wall(s, line, &i, WEST));
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		return (s->err->num = checking_textures_wall(s, line, &i, EAST));
	else if (line[i] == 'S' && line[i + 1] == ' ')
		return (s->err->num = checking_textures_sprite(s, line, &i));
	else if (line[i] == 'F')
		return (s->err->num = checking_color(&s->map->floor, line, &i));
	else if (line[i] == 'C')
		return (s->err->num = checking_color(&s->map->ceil, line, &i));	
	else if (line[i] == '1')
		if (s->err->num = ft_forb_char_map(&head, line, s, &i));
	else if (ft_skip_spaces(line, &i) && line[i] != '\0')
		return (-92);
	return (1);
}

t_list			*ft_creat_list(t_list *head, t_all *s, char *line)
{
	t_list	*new;

	new = NULL;
	if ((s->err->num = checking_validity_map(head, line, s)) < 0)
		return (NULL);
	if (s->fd->count_ind == 1)
	{
		if (!(new = ft_lstnew(line)))
		{	
			ft_lstclear(&head,lstdelone_f);
			s->err->num = -15;
			return (NULL);
		}
		ft_lstadd_back(&head, new);
	}
	return (head);
}

void            my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
    char    *dst;

    dst = win->addr + (y * win->line_lenght + x * (win->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void			ft_search_view(t_all *s, int ch)
{
	s->map->x_p = s->map->x;
	s->map->y_p = s->map->y;
	if (ch == 'N')
		s->map->a_p = M_PI_2;
	else if (ch == 'S')
		s->map->a_p = s->ConstValue->tree_pi_by_two;
	else if (ch == 'E')
		s->map->a_p = M_PI;
	else if (ch == 'W')
		s->map->a_p = s->ConstValue->two_pi;
	
}

void		record_coordinates_of_sprite(t_all *s, int count_sprites)
{
	s->sprite[count_sprites].x = s->map->x + 32;
	s->sprite[count_sprites].y = s->map->y + 32;
	s->map->x += CUBE_SIZE;
	s->map->y += CUBE_SIZE;
}

int			search_player_and_sprites(t_all *s)
{
	int k;
	int i;
	int j;
	int	count_sprites;

	count_sprites = -1;
	i = -1;
	k = CUBE_SIZE;
	while (++i < s->map->size)
	{
		j = -1;
		while (s->map->level[i][++j])
		{
				s->map->y = i * CUBE_SIZE + 1;
				s->map->x = j * CUBE_SIZE;
				k = s->map->x + CUBE_SIZE;
				while (s->map->y++ < ( (i + 1) * CUBE_SIZE))
				{
					while (s->map->x++ < k - 1)
						if (s->map->level[i][j] == 'N' || s->map->level[i][j] == 'S'
							|| s->map->level[i][j] == 'E' || s->map->level[i][j] == 'W')
							ft_search_view(s, s->map->level[i][j]);
						else if (s->map->level[i][j] == '2')
							record_coordinates_of_sprite(s, ++count_sprites);
					s->map->x = j * CUBE_SIZE;
				}
		}
	}
	s->map->x_pp = s->map->x_p - 32;
	s->map->y_pp = s->map->y_p - 32;

}





int		draw_square(t_all *s, int x, int y)
{
	int i = x - 2;
	int	j = y - 2;
	while (i != x + 2)
	{
		j = y - 2;
		while(j != y + 2)
		{
			my_mlx_pixel_put(s->win, i, j, 0x1456e3);
			j++;
		}
		i++;
	}
}



int			get_color_pixel(t_all *s, char *adr, int size_line, int bits_per_pixel)
{
	char	*color;

	color = adr + (s->dataWall->yCoordinateInTexture[s->dataWall->index] * size_line + s->dataWall->OfsetX[s->dataWall->index] * (bits_per_pixel / 8));
	return (*(unsigned int*)color);
}

void		printSliceWall(t_all *s, char *addr, int size_line, int bits_per_pixel)
{
	int				colour_pixel;
	// int				count;


	colour_pixel = get_color_pixel(s, addr, size_line, bits_per_pixel);
	// count = -1;
	// if (s->map->yyy < s->dataWall->ProjectedSliceHeight[s->dataWall->index])
	{	
			my_mlx_pixel_put(s->win, s->dataWall->index, s->map->i++, colour_pixel);
			s->map->yyy++;
	}
	s->dataWall->yCoordinateInTexture[s->dataWall->index]++;
}

double	calc_y(t_all *s)
{
	return (floor(s->map->yyy + (s->dataWall->ProjectedSliceHeightNotCorr[s->dataWall->index] - s->dataWall->ProjectedSliceHeight[s->dataWall->index]) / 2));
}

void		search_y_texture(t_all *s, double y_slice, int h_texture, double sliceWnot)
{
	s->dataWall->yCoordinateInTexture[s->dataWall->index] = floor(y_slice * (h_texture ) / (sliceWnot));
}

double		calculating_sprite_direction(double TWO_M_PI, double x_player, double y_player, int x_sprite, int y_sprite)
{
	double	sprite_direction;

	sprite_direction = atan2(y_player - y_sprite, x_sprite - x_player);

	sprite_direction = sprite_direction >= 0 ? sprite_direction : TWO_M_PI + sprite_direction;
	return (sprite_direction);
}

double		calculating_delta(double TWO_M_PI, double fov_start, double sprite_dir)
{
	double 	delta;

	delta = fov_start - sprite_dir;
	if (delta <= -M_PI)
		delta += TWO_M_PI;
	else if (delta >= M_PI)
		delta -= TWO_M_PI;
	return (delta);
}

void		calculation_of_parameters_of_sprites(t_all *s, t_dataWall *dataWall)
{
	int		i;
	double	delta;

	i = -1;
	while (++i < s->map->item)
	{
		s->sprite[i].sprite_angle = calculating_sprite_direction(s->ConstValue->two_pi,s->map->x_pp, s->map->y_pp, s->sprite[i].x, s->sprite[i].y);
		s->sprite[i].distance = sqrt(pow(s->map->x_pp - s->sprite[i].x, 2) + pow(s->map->y_pp - s->sprite[i].y, 2));
		s->sprite[i].sprite_screen_size_full = (CUBE_SIZE / (s->sprite[i].distance  * cos(s->map->a_p - s->sprite[i].sprite_angle))) * s->ConstValue->DistanceProjectionPlan;
		s->sprite[i].sprite_screen_size_coor = s->sprite[i].sprite_screen_size_full > s->win->y ? s->win->y : s->sprite[i].sprite_screen_size_full;
		s->sprite[i].sprite_width = CUBE_SIZE / s->sprite[i].distance * s->ConstValue->DistanceProjectionPlan;
		s->sprite[i].sprite_screen_size_half = s->sprite[i].sprite_screen_size_coor / 2;
		delta = calculating_delta(s->ConstValue->two_pi, s->map->a_p + s->ConstValue->thiry_degrees, s->sprite[i].sprite_angle);
		s->sprite[i].h_offset =  delta / ( FOV / s->win->x) - s->sprite[i].sprite_screen_size_half;
		s->sprite[i].position_sprite = ((s->ConstValue->CenterProjection - s->sprite[i].sprite_screen_size_half));
	}

}


void	drawing_floor(t_all *s)
{

	while (s->map->i < s->win->y - 1)
		my_mlx_pixel_put(s->win, s->dataWall->index, s->map->i++, s->map->floor);
}

void	drawing_celing(t_all *s)
{
	s->map->yyy = -1;
	while (++s->map->yyy < s->dataWall->PositionWall[s->dataWall->index])
		my_mlx_pixel_put(s->win, s->dataWall->index, s->map->yyy, s->map->ceil);
}

int		get_color_pixel_sprite(t_sprite *sprite, int ofset_x, int i, int y)
{
	char	*color;

	color = sprite[i].adr + ( y * sprite[i].size_line + ofset_x * (sprite[i].bits_per_pixel / 8));
	return (*(unsigned int*)color);

}

int		print_pixel_of_sprite(t_all *s, int j, int i)
{
	int 	color_pixel;
	int		count;
	int		offset_x;
	int		corr_size_sprite;
	double 	y_sprite;

	offset_x = floor((double)j * ((double)s->sprite[i].width / s->sprite[i].sprite_width)); 
	y_sprite = floor(s->map->yyy + ((s->sprite[i].sprite_screen_size_full -  s->sprite[i].sprite_screen_size_coor) / 2));

	color_pixel = get_color_pixel_sprite(s->sprite, offset_x, i, floor(y_sprite * (s->sprite[i].height) / (s->sprite[i].sprite_screen_size_full)));
	if (color_pixel <= 0)
		return (s->map->i + 1);
	my_mlx_pixel_put(s->win, s->dataWall->index, s->map->i, color_pixel);
	return (s->map->i + 1);

}


void	drawing_sprites(t_all *s)
{
	int		i;
	int		j;
	int		*array_of_sequence_numbers_of_sprites;

	i = -1;
	int k;
	calculation_of_parameters_of_sprites(s, s->dataWall);

	array_of_sequence_numbers_of_sprites = ft_calloc(s->map->item, sizeof(int));
	array_of_sequence_numbers_of_sprites = sorting_of_distances_of_sprites(s, array_of_sequence_numbers_of_sprites);

	while (++i < s->map->item)
	{
		j = -1;
		k = array_of_sequence_numbers_of_sprites[i];
		while (++j < s->sprite[k].sprite_width)
		{
			if ((s->sprite[k].h_offset + j ) == s->dataWall->index)
			{
				s->map->i = s->sprite[k].position_sprite;
				if (s->sprite[k].distance < s->dataWall->distance_wall_not_corr[s->dataWall->index])
				{	
					s->map->yyy = -1;
					while (++s->map->yyy < s->sprite[k].sprite_screen_size_coor)
					{
						s->map->i = print_pixel_of_sprite(s, j, k);
					}
				}
			}
		}
		

	}
	
}

void	drawing_walls(t_all *s, t_dataWall *dataWall)
{
	s->map->yyy = 0;
	while (s->map->yyy < dataWall->ProjectedSliceHeight[dataWall->index])
	{
		if (dataWall->CardinalDirections[dataWall->index] == 'N')
		{
			search_y_texture(s, calc_y(s), s->wall[NORD].height, dataWall->ProjectedSliceHeightNotCorr[dataWall->index]);
			printSliceWall(s, s->wall[NORD].adr, s->wall[NORD].size_line, s->wall[NORD].bits_per_pixel);
		}
		else if (dataWall->CardinalDirections[dataWall->index] == 'E')
		{
			search_y_texture(s, calc_y(s), s->wall[EAST].height, dataWall->ProjectedSliceHeightNotCorr[dataWall->index]);
			printSliceWall(s, s->wall[EAST].adr, s->wall[EAST].size_line, s->wall[EAST].bits_per_pixel);
		}
		else if (dataWall->CardinalDirections[dataWall->index] == 'W')
		{
			search_y_texture(s, calc_y(s), s->wall[WEST].height, dataWall->ProjectedSliceHeightNotCorr[dataWall->index]);
			printSliceWall(s, s->wall[WEST].adr, s->wall[WEST].size_line, s->wall[WEST].bits_per_pixel);		
		}
		else if (dataWall->CardinalDirections[dataWall->index] == 'S')
		{
			search_y_texture(s, calc_y(s), s->wall[SOUTH].height, dataWall->ProjectedSliceHeightNotCorr[dataWall->index]);
			printSliceWall(s, s->wall[SOUTH].adr, s->wall[SOUTH].size_line, s->wall[SOUTH].bits_per_pixel);
		}		
	}
}





void	specifyDirectionWallAndCalculateOffset(t_all *s, char ch, int width, double height)
{
	s->dataWall->CardinalDirections[s->dataWall->index] = ch;
	s->dataWall->scalingIndex[s->dataWall->index] = ceil(s->dataWall->ProjectedSliceHeightNotCorr[s->dataWall->index] / height); 
	if (s->map->flagPDPE == 1 && ch == 'N')
	{
		s->dataWall->OfsetX[s->dataWall->index] = floor(fmod(s->map->x_horizont, CUBE_SIZE) * s->ConstValue->ratio_of_texture_height_to_CUBE_SIZE_NORD);
	}
	else if (ch == 'W')
	{
		s->dataWall->OfsetX[s->dataWall->index] = floor(fmod(s->map->y_vertical, CUBE_SIZE) * s->ConstValue->ratio_of_texture_height_to_CUBE_SIZE_WEST);
	}
	else if (ch == 'S')
	{
		s->dataWall->OfsetX[s->dataWall->index] = floor(fmod(s->map->x_horizont, CUBE_SIZE) * s->ConstValue->ratio_of_texture_height_to_CUBE_SIZE_South);
	}
	else if (ch == 'E')
	{
		s->dataWall->OfsetX[s->dataWall->index] = floor(fmod(s->map->y_vertical, CUBE_SIZE) * s->ConstValue->ratio_of_texture_height_to_CUBE_SIZE_EAST);
	}
}

void	calculating_wall_length_in_one_slice(t_all *s, t_dataWall *dataWall)
{
	s->dataWall->ProjectedSliceHeightNotCorr[dataWall->index] = CUBE_SIZE / s->dataWall->distance_wall[s->dataWall->index] * s->ConstValue->DistanceProjectionPlan;
	dataWall->ProjectedSliceHeight[dataWall->index] = s->dataWall->ProjectedSliceHeightNotCorr[dataWall->index] > s->win->y ? s->win->y : s->dataWall->ProjectedSliceHeightNotCorr[dataWall->index];
	dataWall->PositionWall[dataWall->index] = floor((s->ConstValue->CenterProjection - dataWall->ProjectedSliceHeight[dataWall->index] / 2));
	if (s->map->angle_start > 0 && s->map->angle_start < M_PI)
	{
		if (s->map->flagPDPE == 1)
			specifyDirectionWallAndCalculateOffset(s, 'N', s->wall[NORD].width, s->wall[NORD].height);
		else if (s->map->angle_start < M_PI_2 && s->map->flagPDPE == 0)
			specifyDirectionWallAndCalculateOffset(s, 'E', s->wall[EAST].width, s->wall[EAST].height);	
		else
			specifyDirectionWallAndCalculateOffset(s, 'W', s->wall[WEST].width, s->wall[WEST].height);
	}
	else
	{
		if (s->map->flagPDPE == 1)
			specifyDirectionWallAndCalculateOffset(s, 'S', s->wall[SOUTH].width, s->wall[SOUTH].height);
		else if (s->map->angle_start >  s->ConstValue->tree_pi_by_two && s->map->flagPDPE == 0)
			specifyDirectionWallAndCalculateOffset(s, 'E', s->wall[EAST].width, s->wall[EAST].height);
		else
			specifyDirectionWallAndCalculateOffset(s, 'W', s->wall[WEST].width, s->wall[WEST].height);
	}	
}


int			drawRayToWall(t_all *s, int xPlayer, int yPlayer, int xWall, int yWall)
{
	int	dx = xWall - xPlayer;
	int	dy = yWall - yPlayer;
	int		steps;
	float x_increment;
	float y_increment;
	float x = xPlayer;
	float y = yPlayer;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x_increment = dx / (float)steps;
	y_increment = dy / (float)steps;
	int i = 0;
	while (i < steps)
	{
		x +=x_increment;
		y += y_increment;
		my_mlx_pixel_put(s->win, round(x), round(y), 0x1456e3);
		i++;
	}
}	




int		ray_2(t_all *s,  t_dataWall *dataWall)
{
	float PD;
	float PE;
	if (s->map->angle_start > 2 * M_PI)
		s->map->angle_start -= 2 * M_PI;
	else if (s->map->angle_start < 0)
		s->map->angle_start += 2 * M_PI;
	calculatingDeltaForHorizontalIntersection(s, s->map->angle_start);
	calculatingDeltaForVerticallIntersection(s, s->map->angle_start);
	checking_coordinates_h(s);
	checking_coordinates_v(s);
	PD = sqrt(pow((s->map->x_pp - s->map->x_horizont), 2) + pow((s->map->y_pp - s->map->y_horizont), 2));
	PE = sqrt(pow((s->map->x_pp - s->map->x_vertical), 2) + pow((s->map->y_pp - s->map->y_vertical), 2));
	if (PD < PE)
	{
		my_mlx_pixel_put(s->win, s->map->x_horizont, s->map->y_horizont, 0x1456e3);
		drawRayToWall(s, s->map->x_pp, s->map->y_pp, s->map->x_horizont, s->map->y_horizont);
	}
	else
	{
		my_mlx_pixel_put(s->win, s->map->x_vertical, s->map->y_vertical, 0x1456e3);
		drawRayToWall(s, s->map->x_pp, s->map->y_pp, s->map->x_vertical, s->map->y_vertical);
	}
}


int ft_ray_cast_2(t_all *s, t_dataWall *dataWall)
{
	s->map->angle_start = s->map->a_p + M_PI / 6;
	dataWall->index = -1;
	while (++dataWall->index < s->win->x)
	{
		ray_2(s, dataWall);
		s->map->angle_start -= s->ConstValue->delta_ray;
	}	
}



void 		draw2DMap(t_all *s)
{
	int k;
	int i;
	int j;
	int x;
	int y = -1;
	i = -1;
	k = CUBE_SIZE;
	int a = 1;
	while (++i < s->map->size)
	{
		{
			while (++y < (i + 1) * CUBE_SIZE)
			{
				x = -1;
				j = 0;
				while (s->map->level[i][j])
				{
					while (++x < (j + 1) * CUBE_SIZE)
					{
						if (s->map->level[i][j] == '1')
						{
							if ((x + 1) == ((j + 1) * CUBE_SIZE))
							{
								my_mlx_pixel_put(s->win, x, y, 0xaa0000);
								my_mlx_pixel_put(s->win, x + 1, y, 0xaa0000);
							}
							else
								my_mlx_pixel_put(s->win, x, y, 0x878794);
						}
						else if (s->map->level[i][j] == '0' || s->map->level[i][j] == 'N' ||
								s->map->level[i][j] == '2' || s->map->level[i][j] == 'W' ||
								s->map->level[i][j] == 'U' || s->map->level[i][j] == 'S')
						{	
							if ((x + 1) == ((j + 1) * CUBE_SIZE))
							{
								my_mlx_pixel_put(s->win, x, y, 0xaa0000);
								my_mlx_pixel_put(s->win, x + 1, y, 0xaa0000);
							}
							else
								my_mlx_pixel_put(s->win, x, y, 0x36054d);
						}
					}
					j++;
				}
				if ((y + 1) == ((i + 1) * CUBE_SIZE))
				{
					x = -1;
					j--;
					while (++x < (j + 1) * CUBE_SIZE)
					{
						my_mlx_pixel_put(s->win, x, y, 0xaa0000);
						my_mlx_pixel_put(s->win, x, y + 1, 0xaa0000);
					}
				}
			}
		}
	}
}



void		calculation_constant_values(t_all *s)
{
	s->ConstValue->DistanceProjectionPlan = floor((float)s->win->x / 2) / tan(FOV / 2);
	s->ConstValue->CenterProjection = floor((float)s->win->y / 2);
	s->ConstValue->delta_ray = FOV / s->win->x;
	s->ConstValue->ratio_of_texture_height_to_CUBE_SIZE_NORD = s->wall[NORD].width / CUBE_SIZE;
	s->ConstValue->ratio_of_texture_height_to_CUBE_SIZE_South = s->wall[SOUTH].width / CUBE_SIZE;
	s->ConstValue->ratio_of_texture_height_to_CUBE_SIZE_WEST = s->wall[WEST].width / CUBE_SIZE;
	s->ConstValue->ratio_of_texture_height_to_CUBE_SIZE_EAST = s->wall[EAST].width / CUBE_SIZE;
	s->ConstValue->xMapMax = s->fd->max_len * CUBE_SIZE - 1;
	s->ConstValue->yMapMax = s->map->size * CUBE_SIZE - 1;
}

int	take_texture_parameters_sprite(t_all *s, int item, char *filename)
{
	int i;
	
	i = -1;
	if (!(s->sprite = (t_sprite *)malloc(item * (sizeof(t_sprite)))))
		return (-1);
	while (++i < item)
	{
		s->sprite[i].img = mlx_xpm_file_to_image(s->win->mlx, filename, &s->sprite[i].width, &s->sprite[i].height);
		s->sprite[i].adr = mlx_get_data_addr(s->sprite[i].img, &s->sprite[i].bits_per_pixel, &s->sprite[i].size_line, &s->sprite[i].endian);
	}
	return (1);
}

