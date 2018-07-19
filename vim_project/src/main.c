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

/*int		ft_write_x(void)
{
	ft_putchar('P');
	return (0);
}
*/
/*int		exit_x(void)
{
	exit(1);
}
*/
/*void segment(void *win, void *mlx, int x0, int y0, int x1, int y1, int color)
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
}*/

t_point	*ft_add_node(t_point *current, int x, int y, int att)
{
	t_point	*new;

	if (!x && !y)
	{
		current->x = x;
		current->y = y;
		current->attitude = att;
		current->next = NULL;
		return (current);
	}
	if ((new = malloc(sizeof(t_point))) == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->attitude = att;
	new->next = NULL;
	current->next = new;
	return (new);
}

t_point	*ft_make_line(t_point *begin, char *line, int y)
{
	t_point	*current;
	int 	i;
	int 	x;
	int 	att;

	att = 0;
	x = 0;
	i = 0;
	current = begin;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] < '9')
		{
			att = ft_atoi(&line[i]);
//Sending pointer to start of number
			current = ft_add_node(current, x, y, att);
//If 1 number we just complete struct, but if not we create node and complete it
//Return new list
			while (line[i] >= '0' && line[i] < '9')
				i++;
		}
		while (line[i] == ' ')
			i++;
		x++;
//Every time we add only one number
	}
	return (current);
}

t_point		*ft_read(char *file)
{
	int		fd;
	char	*line;
	char	*buff;
	int 	y;
	t_point	*head;
	char	*tmp;
	t_point	*current;

	y = 0;
	buff = ft_strdup("");
	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("Open file fail (Error -1)");
		return (NULL);
	}
	head = malloc(sizeof(t_point));
//Create chained list
	current = head;
//Pointer to the list we didnt touch
	while ((get_next_line(fd, &line)) > 0)
//Make buff with EOL
//Every time we change Y by 1
	{
		tmp = buff;
		buff = ft_strjoin(buff, line);
		buff = ft_strjoin(buff, "\n");
		free(tmp);
		current = ft_make_line(current, line, y);
//Making chained list with current line
//And return last node of list
		y++;
	}
	return (head);
}

int		main(int ac, char **av)
{
	char 	*buff;
	t_point	*head;
	int 	loop;

	loop = 1;
	buff = NULL;
	if (ac < 2)
		return (1);
	if ((head = ft_read(av[1])) == NULL)
		return (1);
	while (head)
	{
		ft_putnbr(head->attitude);
		if (head->attitude > 9)
			ft_putchar(' ');
		else
			ft_putstr("  ");
		head = head->next;
		if (loop % 19 == 0)
			ft_putchar('\n');
		loop++;
	}
	/*void	*mlx_ptr;
	void	*win_ptr;
	int		i;

	i = 10;
	if ((mlx_ptr = mlx_init()) == NULL)
	{
		ft_putendl("Fail to connect");
		return (1);
	}
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello world");
	if (!win_ptr)
	{
		ft_putendl("Fail to open window");
		return (0);
	}*/
//	mlx_key_hook(win_ptr, ft_write_x, NULL);
/*	mlx_string_put(mlx_ptr, win_ptr, 50, 100, 100255000, "Hello world");
	while (i < 190)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, 20, 100255000);
		i++;
	}*/


	/*mlx_hook(win_ptr, 17, 1L << 17, exit_x, NULL);
	segment(win_ptr, mlx_ptr, 0, 0, 50, 50, 100255000);
	segment(win_ptr, mlx_ptr, 50, 50, 250, 250, 100255000);
	segment(win_ptr, mlx_ptr, 250, 250, 70, 140, 100255000);
	mlx_loop(mlx_ptr);*/
	return (0);
}
