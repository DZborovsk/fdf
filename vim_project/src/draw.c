#include "../include/fdf.h"


void  ft_put_pixel_to_img(t_st *fdf, int x, int y, int color)
{
  if (x > 0 && x < 1600 && y > 0 && y < 1000)
    fdf->grid[y * 1600 + x] = color;
}

static  t_coor ft_rotate(t_coor c, t_st fdf, t_coor ctr)
{
  t_coor c0;
  t_coor c1;
  t_coor c2;

  c0.x = c.x;
  c0.y = (c.y - ctr.y) * cos(fdf.rx) - (c.z - ctr.z) * sin(fdf.rx) + ctr.y;
  c0.z = (c.z - ctr.z) * cos(fdf.rx) - (c.y - ctr.y) * sin(fdf.rx) + ctr.z;
  c1.x = (c0.x - ctr.x) * cos(fdf.ry) - (c0.z - ctr.z) * sin(fdf.ry) + ctr.x;
  c1.y = c0.y;
  c1.z = (c0.z - ctr.z) * cos(fdf.ry) + (c0.x - ctr.x) * sin(fdf.ry) + ctr.z;
  c2.x = (c1.x - ctr.x) * cos(fdf.rz) + (c1.y - ctr.y) * sin(fdf.rz) + ctr.x;
  c2.y = (c1.y - ctr.y) * cos(fdf.rz) - (c1.x - ctr.x) * sin(fdf.rz) + ctr.y;
  return (c2);
}

static  void  ft_draw_line(t_st fdf, t_coor c1, t_coor c2)
{
  t_coor d;
  int   sx;
  int   sy;
  int   err;

  d.x = abs(c2.x - c1.x);
  d.y = abs(c2.y - c1.y);
  sx = c1.x < c2.x ? 1 : -1;
  sy = c1.y < c2.y ? 1 : -1;
  err = d.x - d.y;
  ft_put_pixel_to_img(&fdf, c1.x, c1.y, fdf.color);
  while (c1.x != c2.x || c1.y != c2.y)
  {
    ft_put_pixel_to_img(&fdf, c1.x, c1.y, fdf.color);
    if (err * 2 > -d.y)
    {
      err = err - d.y;
      c1.x = c1.x + sx;
    }
    else
    {
      err = err + d.x;
      c1.y = c1.y + sy;
    }
  }
}

static  void  ft_draw_img(t_st *fdf, int y, t_coor ctr)
{
  int     x;
  t_coor  c1;
  t_coor  c2;

  x = 0;
  while (x < fdf->w)
  {
    c1 = ft_init_c1_x(fdf, y, x, c1);
    c2 = ft_init_c2_x(fdf, y, x, c2);
    if (x != fdf->w - 1)
      ft_draw_line(*fdf, ft_rotate(c1, *fdf, ctr), ft_rotate(c2, *fdf, ctr));
    c1 = ft_init_c1_y(fdf, y, x, c1);
    c2 = ft_init_c2_y(fdf, y, x, c2);
    if (y != fdf->h - 1)
      ft_draw_line(*fdf, ft_rotate(c1, *fdf, ctr), ft_rotate(c2, *fdf, ctr));
    x++;
  }
}

void	ft_prepare_to_draw(t_st *fdf)
{
  int     y;
  t_coor  ctr;

  ctr.x = 800;
  ctr.y = 500;
  ctr.z = 0;
  y = 0;
  if (fdf->zoom < 0)
    fdf->zoom = 0;
  while (y < fdf->h)
  {
    ft_draw_img(fdf, y, ctr);
    y++;
  }
}

void	ft_draw(t_st *fdf)
{
  int bpp;
  int sl;
  int e;

	fdf->right = 500;
	fdf->top = 0;
	fdf->zoom = 50;
	fdf->z = 2;
	fdf->color = 0xDB7093;
  fdf->rx = 8.4;
  fdf->ry = 0.6;
  fdf->rz = -0.5;
	fdf->img = mlx_new_image(fdf->mlx, 1600, 1000);
	fdf->grid = (int*)mlx_get_data_addr(fdf->img, &bpp, &sl, &e);
	ft_prepare_to_draw(fdf);
  ft_bars(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
  ft_text_instructions(fdf);
  ft_key_control(fdf);
  mlx_loop(fdf->mlx);
}
