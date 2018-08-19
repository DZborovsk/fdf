/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:20:41 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/03 16:12:58 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = len;
	while (src[i] && size > i)
	{
		dst[i] = src[i];
		i++;
	}
	while (size > i)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
