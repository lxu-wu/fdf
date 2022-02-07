#include "../inc/fdf.h"

int	ft_get_color(char *line, char *obase, size_t *i);

int	ft_hook(int key, t_data *data)
{
	long y = 500;
	long x = 500;

	if (key == 53)
		ft_exit(data);
	ft_put_pixel(&data->ptr, x, y, 0x00000000);
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.win, data->ptr.img, 0, 0);
	return (0);
}

int	ft_exit(t_data *data)
{
	
	mlx_clear_window(data->ptr.mlx, data->ptr.win);
	mlx_destroy_window(data->ptr.mlx, data->ptr.win);
	exit(0);
}

t_ptr	ft_init_ptr(void)
{
	t_ptr	ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "TEST");
	ptr.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	return (ptr);
}

void	ft_printcoor(t_coor **coor)
{
	size_t	i;

	i = 0;
	while (coor[i])
	{
		while (coor[i])
		{
			printf("%ld ", (coor[i])->model.z);
			(coor[i]) = (coor[i])->next;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	// data.coor = ft_parsing(argv[1]);
	// data.ptr = ft_init_ptr();

	size_t i = 0;
	printf("%d\n", ft_get_color(ft_word("0xFF    "), "0123456789ABCDEF", &i));

	// printf("%p\n", data.ptr.img);
	// mlx_key_hook ( data.ptr., int (*funct_ptr)(), void *param );
	
	
	// mlx_pixel_put(data.ptr.mlx, data.ptr.win, 500, 500, 0X00FF00FF);
	// mlx_hook(data.ptr.win, 2, 0L, ft_hook, &(data));
	// mlx_hook(data.ptr.win, 17, 0L, ft_exit, &(data));

	// mlx_loop(data.ptr.mlx);
	// ft_printcoor(data.coor);

}

