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

int		ft_exit(void)
{
	exit(1);
}

void	ft_free_list(t_point *begin)
{
	t_point	*tmp;

	tmp = begin;
	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}

int 	ft_key_hook(int keycode, t_point *list)
{
	if (keycode == 53)
//Exit program if ESC
	{
		mlx_destroy_window(list->mlx, list->win);
		ft_free_list(list);
		ft_exit();
	}
	return (1);
}

void ft_bresen(void *win, void *mlx, int x0, int y0, int x1, int y1, int color)
{
  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = x1 >= x0 ? 1 : -1;
  int sy = y1 >= y0 ? 1 : -1;
  
  if (dy <= dx)
  {
    int d = (dy << 1) - dx;
    int d1 = dy << 1;
    int d2 = (dy - dx) << 1;
    mlx_pixel_put(mlx, win, x0, y0, color);
    for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
    {
      if ( d >0)
      {
        d += d2;
        y += sy;
      }
      else
        d += d1;
      mlx_pixel_put(mlx, win, x, y, color);
    }
  }
  else
  {
    int d = (dx << 1) - dy;
    int d1 = dx << 1;
    int d2 = (dx - dy) << 1;
    mlx_pixel_put(mlx, win, x0, y0, color);
    for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
    {
      if ( d >0)
      {
        d += d2;
        x += sx;
      }
      else
        d += d1;
      mlx_pixel_put(mlx, win, x, y, color);
    }
  }
}

void	ft_input_to_draw(t_point *first, t_point *second)
{
	int 	x_first;
	int 	x_second;
	int 	y_first;
	int 	y_second;	

	x_first = first->x PX;
	y_first = first->y PX;
	x_second = second->x PX;
	y_second = second->y PX;
	ft_bresen(first->win, first->mlx, x_first, y_first, x_second, y_second, 100140111);
}

void	ft_draw(t_point *begin)
{
	t_point *first;
	t_point	*second;

	first = begin;
	while (first->next)
	{
		if (first->y == first->next->y)
			ft_input_to_draw(first, first->next);
		second = first->next;
		while (second)
		{
			if (first->x == second->x)
				ft_input_to_draw(first, second);
			second = second->next;
		}
		first = first->next;
	}

}

int		main(int ac, char **av)
{
	t_point	*list;
	int 	loop;
	void	*mlx;
	void	*win;

	loop = 1;
	if (!(mlx = mlx_init()))
	{
		ft_putendl("Fail to connect to mlx");
		return (1);
	}
	if (!(win = mlx_new_window(mlx, 1440, 800, "FdF")))
	{
		ft_putendl("Fail to open window");
		return (0);
	}
	if (ac < 2)
		return (1);
	if ((list = ft_read(mlx, win, av[1])) == NULL)
		return (1);
	/*	while (head)
	{
		ft_putnbr(head->z);
		if (head->z > 9)
			ft_putchar(' ');
		else
			ft_putstr("  ");
		head = head->next;
		if (loop % 19 == 0)
			ft_putchar('\n');
		loop++;
	}*/
	mlx_string_put(mlx, win, 30, 30, 100255000, "Press ESC to exit");

	mlx_hook(win, 17, 1L << 17, ft_exit, NULL);
	mlx_key_hook(win, ft_key_hook, list);
	ft_draw(list);
	mlx_loop(mlx);
	return (0);
}
