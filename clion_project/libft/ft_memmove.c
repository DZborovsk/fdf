/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:33:06 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/18 18:37:23 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				l;
	unsigned char		*d;
	const unsigned char	*s;

	l = len;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (s > d)
	{
		while (l--)
			*d++ = *s++;
	}
	else
	{
		while (l--)
			*(d + l) = *(s + l);
	}
	return (dst);
}
