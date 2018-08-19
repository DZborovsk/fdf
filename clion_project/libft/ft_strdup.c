/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:37:29 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/02 16:54:45 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*dup;

	l = 0;
	while (s1[l])
		l++;
	dup = (char *)malloc(sizeof(char) * (l + 1));
	if (dup == NULL)
		return (0);
	l = 0;
	while (s1[l])
	{
		dup[l] = s1[l];
		l++;
	}
	dup[l] = '\0';
	return (dup);
}
