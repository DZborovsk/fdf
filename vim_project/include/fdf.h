/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:31:06 by dzborovk          #+#    #+#             */
/*   Updated: 2018/08/20 10:29:28 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define TEXT_COLOR 0xCD3700

typedef struct	s_coor
{
	int			y;
	int			x;
	int			z;
}				t_coor;

typedef struct	s_st
{
	void		*mlx;
	void		*win;
	void		*img;
	int			**matrix;
	float		zoom;
	int			w;
	int			h;
	int			z;
	double		rx;
	double		ry;
	double		rz;
	int			right;
	int			top;
	int			color;
	int			*grid;
}				t_st;

t_st			*ft_init_fdf(void);
void			ft_read(t_st *st, char *file);
int				ft_size_of_array(char **arr);
void			ft_free_split(char **split);
void			ft_free_list(t_list *begin);
int				ft_exit(t_st *fdf);
void			ft_key_control(t_st *fdf);
void			ft_draw(t_st *fdf);
void			ft_prepare_to_draw(t_st *fdf);
t_coor			ft_init_c1_x(t_st *fdf, int y, int x, t_coor c1);
t_coor			ft_init_c2_x(t_st *fdf, int y, int x, t_coor c2);
t_coor			ft_init_c1_y(t_st *fdf, int y, int x, t_coor c1);
t_coor			ft_init_c2_y(t_st *fdf, int y, int x, t_coor c2);
void			ft_put_pixel_to_img(t_st *fdf, int x, int y, int color);
void			ft_text_instructions(t_st *fdf);
void			ft_bars(t_st *fdf);

#endif
