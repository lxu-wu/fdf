/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:47:59 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/15 21:04:44 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	ft_ori_zoom(t_data *data, int key)
{
	ft_zoom(data, key);
	ft_draw_all(data);
}

void	ft_ori_vert(t_data *data, int key, int *v, int *p)
{
	if (*v == 0)
	{
		ft_vertic(data, key);
		ft_take_pro(data);
		if (*p == 0)
			ft_iso(data);
		ft_draw_all(data);
	}
	else
	{
		if (HEIGHT >= 30 && WIDTH >= 300)
		{
			mlx_put_image_to_window(data->ptr.mlx, data->ptr.win,
				data->ptr.img, 0, 0);
			mlx_string_put(data->ptr.mlx, data->ptr.win, WIDTH / 2 - 140,
				HEIGHT / 10, 0x00FF0000, "Press space or p to reset");
		}
	}
}

void	ft_ori_rot(t_data *data, int key, int *v)
{
	ft_rot(data, key);
	ft_draw_all(data);
	*v = 1;
}

void	ft_ori_pro(t_data *data, int key, int *v, int *p)
{
	t_model	model;

	ft_ttra(data);
	ft_take_pro(data);
	if (*p == 0)
	{
		ft_project(model, -1);
		*p = 1;
	}
	else if (*p == 1)
	{
		ft_project(model, -1);
		ft_iso(data);
		*p = 0;
	}
	ft_draw_all(data);
		*v = 0;
}

void	ft_ori_reset(t_data *data, int key, int *v, int *p)
{
	ft_ttra(data);
	ft_take_pro(data);
	ft_data_reset(data);
	if (*p == 0)
		ft_iso(data);
	ft_draw_all(data);
	*v = 0;
}
