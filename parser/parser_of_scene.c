/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_of_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:17:10 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/12 09:26:03 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list		*parser_of_scene(t_all *s, t_list *head, char *cub)
{
	char	*line;
	int		fd;
	int		ret;

	line = NULL;
	if ((fd = open(cub, O_RDONLY)) < 0)
		ft_error_output(s, FD_1);
	while ((ret = get_next_line(fd, &line)) > 0)
		head = ft_creat_list(s, head, line);
	if (ret < 0)
		ft_error_output(s, FD_2);
	head = ft_creat_list(s, head, line);
	return (head);
}
