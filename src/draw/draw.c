/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:49:44 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/15 20:33:39 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	ft_draw_p(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			ft_put_pixel(&data->ptr, data->coor[i]->cam.x,
				data->coor[i]->cam.y, data->coor[i]->color);
			(data->coor)[i] = (data->coor)[i]->next;
		}
		i++;
	}
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.win, data->ptr.img, 0, 0);
	ft_data_reset(data);
}

void	ft_draw_all_line(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			if (data->coor[i]->next)
				ft_draw_line(data->coor[i]->cam, data->coor[i]->next->cam,
					data->coor[i]->color, &data->ptr);
			if (data->coor[i + 1])
				ft_draw_line(data->coor[i]->cam, data->coor[i + 1]->cam,
					data->coor[i]->color, &data->ptr);
			data->coor[i] = data->coor[i]->next;
			i++;
		}
		i = 0;
	}
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.win, data->ptr.img, 0, 0);
	ft_data_reset(data);
}

void	ft_draw_all(t_data *data)
{
	mlx_clear_window(data->ptr.mlx, data->ptr.win);
	ft_draw_bg(&data->ptr, 0);
	ft_cameralize(data);
	ft_draw_p(data);
	ft_draw_all_line(data);
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.win, data->ptr.img, 0, 0);
}
