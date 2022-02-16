/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:08:44 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/16 19:54:21 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

t_coor	**ft_get_coor(t_list *lstmap)
{
	t_coor	**coor;
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	coor = malloc(sizeof(t_coor *) * (ft_lstsize(lstmap) + 1));
	if (!coor)
		ft_error(2);
	while (lstmap)
	{
		coor[i] = ft_modelize(lstmap->content, i);
		lstmap = ft_next(lstmap);
		i++;
	}
	coor[i] = 0;
	return (coor);
}

void	ft_check_line2(int *e, size_t *i, char *line)
{
	*e = 1;
	while (ft_isdigit(line[*i]))
	{
		(*i)++;
		if (line[*i] && line[(*i) + 1] && line[(*i) + 2]
			&& line[*i] == ',' && line[(*i) + 1] == '0'
			&& (line[(*i) + 2] == 'x' || (line[(*i) + 2] == 'X')))
		{
			(*i) += 3;
			while (line[*i] && !ft_isspace(line[*i]))
				(*i)++;
		}
	}
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
		if (ft_isspace(line[i]) && ++i)
		{
			if (line[i] && line[i] == '-')
				i++;
		}
		else if (ft_isdigit(line[i]))
			ft_check_line2(&e, &i, line);
		else if (!ft_isdigit(line[i]) && !ft_isspace(line[i]))
			return (-1);
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
