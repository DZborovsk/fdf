/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:20:46 by dzborovk          #+#    #+#             */
/*   Updated: 2018/07/22 17:20:48 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_size_of_array(char **arr)
{
	int		l;

	l = 0;
	while (arr[l])
		l++;
	return (l);
}

void	ft_free_split(char **split)
{
	int		index;

	index = 0;
	while (split[index])
	{
		free(split[index]);
		index++;
	}
	free(split);
}

void	ft_free_list(t_list *begin)
{
	t_list	*tmp;
	void 	*content;

	tmp = begin;
	content = begin->content;
	while (begin)
	{
		tmp = begin;
		content = begin->content;
		begin = begin->next;
		free(content);
		free(tmp);
	}
}

static	void	ft_free_matrix_lines(t_st *fdf)
{
	int		y;

	y = 0;
	while (y < fdf->h)
	{
		free(fdf->matrix[y]);
		y++;
	}
	free(fdf->matrix);
}

int		ft_exit(t_st *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	ft_free_matrix_lines(fdf);
	exit(1);
}