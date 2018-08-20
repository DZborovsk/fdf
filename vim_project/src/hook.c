/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:14:54 by dzborovk          #+#    #+#             */
/*   Updated: 2018/08/20 10:17:30 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		ft_clear_img(t_st *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1600)
		{
			ft_put_pixel_to_img(fdf, x, y, 0);
			x++;
		}
		y++;
	}
}

void		ft_bars(t_st *fdf)
{
	int		bar;
	int		line;

	bar = 0;
	while (bar < 50)
	{
		line = 0;
		while (line < 1600)
		{
			fdf->grid[bar * 1600 + line] = fdf->color;
			line++;
		}
		bar++;
	}
	bar = 949;
	while (bar < 1000)
	{
		line = 0;
		while (line < 1600)
		{
			fdf->grid[bar * 1600 + line] = fdf->color;
			line++;
		}
		bar++;
	}
}

static	int	ft_key_hook(int keycode, t_st *fdf)
{
	if (keycode == 53)
		ft_exit(fdf);
	ft_clear_img(fdf);
	(keycode == 12) ? fdf->rz += 0.1 : 0;
	(keycode == 0) ? fdf->rz -= 0.1 : 0;
	(keycode == 13) ? fdf->rx += 0.1 : 0;
	(keycode == 1) ? fdf->rx -= 0.1 : 0;
	(keycode == 14) ? fdf->ry += 0.1 : 0;
	(keycode == 2) ? fdf->ry -= 0.1 : 0;
	(keycode == 125) ? fdf->right += 40 : 0;
	(keycode == 126) ? fdf->right -= 40 : 0;
	(keycode == 123) ? fdf->top -= 40 : 0;
	(keycode == 124) ? fdf->top += 40 : 0;
	(keycode == 69) ? fdf->zoom += 1 : 0;
	(keycode == 78) ? fdf->zoom -= 1 : 0;
	(keycode == 91) ? fdf->z += 10 : 0;
	(keycode == 87) ? fdf->z -= 10 : 0;
	(keycode == 8) ? fdf->color -= 43 : 0;
	ft_prepare_to_draw(fdf);
	ft_bars(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	ft_text_instructions(fdf);
	return (0);
}

void		ft_text_instructions(t_st *fdf)
{
	void	*mlx;
	void	*win;

	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 35, 55, fdf->color - 87, "Press ESC to exit");
	mlx_string_put(mlx, win, 35, 75, fdf->color - 87, "Move = < ^ v >");
	mlx_string_put(mlx, win, 35, 95, fdf->color - 87, "Zoom = + -");
	mlx_string_put(mlx, win, 35, 115, fdf->color - 87, "Change height = 8 5");
	mlx_string_put(mlx, win, 35, 135, fdf->color - 87, "Rotate z = Q A");
	mlx_string_put(mlx, win, 35, 155, fdf->color - 87, "Rotate x = E D");
	mlx_string_put(mlx, win, 35, 175, fdf->color - 87, "Rotate y = W S");
	mlx_string_put(mlx, win, 35, 195, fdf->color - 87, "Change color = C");
}

void		ft_key_control(t_st *fdf)
{
	mlx_hook(fdf->win, 17, 1L << 17, ft_exit, fdf);
	mlx_key_hook(fdf->win, ft_key_hook, fdf);
}
