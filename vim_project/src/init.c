
#include "../include/fdf.h"

t_coor	ft_init_c1_x(t_st *fdf, int y, int x, t_coor c1)
{
	c1.z = fdf->matrix[y][x];
	c1.x = y * fdf->zoom + fdf->right;
	c1.y = x * fdf->zoom + fdf->top;
	if (c1.z != 0)
		c1.z = (c1.z * fdf->z) * 0.2;
	return (c1);
}

t_coor	ft_init_c1_y(t_st *fdf, int y, int x, t_coor c1)
{
	c1.z = fdf->matrix[y][x];
	c1.x = y * fdf->zoom + fdf->right;
	c1.y = x * fdf->zoom + fdf->top;
	if (c1.z != 0)
		c1.z = (c1.z* fdf->z) * 0.2;
	return (c1);
}

t_coor	ft_init_c2_x(t_st *fdf, int y, int x, t_coor c2)
{
	if (fdf->w - 1 != x)
		c2.z = fdf->matrix[y][x + 1];
	if (c2.z != 0)
		c2.z = (c2.z * fdf->z) * 0.2;
	c2.x = y * fdf->zoom + fdf->right;
	c2.y = x * fdf->zoom + fdf->zoom + fdf->top;
	return (c2);
}

t_coor	ft_init_c2_y(t_st *fdf, int y, int x, t_coor c2)
{
	if (fdf->h - 1 != y)
		c2.z = fdf->matrix[y + 1][x];
	c2.x = (y * fdf->zoom) + fdf->zoom + fdf->right;
	c2.y = x * fdf->zoom + fdf->top;
	if (c2.z != 0)
		c2.z = (c2.z * fdf->z) * 0.2;
	return (c2);
}

t_st	*ft_init_fdf(void)
{
	t_st	*fdf;

	if (!(fdf = (t_st*)malloc(sizeof(t_st))))
		return (NULL);
	if (!(fdf->mlx = mlx_init()))
	{
		ft_putendl("Fail to connect to mlx");
		return (NULL);
	}
	fdf->w = 0;
	if (!(fdf->win = mlx_new_window(fdf->mlx, 1600, 1000, "FdF")))
	{
		ft_putendl("Fail to open window");
		return (NULL);
	}
	return (fdf);
}