/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:31:06 by dzborovk          #+#    #+#             */
/*   Updated: 2018/07/19 13:05:16 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define CONST 0.5
# define TEXT_COLOR 0xCD3700
# define ROSE 0xDB7093
# define RED 0xCD3700
# define BLUE 0xa020f0

typedef struct 		s_coord
{
	int				y;
	int				x;
	int				z;
	struct s_coord	*next;
}					t_coord;

typedef struct 		s_st
{
	t_coord			*list;
	void			*mlx;
	void			*win;
	void			*img;
	float			zoom;
	int				w;
	int				h;
	int				z;
	int 			rx;
	int 			ry;
	int 			rz;
	int 			right;
	int 			top;
	int 			color;
	int 			*grid;
}					t_st;

t_coord	*ft_add_node(t_coord *current, int x, int y, int z);
t_coord	*ft_make_line(t_coord *begin, char *line, int y);
void 	ft_read(t_st *st, char *file);
void	ft_verif_value(t_st *st);
t_st	*ft_init_st(void);
void	ft_key_control(t_st *st);
void	ft_text_instructions(void *mlx, void *win);
int 	ft_key_hook(int keycode, t_st *st);
//int		ft_zoom(int keycode, t_st *st);
void	ft_free_list(t_coord *begin);
int		ft_exit(void);
void	ft_draw(t_st *st);
int 	ft_count_width(t_st *st);
void	ft_input_to_draw(t_st *st, t_coord *first, t_coord *second);
void	ft_init_coord_par(t_st *st);
void ft_bresen(void *win, void *mlx, int x0, int y0, int x1, int y1, int color);

#endif
