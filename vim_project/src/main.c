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

void	ft_free_list(t_coord *begin)
{
	t_coord	*tmp;

	tmp = begin;
	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}

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

void	ft_input_to_draw(t_st *st, t_coord *first, t_coord *second)
{
	int 	x_first;
	int 	x_second;
	int 	y_first;
	int 	y_second;	

	x_first = first->x PX;
	y_first = first->y PX;
	x_second = second->x PX;
	y_second = second->y PX;
	if (first->z > 0)
	{
//		x_first = x_first + first->z * 0.2;
		y_first = y_first - first->z;
	}
	if (second->z > 0 && first->z == 0)
	{
		y_second = y_second - second->z;
	}
	if (first->z == second->z)
	{
		
		y_second = y_second - second->z;
	}


/*	if (first->z > 0)
	{
//		x_first = x_first + first->z * 0.2;
		x_first = x_first - first->z;
	}
*/	

//I need to modify not x y here!! I need to modify it in my list
	// if (first->z > 0 && second->z > 0)
	// 	ft_bresen(st->win, st->mlx, x_first-5, y_first - 10, x_second-5, y_second - 10, ROSE);
	// else if (second->z > 0 && first->z == 0)
	// 	ft_bresen(st->win, st->mlx, x_first, y_first, x_second, y_second - 10, RED);
	// else
	ft_bresen(st->win, st->mlx, x_first, y_first, x_second, y_second, ROSE);
}

/*void	ft_change_proection(t_coord *b)
{
	t_coord	*current;

	current = b;
	while (current)
	{
		if (current->z > 0)
		{
			current->x = current->x + (current->z * 0.7);
			current->y = current->y - (current->z * 0.2);
		}
		current = current->next;
	}
}*/

void	ft_draw(t_st *st, t_coord *begin)
{
	t_coord *first;
	t_coord	*second;

	first = begin;
//	ft_change_proection(begin);
	while (first->next)
	{
		if (first->y == first->next->y)
			ft_input_to_draw(st, first, first->next);
		second = first->next;
		while (second)
		{
			if (first->x == second->x)
				ft_input_to_draw(st, first, second);
			second = second->next;
		}
		first = first->next;
	}

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

int		main(int ac, char **av)
{
	t_st	*st;
	int 	loop;
	void	*mlx;
	void	*win;

	loop = 1;
	if (!(mlx = mlx_init()))
	{
		ft_putendl("Fail to connect to mlx");
		return (1);
	}
	if (!(win = mlx_new_window(mlx, 1440, 800, "fdf")))
	{
		ft_putendl("Fail to open window");
		return (0);
	}
	if (ac < 2)
	{
		ft_putendl("File name missing (use: ./fdf file_name)");
		return (1);
	}
	if ((st = ft_read(mlx, win, av[1])) == NULL)
//Creating chained list in struct s_st->list
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
	ft_text_instructions(mlx, win);
//Display all instructions in left top corner
	ft_key_control(st);
//Key setup
	ft_draw(st, st->list);
//Draw chained list
	mlx_loop(mlx);
	return (0);
}
