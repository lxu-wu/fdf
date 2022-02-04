#include "../inc/fdf.h"

int	ft_exit(t_ptr *ptr);


int	ft_hook(int key, t_data *data)
{
	long x = 100;
	long y = 100;

	if (key == 53)
		ft_exit(&data->ptr);
	ft_put_pixel(&data->ptr, x++, y, 0x00FFFFFF);
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.win, data->ptr.img, 0, 0);
	return (0);
}



int	ft_test(int key, t_data *data)
{
	while (g_x < 1000)
		ft_hook(key, data);
	return (1);
}




int	ft_exit(t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.ptr.mlx = mlx_init();
	data.ptr.win = mlx_new_window(data.ptr.mlx, WIDTH, HEIGHT, "TEST");
	data.ptr.img = mlx_new_image(data.ptr.mlx, WIDTH, HEIGHT);
	// printf("%p\n", data.ptr.img);
	// mlx_key_hook ( data.ptr., int (*funct_ptr)(), void *param );
	mlx_pixel_put(data.ptr.mlx, data.ptr.win, 500, 500, 0X00FF00FF);
	mlx_hook(data.ptr.win, 2, 0L, ft_hook, &(data));
	mlx_hook(data.ptr.win, 17, 0L, ft_exit, &(data.ptr));

	mlx_loop(data.ptr.mlx);
}