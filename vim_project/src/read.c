
#include "../include/fdf.h"

t_coord	*ft_add_node(t_coord *current, int x, int y, int z)
{
	t_coord	*new;

	if (!x && !y)
	{
		current->x = x;
		current->y = y;
		current->z = z;
		current->next = NULL;
		return (current);
	}
	if ((new = malloc(sizeof(t_coord))) == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	current->next = new;
	return (new);
}

t_coord	*ft_make_line(t_coord *begin, char *line, int y)
{
	t_coord	*current;
	int 	i;
	int 	x;
	int 	z;

	z = 0;
	x = 0;
	i = 0;
	current = begin;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] < '9')
		{
			z = ft_atoi(&line[i]);
//Sending pointer to start of number
			current = ft_add_node(current, x, y, z);
//If 1 number we just complete struct, but if not we create node and complete it
//Return new list
			while (line[i] >= '0' && line[i] < '9')
				i++;
		}
		while (line[i] == ' ')
			i++;
		x++;
//Every time we add only one number
	}
	return (current);
}

t_st	*ft_read(void *mlx, void *win, char *file)
{
	int		fd;
	char	*line;
	char	*buff;
	int 	y;
	t_coord	*head;
	char	*tmp;
	t_coord	*current;
	t_st	*st;

	y = 0;
	buff = ft_strdup("");
	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("Open file fail (Error -1)");
		return (NULL);
	}
	st = malloc(sizeof(t_st));
	head = malloc(sizeof(t_coord));
	st->mlx = mlx;
	st->win = win;
	st->list = head;
//Create chained list
	current = st->list;
//Pointer to the list we didnt touch
	while ((get_next_line(fd, &line)) > 0)
//Make buff with EOL
//Every time we change Y by 1
	{
		tmp = buff;
		buff = ft_strjoin(buff, line);
		buff = ft_strjoin(buff, "\n");
		free(tmp);
		current = ft_make_line(current, line, y);
//Making chained list with current line
//And return last node of list
		y++;
	}
	return (st);
}