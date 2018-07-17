/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:16:37 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/18 19:26:21 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		chr;

	chr = (unsigned char)c;
	str = (unsigned char*)s;
	while (n--)
	{
		if (*(str++) == (unsigned char)c)
			return ((void*)(str - 1));
	}
	return (NULL);
}
