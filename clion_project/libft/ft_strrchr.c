/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:30:23 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/07 18:50:15 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;

	l = ft_strlen(s) - 1;
	if ('\0' == (char)c)
		return ((char*)(s + l + 1));
	while (l >= 0 && s && *(s + l))
	{
		if (*(s + l) == (char)c)
			return ((char*)(s + l));
		l--;
	}
	return (0);
}
