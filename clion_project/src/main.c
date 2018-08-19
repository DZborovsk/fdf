/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:01:35 by dzborovk          #+#    #+#             */
/*   Updated: 2018/07/19 13:04:53 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		main(int ac, char **av)
{
	t_st 	*fdf;

	if (ac < 2)
//Checking file name
	{
		ft_putendl("File name missing (use: ./fdf file_name)");
		return (1);
	}
	if (!(fdf = ft_init_fdf()))
//Creating stuct fdf and init it //Creating win, mlx ...
	{
		free(fdf);
		return (1);
	}
	ft_read(fdf, av[1]);
//Creating chained list in struct s_st->list
//	ft_text_instructions(fdf->mlx, fdf->win);
//Display all instructions in left top corner
	//ft_key_control(fdf);
//Key setup
	//ft_draw(fdf);
//Draw chained list
	//mlx_loop(fdf->mlx);
	return (0);
}
