/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:52:21 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/21 19:56:24 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*r_str;

	i = 0;
	if (s == NULL || s[i] == '\0' || f == NULL)
		return (0);
	r_str = ft_strnew(ft_strlen(s));
	if (r_str == NULL)
		return (NULL);
	while (s[i])
	{
		r_str[i] = f(i, s[i]);
		i++;
	}
	return (r_str);
}
