/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_of_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:17:10 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/30 19:32:08 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

t_list			*parser_of_scene(char *cub, t_all *s, t_list *head)
{	
	char	*line;

	line = NULL;
	if ((s->fd->fd = open(cub, O_RDONLY)) < 0)
		return (ft_errorstr(FD_1, 0));
	while ((s->fd->ret = get_next_line(s->fd->fd, &line)) > 0)
	{
		if (!(head = ft_creat_list(head, s, line)) || s->err->num < 0)
			return (ft_errorstr(NULL,s->err->num));
	}
	if (!(head = ft_creat_list(head, s, line)))
		return (ft_strerror(-15));
	if (!(head = ft_add_space(&head, s)))
		return (ft_strerror(-15));
	return (head);
}