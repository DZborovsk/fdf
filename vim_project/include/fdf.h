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

# define PX * 40 + 300
# define PX1 * 40 + 300
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
}					t_st;

t_coord	*ft_add_node(t_coord *current, int x, int y, int z);
t_coord	*ft_make_line(t_coord *begin, char *line, int y);
t_st	*ft_read(void *mlx, void *win, char *file);

#endif
