/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:30:57 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/16 17:58:58 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	ft_zoom1(t_data *data)
{
	size_t	i;

	i = 0;
	data->transfo.zoom *= 1.01;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			data->coor[i]->pro.x *= 1.01;
			data->coor[i]->pro.y *= 1.01;
			data->coor[i]->pro.z *= 1.01;
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}	
}

void	ft_zoom2(t_data *data)
{
	size_t	i;

	i = 0;
	data->transfo.zoom /= 1.01;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			data->coor[i]->pro.x /= 1.01;
			data->coor[i]->pro.y /= 1.01;
			data->coor[i]->pro.z /= 1.01;
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}	
}

void	ft_upper(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			if (data->coor[i]->model.z)
				data->coor[i]->model.z /= 1.1;
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}	
}

void	ft_lower(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			if (data->coor[i]->model.z)
				data->coor[i]->model.z *= 1.1;
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}
}

void	ft_rot_all(t_data *data, float degree, void (*rot)(t_model *, float))
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			rot(&data->coor[i]->pro, ft_rad(degree));
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}
}
