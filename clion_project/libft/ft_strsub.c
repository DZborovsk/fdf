/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:23:00 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/22 13:33:52 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	l;

	i = 0;
	if (s == NULL || s[0] == '\0')
		return (NULL);
	l = ft_strlen(s);
	if (l < start || l < len)
		return (NULL);
	sub = ft_strnew(len);
	if (sub == NULL)
		return (NULL);
	while (len--)
		sub[i++] = s[start++];
	return (sub);
}
