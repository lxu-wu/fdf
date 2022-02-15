/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:51:57 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/15 18:52:03 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	ft_draw_bg(t_ptr *ptr, int color)
{
	t_cam	cam1;
	t_cam	cam2;

	cam1.x = 0;
	cam2.x = WIDTH;
	cam1.y = 0;
	while (cam1.y <= HEIGHT)
	{
		cam2.y = cam1.y;
		ft_draw_line(cam1, cam2, color, ptr);
		cam1.y++;
	}
}
