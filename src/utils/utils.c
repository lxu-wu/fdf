/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:32:01 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/16 19:54:37 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

float	ft_rad(float degree)
{
	float	rad;

	rad = (degree / 180) * M_PI;
	return (rad);
}

char	*ft_word(char *str)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		ft_error(2);
	ft_strlcpy(word, str, i + 1);
	return (word);
}

char	*ft_strupper(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (str);
}

void	ft_data_reset(t_data *data)
{
	size_t	i;
	t_list	*tmp;
	size_t	size;

	i = 0;
	tmp = data->saved;
	while (tmp)
	{
		data->coor[i++] = tmp->content;
		tmp = tmp->next;
	}
}
