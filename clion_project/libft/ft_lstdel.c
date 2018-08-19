/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:02:26 by dzborovk          #+#    #+#             */
/*   Updated: 2017/11/30 16:09:23 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*current;

	current = *alst;
	if (alst)
	{
		if (*alst && *del)
		{
			while (current)
			{
				temp = current->next;
				del(current->content, current->content_size);
				free(current);
				current = temp;
				*alst = NULL;
			}
		}
	}
}
