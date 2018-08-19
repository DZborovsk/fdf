/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:07:24 by dzborovk          #+#    #+#             */
/*   Updated: 2017/12/01 13:22:23 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*new;

	if (!f || !lst)
		return (NULL);
	if (!(current = f(lst)))
		return (NULL);
	new = current;
	while (lst->next)
	{
		lst = lst->next;
		if (!(current->next = f(lst)))
		{
			free(current->next);
			return (NULL);
		}
		current = current->next;
	}
	return (new);
}
