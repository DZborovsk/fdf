/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:57:04 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/29 17:40:53 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwd(char const *s, char c)
{
	int		w;
	int		i;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			w++;
		while (s[i] != c && s[i])
			i++;
	}
	return (w);
}

static int	ft_countch(char const *s, char c)
{
	int		l;

	l = 0;
	while (*s != c && *s)
	{
		l++;
		s++;
	}
	return (l);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		words;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_countwd(s, c);
	if (!(new = (char**)malloc(sizeof(char*) * words + 1)))
		return (NULL);
	while (*s && i < words)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		if (!(new[i] = (char*)malloc(sizeof(char) * ft_countch(s, c) + 1)))
			return (NULL);
		while (*s != c && *s)
			new[i][j++] = *s++;
		new[i][j] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}
