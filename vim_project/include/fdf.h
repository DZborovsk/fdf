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

typedef struct 		s_point
{
	int				y;
	int				x;
	int				attitude;
	struct s_point	*next;
}					t_point;

#endif
