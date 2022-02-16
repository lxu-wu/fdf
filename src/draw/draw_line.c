/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:35:20 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/16 14:42:50 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	ft_put_pixel(t_ptr *ptr, long x, long y, int color)
{
	int		pixel_bits;
	int		size_line;
	int		endian;
	char	*buffer;
	long	pixel;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		buffer = mlx_get_data_addr(ptr->img, &pixel_bits, &size_line, &endian);
		pixel = round((y * size_line) + (x * 4));
		buffer[pixel] = color;
		buffer[pixel + 1] = (color >> 8);
		buffer[pixel + 2] = (color >> 16);
		buffer[pixel + 3] = (color >> 24);
	}
}

void	ft_d_init(t_cam c1, t_cam c2, long d[13])
{
	d[0] = round(c1.x);
	d[1] = round(c2.x);
	d[2] = round(c1.y);
	d[3] = round(c2.y);
	d[4] = labs(d[1] - d[0]);
	d[5] = labs(d[3] - d[2]);
	d[6] = labs(2 * d[4]);
	d[7] = labs(2 * d[5]);
	d[8] = d[4];
	d[9] = d[5];
	d[10] = 1;
	d[11] = 1;
	if (d[0] > d[1])
		d[10] = -1;
	if (d[2] > d[3])
		d[11] = -1;
}

void	ft_draw_line1(long d[12], int color, t_ptr *ptr)
{
	size_t	i;

	i = 0;
	while (i < d[8])
	{
		ft_put_pixel(ptr, d[0], d[2], color);
		i++;
		d[0] += d[10];
		d[4] -= d[7];
		if (d[4] < 0)
		{
			d[2] += d[11];
			d[4] += d[6];
		}
	}
}

void	ft_draw_line2(long d[12], int color, t_ptr *ptr)
{
	size_t	i;

	i = 0;
	while (i < d[9])
	{
		ft_put_pixel(ptr, d[0], d[2], color);
		i++;
		d[2] += d[11];
		d[5] -= d[6];
		if (d[5] < 0)
		{
			d[0] += d[10];
			d[5] += d[7];
		}
	}
}

void	ft_draw_line(t_cam c1, t_cam c2, int color, t_ptr *ptr)
{
	long	d[12];

	ft_d_init(c1, c2, d);
	if (d[8] >= d[9])
		ft_draw_line1(d, color, ptr);
	if (d[8] < d[9])
		ft_draw_line2(d, color, ptr);
}
