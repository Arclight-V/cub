/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_of_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:17:10 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 19:03:12 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void			checking_validity_map(t_all *s, t_list *head, char *line)
{
	int			i;

	i = 0;
	ft_skip_spaces(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ')
		checking_resolution(s, head, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		checking_textures_wall(s, head, line, NORD);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		checking_textures_wall(s, head, line, SOUTH);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		checking_textures_wall(s, head, line, WEST);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		checking_textures_wall(s, head, line, EAST);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		checking_textures_sprite(s, head, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		checking_color(s, head, line, &s->map->floor);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		checking_color(s, head, line, &s->map->ceil);
	else if (line[i] == '1')
		ft_forb_char_map(s, head, line, &i);
	else if (ft_skip_spaces(line, &i) && line[i] != '\0')
		ft_errorstr(s, head, MAP_3);
}

void		*ft_creat_list(t_all *s, t_list *head, char *line)
{
	t_list	*new;

	new = NULL;
	checking_validity_map(s, head, line);
	if (s->fd->count_ind > 8)
	{
		if (!(new = ft_lstnew(line)))
			ft_errorstr(s, head, MALLOC_10);
		ft_lstadd_back(&head, new);
		return (head);
	}
	ft_free_tmp(line);
	return (head);
}

t_list			*parser_of_scene(t_all *s, t_list *head, char *cub)
{	
	char	*line;
	int		fd;
	int		ret;

	line = NULL;
	if ((fd = open(cub, O_RDONLY)) < 0)
		ft_errorstr(s, head, FD_1);
	while ((ret = get_next_line(fd, &line)) > 0)
		head = ft_creat_list(s, head, line);
	if (ret < 0)
	 	ft_errorstr(s, head, FD_2);
	head = ft_creat_list(s, head, line);
	head = ft_add_space(s, head);
	return (head);
}