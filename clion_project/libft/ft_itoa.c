/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:45:53 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/23 17:07:05 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		tmp;

	tmp = 0;
	i = ft_count_num(n);
	s = (char*)malloc((char)(i + 1));
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	if (n == 0)
		s[i - 1] = '0';
	if (n < 0)
		s[0] = '-';
	while (n)
	{
		i--;
		tmp = n % 10;
		if (tmp < 0)
			tmp = -tmp;
		s[i] = tmp + '0';
		n = n / 10;
	}
	return (s);
}
