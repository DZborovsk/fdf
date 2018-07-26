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

/*void	ft_init_coord_par(t_st *st)
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
}*/

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

void    color_brain(t_coord *head, t_coord *first, t_coord *second)
{
  int x1;
  int y0;
  int z0;
  int z1;
  int *arr;

  arr = malloc(sizeof((int*)4));
  y0 = ((first->y - head->height / 2) PY) * cos(head->rotx) + ((first->z - head->cz) PZ) * sin(head->rotx) + (head->height / 2) PY + head->plus_h;
  z0 = ((first->z - head->cz) PZ) * cos(head->rotx) - ((first->y - head->height / 2) PY) * sin(head->rotx) + head->cz PZ;
  x1 = ((first->x - head->width / 2) PX) * cos(head->roty) - (z0 - head->cz) * sin(head->roty) + (head->width / 2) PX + head->plus_w;
  z1 = (z0 - head->cz) * cos(head->roty) + (first->x - head->width / 2) * sin(head->roty) + head->cz;
  arr[0] = (x1 - head->width / 2) * cos(head->rotz) + (y0 - head->height / 2) * sin(head->rotz) + head->width / 2;
  arr[1] = (y0 - head->height / 2) * cos(head->rotz) - (x1 - head->width / 2) * sin(head->rotz) + head->height / 2;
  y0 = ((second->y - head->height / 2) PY) * cos(head->rotx) + ((second->z - head->cz) PZ) * sin(head->rotx) + (head->height / 2) PY + head->plus_h;
  z0 = ((second->z - head->cz) PZ) * cos(head->rotx) - ((second->y - head->height / 2) PY) * sin(head->rotx) + head->cz PZ;
  x1 = ((second->x - head->width / 2) PX) * cos(head->roty) - (z0 - head->cz) * sin(head->roty) + (head->width / 2) PX + head->plus_w;
  z1 = (z0 - head->cz) * cos(head->roty) + (second->x - head->width / 2) * sin(head->roty) + head->cz;
  arr[2] = (x1 - head->width / 2) * cos(head->rotz) + (y0 - head->height / 2) * sin(head->rotz) + head->width / 2;
  arr[3] = (y0 - head->height / 2) * cos(head->rotz) - (x1 - head->width / 2) * sin(head->rotz) + head->height / 2;

  // arr = transform(head, first, second);
  ft_line(head, arr, first->color, second->color, first, second);
  free(arr);
}

void	ft_draw_img(t_st *st)
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
		if (first->next->next && first->x != st->w)
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

void	ft_draw(t_st *st)
{
//	int	bpp;
//	int	sl;
//	int	e;

	st->rx = 8;
	st->ry = 0;
	st->rz = -0;
	st->right = 1460;
	st->top = -620;
	st->zoom = 1;
	st->z = 0;
	st->color = 0xDB7093;
	st->img = mlx_new_image(st->mlx, 1800, 1050);
//	st->grid = (int*)mlx_get_data_addr(st->img, &bpp, &sl, &e);
	ft_draw_img(st);
//	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
}
