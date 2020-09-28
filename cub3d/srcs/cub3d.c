/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:08:43 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/24 12:07:07 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_start(char *cub)
{
	t_all			*s;
	t_map			*map;
	t_err 			*err;
	t_fd			*fd;
	t_win			*win;
	t_ConstValue 	*ConstValue;
	t_nord			*nord;
	t_south			*south;
	t_west			*west;
	t_east			*east;
	t_dataWall 		*dataWall;
	t_sprite		*sprite;
	// map = NULL;
	// err = NULL;
	fd = NULL;
	
	// map = ft_creat_map_s();
	// err = ft_creat_err_s();
	s = ft_creat_all_s();

	// if (!(map = ft_creat_map_s()))
	// 	return (ft_strerror(10));
	// if (!(err = ft_creat_err_s()))
	// 	return (ft_strerror(11));
	// if (!(fd = ft_creat_fd_s()))
	// 	return (ft_strerror(12));
	// if (!(s = ft_creat_all_s()))
	// 	return (ft_strerror(13));
	
	s->map = ft_creat_map_s();
	s->err = ft_creat_err_s();
	s->fd = ft_creat_fd_s();
	s->win = ft_creat_win_s();
	s->ConstValue = ft_constValue_s();
	s->nord = ft_creat_nord_s();
	s->south = ft_creat_south_s();
	s->west = ft_creat_west_s();
	s->east = ft_creat_east_s();
	s->dataWall = ft_creat_dataWall_s();
	// s->sprite = ft_creat_sprite_s();
	ft_parser(cub, s);

}


int		main (int argc, char **argv)
{
			if (argc == 2)
		ft_start(argv[1]);
	else
	{
		ft_start("str");
	}
	
}