/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:46:25 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/04 16:07:11 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char			*d;
	const char		*s;
	size_t			dsize;
	size_t			dlen;

	dsize = dstsize;
	s = src;
	d = dst;
	while (dsize-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	dsize = dstsize - dlen;
	if (dsize == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (dsize != 1)
		{
			*d++ = *s;
			dsize--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
