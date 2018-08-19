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
	{
		ft_putendl("File name missing (use: ./fdf file_name)");
		return (1);
	}
	if (!(fdf = ft_init_fdf()))
	{
		free(fdf);
		return (1);
	}
	ft_read(fdf, av[1]);
	ft_draw(fdf);
	system("leaks fdf");
	return (0);
}
