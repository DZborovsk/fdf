/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:51:41 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/17 16:17:01 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char		*s;
	unsigned char	*m;

	s = (char*)src;
	m = (unsigned char*)dst;
	while (n--)
		*m++ = *s++;
	return (dst);
}
