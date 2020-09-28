/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:08:43 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/28 20:48:37 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				initializing_structures(char *cub)
{
	t_all			*s;

	if (!(s = initializing_structure_of_structures()))
		return (ft_errorstr(MALLOC_1, 0));
	if (!(s->map = initializing_map_structure()))
		return (ft_errorstr(MALLOC_2, 0));
	if (!(s->err = initializing_err_structure()))
		return( ft_errorstr(MALLOC_3, 0));
	if (!(s->fd = initializing_fd_structure()))
		return (ft_errorstr(MALLOC_4, 0));
	if (!(s->win = initializing_win_structure()))
		return (ft_errorstr(MALLOC_5, 0));
	if (!(s->ConstValue = initializing_const_values_structure()))
		return (ft_errorstr(MALLOC_6, 0));
	if (!(s->nord = initializing_nord_wall_structure()))
		return(ft_errorstr(MALLOC_7, 0));
	if (!(s->south = initializing_south_wall_structure()))
		return(ft_errorstr(MALLOC_8, 0));
	if (!(s->west = initializing_west_wall_structure()))
		return(ft_errorstr(MALLOC_9, 0));
	if (!(s->east = initializing_east_wall_structure()))
		return(ft_errorstr(MALLOC_10, 0));
	if (!(s->dataWall = initializing_slice_parameters_structure()))
		return(ft_errorstr(MALLOC_11, 0));	
	ft_parser(cub, s);

}


int		main (int argc, char **argv)
{
	if (argc == 2)
		initializing_structures(argv[1]);
	else
		ft_putendl_fd("Error : Invalid arguments", 2);
	return (0);
	
}