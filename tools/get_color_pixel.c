/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:13:06 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/09 16:14:07 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_color_pixel(t_data *data, char *adr, int size_line,\
							int bps)
{
	char	*color;

	color = adr + (data->y_image[data->i] * size_line +\
					data->x_image[data->i] * (bps >> 3));
	return (*(unsigned int*)color);
}
