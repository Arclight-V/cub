/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_of_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:17:10 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/05 18:26:15 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int				checking_validity_map(t_list *head, char *line, t_all *s)
{
	int			i;

	i = 0;
	ft_skip_spaces(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ')
		return (s->fd->err = checking_resolution(s, line, &i));
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (s->fd->err = checking_textures_wall(s, line, &i, NORD));
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (s->fd->err = checking_textures_wall(s, line, &i, SOUTH));
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		return (s->fd->err = checking_textures_wall(s, line, &i, WEST));
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		return (s->fd->err = checking_textures_wall(s, line, &i, EAST));
	else if (line[i] == 'S' && line[i + 1] == ' ')
		return (s->fd->err = checking_textures_sprite(s, line, &i));
	else if (line[i] == 'F')
		return (s->fd->err = checking_color(&s->map->floor, line, &i, &s->fd->count_ind));
	else if (line[i] == 'C')
		return (s->fd->err = checking_color(&s->map->ceil, line, &i, &s->fd->count_ind));	
	else if (line[i] == '1')
		return (s->fd->err = ft_forb_char_map(&head, line, s, &i));
	else if (ft_skip_spaces(line, &i) && line[i] != '\0')
		return (-92);
	return (1);
}

t_list			*ft_creat_list(t_list *head, t_all *s, char *line)
{
	t_list	*new;

	new = NULL;
	if ((s->fd->err = checking_validity_map(head, line, s)) < 0)
		return (NULL);
	if (s->fd->count_ind > 8)
	{
		if (!(new = ft_lstnew(line)))
		{	
			ft_lstclear(&head,lstdelone_f);
			s->fd->err = -15;
			return (NULL);
		}
		ft_lstadd_back(&head, new);
	}
	return (head);
}

t_list			*parser_of_scene(char *cub, t_all *s, t_list *head)
{	
	char	*line;
	int		fd;
	int		ret;

	line = NULL;
	if ((fd = open(cub, O_RDONLY)) < 0)
	{	
		s->fd->err = -1;
		return (NULL);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(head = ft_creat_list(head, s, line)) && s->fd->err < 0)
			return (NULL);
	}
	if (!(head = ft_creat_list(head, s, line)) && s->fd->err < 0)
		return (NULL);
	if (!(head = ft_add_space(&head, s)))
		return (NULL);
	return (head);
}