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

int		ft_exit(void)
{
	exit(1);
}

void	ft_free_list(t_coord *begin)
{
	t_coord	*tmp;

	tmp = begin;
	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}
