/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:01:12 by dzborovk          #+#    #+#             */
/*   Updated: 2018/07/16 11:27:59 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*ft_create_chained_list(t_gnl *list, int fd)
{
	char	*data;

	data = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!data)
		return (NULL);
	data[BUFF_SIZE] = '\0';
	if (!list)
	{
		list = (t_gnl*)ft_lstnew(data, (BUFF_SIZE + 1));
		list->size = fd;
	}
	free(data);
	return (list);
}

t_gnl	*ft_return_list_by_fd(t_gnl *current, int fd)
{
	char	*data;

	data = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!data)
		return (NULL);
	data[BUFF_SIZE] = '\0';
	while (current->size != fd && current->next)
		current = current->next;
	if (current->size != fd)
	{
		current->next = (t_gnl*)ft_lstnew(data, (BUFF_SIZE + 1));
		current = current->next;
		current->size = fd;
	}
	free(data);
	return (current);
}

char	*ft_read_file(char *str, t_gnl *current, char *clear)
{
	int		rd;

	rd = 0;
	while (!(ft_strchr(str, '\n'))
		&& (rd = read(current->size, current->content, BUFF_SIZE)) > 0)
	{
		current->content[rd] = '\0';
		clear = str;
		str = ft_strjoin(str, current->content);
		free(clear);
	}
	if (rd == -1)
		return (NULL);
	return (str);
}

int		ft_copy_line(char *str, char *clear, char **line)
{
	if (!ft_strchr(str, '\n'))
	{
		if (ft_strlen(str) > 0)
		{
			clear = str;
			*line = ft_strdup(str);
			free(clear);
			return (1);
		}
		else
			return (0);
	}
	*line = ft_strsub(str, 0, (ft_strchr(str, '\n') - str));
	free(str);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*current;
	char			*str;
	char			*nl;
	char			*clear;

	clear = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	list = ft_create_chained_list(list, fd);
	current = list;
	if (!(current = ft_return_list_by_fd(current, fd)) && !current)
		return (-1);
	if (!(nl = ft_strchr(current->content, '\n')))
		str = ft_strdup("");
	else
	{
		*nl = ' ';
		str = ft_strdup(nl + 1);
	}
	if (!(str = ft_read_file(str, current, clear)))
		return (-1);
	if (ft_copy_line(str, clear, line) == 0)
		return (0);
	return (1);
}
