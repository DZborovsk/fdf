
#include "../include/fdf.h"

t_st	*ft_init_fdf(void)
//Creating stuct fdf and init w, zoom, win, mlx
{
	t_st	*fdf;

	if (!(fdf = (t_st*)malloc(sizeof(t_st))))
		return (NULL);
//	if (!(fdf->mlx = mlx_init()))
//	{
//		ft_putendl("Fail to connect to mlx");
//		return (NULL);
//	}
	fdf->w = 0;
	fdf->zoom = 1;
//	if (!(fdf->win = mlx_new_window(fdf->mlx, 1800, 1200, "FdF")))
//	{
//		ft_putendl("Fail to open window");
//		return (NULL);
//	}
//	if (!(fdf->list = malloc(sizeof(t_coord))))
//		return (NULL);
	return (fdf);
}