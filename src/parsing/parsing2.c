/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:37:54 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/16 19:53:45 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_check_str(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (c == base[i])
		return (i);
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

int	ft_modelize2(t_model *model, size_t *i, char *line, long *x)
{
	int	color;

	color = 0x00FFFFFF;
	model->x = (*x)++;
	model->z = ft_atoi(line + (*i));
	while (line[*i] && line[*i] != ' ')
	{
		if (line[*i] == ',' && ++(*i))
		{
			color = ft_atoi_base(ft_strupper(ft_word(line + (*i))),
					"0123456789ABCDEF");
			while (line[*i] && line[*i] != ' ')
				(*i)++;
		}
		else
			(*i)++;
	}
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
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (line[i])
		{
			model.y = y;
			color = ft_modelize2(&model, &i, line, &x);
			ft_cooradd_back(&coor, ft_coornew(model, color));
		}
	}
	return (coor);
}
