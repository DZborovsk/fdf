/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:01:35 by dzborovk          #+#    #+#             */
/*   Updated: 2018/07/17 18:56:57 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_write_x(int key, void *param)
{
	ft_putchar('P');
	return (0);
}

int		exit_x(void)
{
	exit(1);
}

void segment(void *win, void *mlx, int x0, int y0, int x1, int y1, int color)
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

int		ft_gnl_file(char *file)
{
	int		fd;
	char	*line;
	char	*buff;

	buff = ft_strdup("");
	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("Open file fail (Error -1)");
		return (1);
	}
	while ((get_next_line(fd, &line)) > 0)
	{
		buff = ft_strjoin(buff, line);
		buff = ft_strjoin(buff, "\n");
	}
	ft_putstr(buff);
	return (0);
}

int		main(int ac, char **av)
{
/*	void	*mlx_ptr;
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
	}
//	mlx_key_hook(win_ptr, ft_write_x, NULL);
	mlx_string_put(mlx_ptr, win_ptr, 50, 100, 100255000, "Hello world");
	while (i < 190)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, 20, 100255000);
		i++;
	}
*/
	if (ft_gnl_file(av[1]) == 1)
		return (1);
/*	mlx_hook(win_ptr, 17, 1L << 17, exit_x, NULL);
	segment(win_ptr, mlx_ptr, 235, 0, 50, 50, 100255000);
	mlx_loop(mlx_ptr);
*/	return (0);
}
