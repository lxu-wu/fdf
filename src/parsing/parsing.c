#include "../../inc/fdf.h"







// size_t	ft_coor_len(t_data *data)
// {
// 	size_t	len;
// 	size_t	tmp;
// 	size_t	i;

// 	i = 0;
// 	len = 0;
// 	while (data->coor[i])
// 	{
// 		tmp = ft_coorsize(data->coor[i++]);
// 		if (len < tmp)
// 			len = tmp;
// 	}
// 	return (len);
// }

// size_t	ft_coor_height(t_data *data)
// {
// 	size_t	i;

// 	i = 0;
// 	while (data->coor[i])
// 		i++;
// 	return (i);
// }
	// ft_data_reset(data);
	// data->len = ft_coor_len(data);
	// ft_data_reset(data);
	// data->height = ft_coor_height(data);
	// ft_data_reset(data);














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

int	ft_check_str(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (c == base[i])
		return (i);
	printf("%c\n", c);
	ft_error(5);
	return (1);
}	

int	ft_atoi_base(char *str, char *base)
{
	int		n;
	int		neg;
	int		base_len;
	char	*tmp;

	tmp = str;
	// printf("%s\n", str);
	if (str[0] != '0' || str[1] != 'X')
		ft_error(4);
	str += 2;
	base_len = ft_strlen(base);
	n = 0;
	while (*str && ft_check_str(*str, base) >= 0)
	{
		n = n * base_len + ft_check_str(*str, base);
		str++;
	}
	free(tmp);
	return (n);
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
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (line[i])
		{
			color = 0x00FFFFFF;
			model.y = y;
			model.x = x;
			model.z = ft_atoi(line + i);
			while (line[i] && line[i] != ' ')
			{
				if (line[i] == ',' && ++i)
				{
					color = ft_atoi_base(ft_strupper(ft_word(line + i)), "0123456789ABCDEF");
					while (line[i] && line[i] != ' ')
						i++;
				}
				else
					i++;
			}
			x++;
			ft_cooradd_back(&coor, ft_coornew(model, color));
		}
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

int	ft_check_line(char *line)
{
	size_t	i;
	int		e;

	i = 0;
	e = 0;
	if (line[0] == '-')
		i++;
	while (line[i])
	{
		if (ft_isspace(line[i]))
		{
			i++;
			if (line[i] && line[i] == '-')
				i++;
		}
		else if (ft_isdigit(line[i]))
		{
			e = 1;
			while (ft_isdigit(line[i]))
			{
				if (line[i] && line[i + 1] && line[i + 2] && line[i] == ',' && line[i + 1] == '0' && (line[i + 2] == 'x' || (line[i + 2] == 'X')))
					i += 3;
				i++;
			}
		}
		else if (!ft_isdigit(line[i]) && !ft_isspace(line[i]))
		{
			printf("%i\n", line[i]);
			return (-1);
		}
		else
			i++;
	}
	if (!e)
		return (1);
	return (0);
}

t_list	*ft_get_lstmap(int fd)
{
	char	*line;
	int		e;
	t_list	*lstmap;

	lstmap = 0;
	line = get_next_line(fd);
	while (line)
	{
		e = ft_check_line(line);
		if (e == 0)
			ft_lstadd_back(&lstmap, ft_lstnew(line));
		if (e == -1)
		{
			ft_lstclear(&lstmap, free);
			write(2, "Map error: content false\n", 25);
			exit(1);
		}
		line = get_next_line(fd);
	}
	return (lstmap);
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
	lstmap = ft_get_lstmap(fd);
	close(fd);
	coor = ft_get_coor(lstmap);
	return (coor);
}
