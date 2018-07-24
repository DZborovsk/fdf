
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

void	ft_verif_value(t_st *st)
{
	t_coord	*current;

	current = st->list;
	while (current)
	{
		if (current->z > 1000 || current->z < -1000)
		{
			mlx_destroy_window(st->mlx, st->win);
			ft_free_list(st->list);
			free(st);
			ft_exit();
		}
		current = current->next;
	}
}

void	ft_read(t_st *st, char *file)
{
	int		fd;
	char	*line;
	char	*buff;
	int 	y;
	char	*tmp;
	t_coord	*current;

	y = 0;
	buff = ft_strdup("");
	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_putendl("Open file fail (Error -1)");
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
	ft_verif_value(st);
}

t_st	*ft_init_st(void)
//Creating stuct st and init it
{
	t_st	*st;

	if (!(st = malloc(sizeof(t_st))))
		return (NULL);
	if (!(st->mlx = mlx_init()))
	{
		ft_putendl("Fail to connect to mlx");
		return (NULL);
	}
	st->w_win = 1600;
	st->h_win = 1000;
	st->w = 0;
	st->zoom = 1;
	if (!(st->win = mlx_new_window(st->mlx, st->w_win, st->h_win, "fdf")))
	{
		ft_putendl("Fail to open window");
		return (NULL);
	}
	if (!(st->list = malloc(sizeof(t_coord))))
		return (NULL);
	return (st);
}