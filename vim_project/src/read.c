
#include "../include/fdf.h"

static	void	ft_add_line(t_st *fdf, int y, char *line)
{
	int		x;
	char 	**split;

	x = 0;
	split = ft_strsplit(line, ' ');
	fdf->w = ft_size_of_array(split);
	fdf->matrix[y] = (int*)malloc(sizeof(int) * (fdf->w));
	while (split[x])
	{
		fdf->matrix[y][x] = ft_atoi(split[x]);
		x++;
	}
	ft_free_split(split);
}

static	void	ft_read_to_fdf(t_st *fdf, t_list *begin)
{
	int 	line_nbr;
	t_list *current;

	current = begin;
	fdf->matrix = (int**)malloc(sizeof(int*) * fdf->h);
	line_nbr = 0;
	while (line_nbr < fdf->h && current)
	{
		ft_add_line(fdf, line_nbr, (char*)(current->content));
		line_nbr++;
		current = current->next;
	}
	ft_free_list(begin);
}

static	t_list	*ft_add_next_node(t_list *begin, char *line)
{
	t_list	*current;

	current = begin;
	while (current->next)
		current = current->next;
	current->next = (t_list*)malloc(sizeof(t_list));
	current = current->next;
	current->content = ft_strdup(line);
	current->next = NULL;
	return (current);
}

static	t_list	*ft_add_first_node(t_list *begin, char *line)
{
	begin->content = ft_strdup(line);
	begin->next = NULL;
	return (begin);
}

void	ft_read(t_st *fdf, char *file)
{
	int		fd;
	t_list	*line;
	t_list	*begin;
	char	*temp;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("Open file fail (Error -1)");
		free(fdf);
		exit(0);
	}
	begin = (t_list*)malloc(sizeof(t_list));
	if (get_next_line(fd, &temp) > 0)
	{
		line = ft_add_first_node(begin, temp);
		free(temp);
		fdf->h = 1;
	}
	while ((get_next_line(fd, &temp)) > 0)
	{
		line = ft_add_next_node(line, temp);
		free(temp);
		fdf->h++;
	}
	ft_read_to_fdf(fdf, begin);
}

