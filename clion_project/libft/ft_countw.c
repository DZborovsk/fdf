/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:43:34 by dzborovk          #+#    #+#             */
/*   Updated: 2017/12/01 13:17:49 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_countw(char const *s)
{
	size_t		w;
	char const	*str;

	str = s;
	w = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (*str)
	{
		while ((*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\f' || *str == '\v' || *str == '\r')
				&& *str)
			str++;
		if (*str)
			w++;
		while ((*str != ' ' || *str != '\t' || *str != '\n'
			|| *str != '\f' || *str != '\v' || *str != '\r')
				&& *str)
			str++;
	}
	return (w);
}
