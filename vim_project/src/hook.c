/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:14:54 by dzborovk          #+#    #+#             */
/*   Updated: 2018/07/22 17:14:56 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*int		ft_zoom(int keycode, t_st *st)
{
	if (keycode == 69)
	{
		st->zoom = (st->zoom + 0.2) > 10 ? 9.8 : st->zoom + 0.2;
		mlx_clear_window(st->mlx, st->win);
//		if (e->iso)
//			e->tab = ft_init_coor_iso(e);
//		else
		ft_init_coord_par(st);
		ft_draw(st, st->list);
//		expose_hook(e);
	}
	if (keycode == 78)
	{
		st->zoom = ((st->zoom * 0.8) < 0.1 ? 0.12 : st->zoom * 0.8);
		mlx_clear_window(st->mlx, st->win);
//		if (e->iso)
//			e->tab = ft_init_coor_iso(e);
//		else
		ft_init_coord_par(st);
		ft_draw(st, st->list);
//		expose_hook(e);
	}
	return (1);
}*/

int 	ft_key_hook(int keycode, t_st *st)
{
	if (keycode == 53)
//Exit program if ESC
	{
		mlx_destroy_window(st->mlx, st->win);
		ft_free_list(st->list);
		free(st);
		ft_exit();
	}
//	if (keycode == 69 || keycode == 78)
//		ft_zoom(keycode, st);
	return (1);
}

void	ft_text_instructions(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 35, 35, TEXT_COLOR, "Press ESC to exit");
	mlx_string_put(mlx, win, 35, 55, TEXT_COLOR, "Move = ^ v < >");
	mlx_string_put(mlx, win, 35, 75, TEXT_COLOR,
		"Zoom = + - or scrolling");
	mlx_string_put(mlx, win, 35, 95, TEXT_COLOR, "Isometric = i");
	mlx_string_put(mlx, win, 35, 115, TEXT_COLOR, "Parallel = p");
	mlx_string_put(mlx, win, 35, 135, TEXT_COLOR, "Increase z = *");
	mlx_string_put(mlx, win, 35, 155, TEXT_COLOR, "Decrease z = /");
	mlx_string_put(mlx, win, 35, 175, TEXT_COLOR, "Increase x = 1");
	mlx_string_put(mlx, win, 35, 195, TEXT_COLOR, "Decrease x = 2");
	mlx_string_put(mlx, win, 35, 215, TEXT_COLOR, "Increase z = 4");
	mlx_string_put(mlx, win, 35, 235, TEXT_COLOR, "Decrease z = 5");
	mlx_string_put(mlx, win, 35, 255, TEXT_COLOR, "Change color = .");
}

void	ft_key_control(t_st *st)
{
	mlx_hook(st->win, 17, 1L << 17, ft_exit, NULL);
	mlx_key_hook(st->win, ft_key_hook, st);
}
