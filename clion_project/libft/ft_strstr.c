/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:59:37 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/07 20:07:03 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		i2;
	int		l;

	l = ft_strlen(needle);
	i2 = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i + i2] == needle[i2])
		{
			if (i2 == l - 1)
				return ((char*)(haystack + i));
			i2++;
		}
		i2 = 0;
		i++;
	}
	return (0);
}
