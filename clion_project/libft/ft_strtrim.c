/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:52:21 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/22 18:16:52 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		l;
	int		i;
	char	*n;
	int		i2;

	i2 = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	l = (int)ft_strlen(s);
	l--;
	while ((s[l] == ' ' || s[l] == '\n' || s[l] == '\t') && s[l])
		l--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (l == -1)
		l = i - 1;
	n = (char*)malloc((char)(l - (i - 1) + 1));
	if (n == NULL)
		return (NULL);
	while (i <= l && s[i])
		n[i2++] = s[i++];
	n[i2] = '\0';
	return (n);
}
