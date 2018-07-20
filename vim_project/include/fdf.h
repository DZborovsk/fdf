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
# define PX * 30 + 200

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct 		s_point
{
	int				y;
	int				x;
	int				z;
	void			*mlx;
	void			*win;
	struct s_point	*next;
}					t_point;

t_point	*ft_add_node(void *mlx, void *win, t_point *current, int x, int y, int z);
t_point	*ft_make_line(void *mlx, void *win, t_point *begin, char *line, int y);
t_point	*ft_read(void *mlx, void *win, char *file);

#endif
