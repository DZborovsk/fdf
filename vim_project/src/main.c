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
	t_st 	*st;
//	int 	loop = 1;
	if (ac < 2)
//Checking file name
	{
		ft_putendl("File name missing (use: ./fdf file_name)");
		return (1);
	}
	if (!(st = ft_init_st()))
//Creating stuct st and init it
//Creating win
		return (1);
	ft_read(st, av[1]);
/*	while (st->list)
	{
		ft_putnbr(st->list->z);
		if (st->list->z > 9)
			ft_putchar(' ');
		else
			ft_putstr("  ");
		st->list = st->list->next;
		if (loop % 19 == 0)
			ft_putchar('\n');
		loop++;
	}*/
//Creating chained list in struct s_st->list
	ft_text_instructions(st->mlx, st->win);
//Display all instructions in left top corner
	ft_key_control(st);
//Key setup
	ft_draw(st);
//Draw chained list
	mlx_loop(st->mlx);
	return (0);
}
