/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:12:55 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/07 17:26:56 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		ft_errorstr(t_all *s, t_list *head, char *str)
{
	ft_putendl_fd(str, 2);
	game_exit(s, head, 0);
}
