/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:59:41 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/15 20:31:35 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	ft_translation(t_data *data, int key)
{
	size_t	i;

	i = 0;
	if (key == 0)
		data->transfo.x -= 1;
	else if (key == 2)
		data->transfo.x += 1;
	else if (key == 1)
		data->transfo.y += 1;
	else if (key == 13)
		data->transfo.y -= 1;
	ft_data_reset(data);
}

void	ft_zoom(t_data *data, int key)
{
	if (key == 12)
		ft_zoom1(data);
	if (key == 14)
		ft_zoom2(data);
	ft_data_reset(data);
}

void	ft_vertic(t_data *data, int key)
{
	if (key == 3)
		ft_upper(data);
	if (key == 15)
		ft_lower(data);
	ft_data_reset(data);
}

void	ft_rot(t_data *data, int key)
{
	if (key == 5)
		ft_rot_all(data, 1, ft_rotz);
	else if (key == 4)
		ft_rot_all(data, -1, ft_rotz);
	else if (key == 17)
		ft_rot_all(data, 1, ft_rotx);
	else if (key == 16)
		ft_rot_all(data, -1, ft_rotx);
	else if (key == 11)
		ft_rot_all(data, 1, ft_roty);
	else if (key == 45)
		ft_rot_all(data, -1, ft_roty);
	ft_data_reset(data);
}
