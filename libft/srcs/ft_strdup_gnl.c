/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 10:37:55 by anatashi          #+#    #+#             */
/*   Updated: 2020/08/19 10:40:48 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup_gnl(char *src)
{
	char	*new_array;
	size_t	i;

	i = 0;
	if (!(new_array = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		new_array[i] = src[i];
		i++;
	}
	new_array[i] = '\0';
	return (new_array);
}
