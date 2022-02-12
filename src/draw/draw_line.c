#include "../../inc/fdf.h"

void	ft_put_pixel(t_ptr *ptr, long x, long y, int color)//, t_camcoor c1, t_camcoor c2)
{
	int 	pixel_bits;
	int 	size_line;
	int 	endian;
	char	*buffer;
	long	pixel;

	// printf("color = %d\n", color);
	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		buffer = mlx_get_data_addr(ptr->img, &pixel_bits, &size_line, &endian);
		pixel = round((y *  size_line) + (x * 4));
		buffer[pixel] = color;
		buffer[pixel + 1] = (color >> 8);
		buffer[pixel + 2] = (color >> 16);
		buffer[pixel + 3] = (color >> 24);
	}
}

void	ft_draw_line(t_cam c1, t_cam c2, int color, t_ptr *ptr)
{
	long x1=round(c1.x);
	long x2=round(c2.x);
	long y1=round(c1.y);
	long y2=round(c2.y);
	long ex=labs(x2-x1);
	long ey=labs(y2-y1);
	long dx=labs(2 * ex);
	long dy=labs(2 * ey);
	long Dx=ex;
	long Dy=ey;
	long i=0;
	long Xincr=1;
	long Yincr=1;

	// printf("%ld %ld %ld %ld\n", x1, y1, x2, y2);
	if (x1 > x2)
		Xincr = -1;
	if (y1 > y2)
		Yincr = -1;
	if (Dx >= Dy)
	{
		while (i < Dx)
		{
			ft_put_pixel(ptr, x1, y1, color);
			i++;
			x1 += Xincr;
			ex -= dy;
			if (ex < 0)
			{
				y1 += Yincr;
				ex += dx;
			}
		}
	}
	if (Dx <= Dy)
	{
		while (i < Dy)
		{
			ft_put_pixel(ptr, x1, y1, color);
			i++;
			y1 += Yincr;
			ey -= dx;
			if (ey < 0)
			{
				x1 += Xincr;
				ey += dy;
			}
		}
	}
}
