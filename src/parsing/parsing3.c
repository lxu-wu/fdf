/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:44:02 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/15 20:44:03 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

t_ptr	ft_init_ptr(void)
{
	t_ptr	ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "FDF");
	ptr.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	return (ptr);
}

size_t	ft_coor_len(t_data *data)
{
	size_t	len;
	size_t	tmp;
	size_t	i;

	i = 0;
	len = 0;
	while (data->coor[i])
	{
		tmp = ft_coorsize(data->coor[i++]);
		if (len < tmp)
			len = tmp;
	}
	return (len);
}

size_t	ft_coor_height(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
		i++;
	return (i);
}
