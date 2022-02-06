#include "../../inc/fdf.h"

void	ft_put_pixel(t_ptr *ptr, long x, long y, int color)//, t_camcoor c1, t_camcoor c2)
{
	int 	pixel_bits;
	int 	size_line;
	int 	endian;
	char	*buffer;
	long	pixel;

	printf("color = %d\n", color);
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

// void	ft_dawline(t_camcoor c1, t_camcoor c2)