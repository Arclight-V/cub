/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:12:55 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/28 20:49:34 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		ft_errorstr(char *str, int num)
{
	if (!num)
	{
		ft_putendl_fd(str, 2);
		exit(1);
	}
	else
	{
		ft_strerror(num);
		exit(1);
	}
}
