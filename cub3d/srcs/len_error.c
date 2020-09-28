/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:04:14 by anatashi          #+#    #+#             */
/*   Updated: 2020/08/31 13:10:47 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

int main ()
{
	// char *s = "Error : Couldn't read fd\n";
	// printf("len s is %li\n", strlen(s));

	int i = 0;
	char *s = "Error : Malloc fail (creating a list from fd)\n";
	while (s[++i])
	{
		printf("s = %c [i] = %i\n", s[i],i);
	}
	
}