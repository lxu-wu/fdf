/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:31:47 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/16 16:37:22 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	ft_ttra(t_data *data)
{
	data->transfo.x = WIDTH / 2;
	data->transfo.y = HEIGHT / 2;
	data->transfo.zoom = 1;
}

void	ft_resize_model(t_data *data)
{
	size_t	i;
	size_t	dy;
	size_t	dx;

	dy = data->height / 2;
	dx = data->len / 2;
	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			data->coor[i]->model.x -= dx;
			data->coor[i]->model.x *= (double)HEIGHT / data->len;
			data->coor[i]->model.y -= dy;
			data->coor[i]->model.y *= (double)HEIGHT / data->len;
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}
	ft_data_reset(data);
}

void	ft_take_pro(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			data->coor[i]->pro.x = data->coor[i]->model.x * data->transfo.zoom;
			data->coor[i]->pro.z = data->coor[i]->model.z * data->transfo.zoom;
			data->coor[i]->pro.y = data->coor[i]->model.y * data->transfo.zoom;
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}
	ft_data_reset(data);
}

void	ft_cameralize(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			data->coor[i]->cam = ft_project(data->coor[i]->pro, 1);
			data->coor[i]->cam.x += data->transfo.x;
			data->coor[i]->cam.y += data->transfo.y;
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}
	ft_data_reset(data);
}
