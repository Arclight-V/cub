/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_of_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:17:10 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/03 13:05:26 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

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