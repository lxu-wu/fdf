#include "../../inc/fdf.h"

void	ft_put_pixel(t_ptr *ptr, long x, long y, int color)//, t_camcoor c1, t_camcoor c2)
{
	int 	pixel_bits;
	int 	size_line;
	int 	endian;
	char	*buffer;
	long	pixel;

	// printf("color = %d\n", color);
	if (x <= WIDTH && y <= HEIGHT)
	{
		buffer = mlx_get_data_addr(ptr->img, &pixel_bits, &size_line, &endian);
		pixel = (y *  size_line)+ (x * 4);
		buffer[pixel + 0] = color;
		buffer[pixel + 1] = (color >> 8);
		buffer[pixel + 2] = (color >> 16);
		buffer[pixel + 3] = (color >> 24);
	}
}

void	ft_draw_line(t_cam c1, t_cam c2, int color, t_ptr *ptr)
{
	long	e[2];
	long	d[2];
	long	incr[2];
	size_t	i;

	incr[0] = 1;
	incr[1] = 1;
	if (c1.x > c2.x)
		incr[0] = -1;
	if (c1.y > c1.y)
		incr[1] = -1;
	i = 0;
	e[0] = labs(c2.x - c1.x);
	e[1] = labs(c2.y - c1.y);
	d[0] = 2 * e[0];
	d[1] = 2 * e[1];
	if (e[0] > e[1])
	{
		while (i <= e[0])
		{
			ft_put_pixel(ptr, c1.x, c1.y, color);
			i++;
			c1.x += incr[0];
			e[0] -= d[1];
		}
		if (e[0] < 0)
		{
			c1.y += incr[1];
			e[0] += d[0];
		}
	}
	else if (e[0] < e[1])
	{
		while (i <= e[1])
		{
			ft_put_pixel(ptr, c1.x, c1.y, color);
			i++;
			c1.y += incr[1];
			e[1] -= d[0];
		}
		if (e[1] < 0)
		{
			c1.x += incr[0];
			e[1] += d[1];
		}
	}
}
