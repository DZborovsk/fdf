/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:36:55 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/11 16:37:10 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		i2;
	size_t		n_len;

	i2 = 0;
	i = 0;
	n_len = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i != len)
	{
		while (haystack[i + i2] == needle[i2])
		{
			if (i2 == n_len - 1 && i + i2 < len)
				return ((char*)(haystack + i));
			i2++;
		}
		i++;
	}
	return (0);
}
