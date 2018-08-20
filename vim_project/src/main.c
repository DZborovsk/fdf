/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:01:35 by dzborovk          #+#    #+#             */
/*   Updated: 2018/08/20 10:21:48 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_put_pixel_to_img(t_st *fdf, int x, int y, int color)
{
	if (x > 0 && x < 1600 && y > 0 && y < 1000)
		fdf->grid[y * 1600 + x] = color;
}

int		main(int ac, char **av)
{
	t_st	*fdf;

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
