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

void	ft_init_coord_par(t_st *st)
{
	t_coord	*current;
	float	tmp;

	current = st->list;
	tmp = 0;
	while (current)
	{
		tmp = 500 + (current->x * 50) * st->zoom + CONST *	(current->z * -3) * st->zoom;
		current->x = (int)(tmp + 0.5);
		tmp = 300 + (current->y * 50) * st->zoom + (CONST / 2) * (current->z * -3) * st->zoom;
		current->y = (int)(tmp + 0.5);
		current = current->next;
	}
}

void	ft_input_to_draw(t_st *st, t_coord *first, t_coord *second)
{
	int 	x_first;
	int 	x_second;
	int 	y_first;
	int 	y_second;	

//	ft_init_coord_par(st);
	x_first = first->x;
	y_first = first->y;
	x_second = second->x;
	y_second = second->y;
	ft_bresen(st->win, st->mlx, x_first, y_first, x_second, y_second, ROSE);
}

int 	ft_count_width(t_st *st)
{
	t_coord	*current;

	current = st->list;
	while (current->next && current->y == current->next->y)
		current = current->next;
	return (current->x);
}

void	ft_draw(t_st *st)
{
	t_coord *first;
	t_coord	*second;

	first = st->list;
	
//	ft_putnbr(st->w);
//	ft_putnbr(st->list->x);
	ft_init_coord_par(st);
	st->w = ft_count_width(st);
//	ft_putnbr(st->w);
//	ft_putchar('\n');
	while (first->next)
	{
		if (first->y == first->next->y || first->x != st->w)
			ft_input_to_draw(st, first, first->next);
//		ft_putnbr(first->y);
//		ft_putchar('\n');
		second = first->next;
		while (second)
		{
			if (first->x == second->x)
			{
				ft_input_to_draw(st, first, second);
				break ;
			}
			second = second->next;
		}
		first = first->next;
	}
}
/*	while (second->next)
	{
		while (first->next)
		{
			ft_input_to_draw(st, first, first->next);
			first = first->next;
		}
		if (second->x == second->next->x)
			ft_input_to_draw(st, second, second->next);
		second = second->next;
	}
*/
/*	while (first->next)
	{
		if (_ % first->x!= 0)
			ft_input_to_draw(st, first, first->next);
		if (i < (first->y - 1) * first->x)
			ft_input_to_draw(st, first, first->next);
		first = first->next;
	}
*/

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
