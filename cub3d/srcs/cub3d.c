/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:08:43 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/28 19:41:14 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				initializing_structures(char *cub)
{
	t_all			*s;

	if (!(s = initializing_structure_of_structures()))
		return (ft_errorstr(MALLOC_1));
	if (!(s->map = initializing_map_structure()))
		return (ft_errorstr(MALLOC_2));
	if (!(s->err = initializing_err_structure()))
		return( ft_errorstr(MALLOC_3));
	if (!(s->fd = initializing_fd_structure()))
		return (ft_errorstr(MALLOC_4));
	if (!(s->win = initializing_win_structure()))
		return (ft_errorstr(MALLOC_5));
	if (!(s->ConstValue = initializing_const_values_structure()))
		return (ft_errorstr(MALLOC_6));
	if (!(s->nord = initializing_nord_wall_structure()))
		return(ft_errorstr(MALLOC_7));
	if (!(s->south = initializing_south_wall_structure()))
		return(ft_errorstr(MALLOC_8));
	if (!(s->west = initializing_west_wall_structure()))
		return(ft_errorstr(MALLOC_9));
	if (!(s->east = initializing_east_wall_structure()))
		return(ft_errorstr(MALLOC_10));
	if (!(s->dataWall = initializing_slice_parameters_structure()))
		return(ft_errorstr(MALLOC_11));	
	// s->sprite = ft_creat_sprite_s();
	ft_parser(cub, s);

}


int		main (int argc, char **argv)
{
			if (argc == 2)
		initializing_structures(argv[1]);
	else
	{
		initializing_structures("str");
	}
	
}