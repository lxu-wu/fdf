#include "../../inc/fdf.h"

void	ft_extention_valider(char *map)
{
	size_t	i;

	i = ft_strlen(map);
	while (i && map[i] != '.')
		i--;
	if (ft_strcmp(map + i, ".fdf"))
	{
		write(2, "File error\n", 11);
		exit(1);
	}
}

int	ft_get_color(char *line, char *ibase, size_t *i)
{
	int		color;
	char	*str;
	size_t	beg;
	int		tmp;

	beg = 0;
	color = 0;
	while (line[beg])
	{
		line[beg] = ft_toupper(line[beg]);
		beg++;
	}
	str = ft_calloc(sizeof(char), ((beg) + 1));
	(*i) += beg--;
	while (beg && line[beg])
	{
		str[beg] =
	}
	printf("color == %d\n", color);
	free(line);
	return (color);
}

t_coor	*ft_modelize(char *line, size_t y)
{
	t_coor	*coor;
	size_t	i;
	long	x;
	t_model	model;
	int		color;

	i = 0;
	x = 0;
	coor = 0;
	while (line[i])
	{
		color = 0;
		model.y = y;
		model.x = x;
		while (line[i] && ft_isspace(line[i]))
			i++;
		model.z = ft_atoi(line + i);
		while (line[i] && line[i] != ' ')
		{
			if (line[i] == ',' && ++i)
				color = ft_get_color(ft_word(line), "0123456789ABCDEF",&i);
			else
				i++;
		}
		x++;
		ft_cooradd_back(&coor, ft_coornew(model, color));
	}
	return (coor);
}

t_coor **ft_get_coor(t_list *lstmap)
{
	t_coor	**coor;
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	coor = malloc(sizeof(t_coor *) * (ft_lstsize(lstmap) + 1));
	while (lstmap)
	{
		coor[i] = ft_modelize(lstmap->content, i);
		lstmap = ft_next(lstmap);
		i++;
	}
	coor[i] = 0;
	return (coor);
}

t_coor	**ft_parsing(char *map)
{
	t_coor	**coor;
	t_model	model;
	int		fd;
	t_list	*lstmap;
	char	*line;

	ft_extention_valider(map);
	lstmap = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{

		perror("open :");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&lstmap, ft_lstnew(line));
		line = get_next_line(fd);
	}
	coor = ft_get_coor(lstmap);
	return (coor);
}