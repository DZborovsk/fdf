
#include "../include/fdf.h"

t_point	*ft_add_node(void *mlx, void *win, t_point *current, int x, int y, int z)
{
	t_point	*new;

	if (!x && !y)
	{
		current->x = x;
		current->y = y;
		current->z = z;
		current->next = NULL;
		current->mlx = mlx;
		current->win = win;
		return (current);
	}
	if ((new = malloc(sizeof(t_point))) == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	current->next = new;
	new->mlx = mlx;
	new->win = win;
	return (new);
}

t_point	*ft_make_line(void *mlx, void *win, t_point *begin, char *line, int y)
{
	t_point	*current;
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
			current = ft_add_node(mlx, win, current, x, y, z);
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

t_point	*ft_read(void *mlx, void *win, char *file)
{
	int		fd;
	char	*line;
	char	*buff;
	int 	y;
	t_point	*head;
	char	*tmp;
	t_point	*current;

	y = 0;
	buff = ft_strdup("");
	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("Open file fail (Error -1)");
		return (NULL);
	}
	head = malloc(sizeof(t_point));
//Create chained list
	current = head;
//Pointer to the list we didnt touch
	while ((get_next_line(fd, &line)) > 0)
//Make buff with EOL
//Every time we change Y by 1
	{
		tmp = buff;
		buff = ft_strjoin(buff, line);
		buff = ft_strjoin(buff, "\n");
		free(tmp);
		current = ft_make_line(mlx, win, current, line, y);
//Making chained list with current line
//And return last node of list
		y++;
	}
	return (head);
}