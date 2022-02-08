#include "../inc/fdf.h"


void	ft_draw_all_line(t_data *data);
int	ft_get_color(char *line, char *obase, size_t *i);

void	ft_data_reset(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		data->coor[i] = ft_coorfirst(data->coor[i]);
		i++;
	}
}

void	ft_translation(t_data *data, int key)
{
	size_t i;

	i = 0;
	if (key == 0)
	{
		while (data->coor[i])
		{
			while (data->coor[i]->next)
			{
				data->coor[i]->cam.x -= 1;
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}
	}
	else if (key == 2)
	{
		while (data->coor[i])
		{
			while (data->coor[i]->next)
			{
				data->coor[i]->cam.x += 1;
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}	
	}
	else if (key == 1)
	{
		while (data->coor[i])
		{
			while (data->coor[i]->next)
			{
				data->coor[i]->cam.y += 1;
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}	
	}
	else if (key == 13)
	{
		while (data->coor[i])
		{
			while (data->coor[i]->next)
			{
				data->coor[i]->cam.y -= 1;
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}
	}
}

int	ft_hook(int key, t_data *data)
{
	char	*buffer;
	int		bit_per_pixel;
	int		size_len;
	int		edian;

	ft_data_reset(data);
	printf("keycode == %d\n", key);
	if (key == 53)
		ft_exit(data);
	else if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		ft_translation(data, key);
		buffer = mlx_get_data_addr(data->ptr.img, &bit_per_pixel, &size_len, &edian);
		buffer = ft_memset(buffer, 0, size_len * WIDTH);
		ft_data_reset(data);
		ft_draw_all_line(data);
	}
	// ft_put_pixel(&data->ptr, x, y, 0x0000FF00);
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
	while (coor[i]->next)
	{
		while (coor[i]->next)
		{
			printf("%ld %ld, ", (coor[i])->cam.x, (coor[i])->cam.y);
			(coor[i]) = (coor[i])->next;
		}
		printf("\n");
		i++;
	}
}

void	ft_draw_all_line(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			if (data->coor[i]->next)
				ft_draw_line(data->coor[i]->cam, data->coor[i]->next->cam, data->coor[i]->color, &data->ptr);
			if (data->coor[i + 1])
				ft_draw_line(data->coor[i]->cam, data->coor[i + 1]->cam, data->coor[i]->color, &data->ptr);
			if (data->coor[i]->next)
				data->coor[i] = data->coor[i]->next;
			i++;
		}
		if (!data->coor[i - 1]->next)
			break ;
		i = 0;
	}
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.win, data->ptr.img, 0, 0);
}

void	ft_draw_all(t_data data)
{
	size_t	i;
	t_data tmp;
	tmp = data;

	i = 0;
	while (tmp.coor[i])
	{
		while (tmp.coor[i])
		{
			ft_put_pixel(&tmp.ptr, tmp.coor[i]->cam.x, tmp.coor[i]->cam.y, 0x00FF00FF);
			(tmp.coor)[i] = (tmp.coor)[i]->next;
		}
		i++;
	}
	mlx_put_image_to_window(data.ptr.mlx, data.ptr.win, data.ptr.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	// t_data	tmp;

	data.coor = ft_parsing(argv[1]);
	// printf("1\n");
	data.ptr = ft_init_ptr();

	// size_t i = 0;

	// printf("%d\n", ft_atoi_base(ft_word("FFFFFFFF"), "0123456789ABCDEF"));
	ft_draw_all_line(&data);
	ft_data_reset(&data);
	// ft_draw_all(data);
	// printf("%p\n", data.ptr.img);
	// mlx_key_hook ( data.ptr., int (*funct_ptr)(), void *param );
	
	// t_cam cam;
	// t_cam cam1;

	// cam1.x = 500;
	// cam1.y = 400;
	// cam.x = 0;
	// cam.y = 200;
	// ft_draw_line(cam, cam1, 0x00FFFFFF, &data.ptr); 
	// mlx_put_image_to_window(data.ptr.mlx, data.ptr.win, data.ptr.img, 0, 0);
	// mlx_pixel_put(data.ptr.mlx, data.ptr.win, 500, 500, 0X00FF00FF);
	mlx_hook(data.ptr.win, 2, 0L, ft_hook, &(data));
	mlx_hook(data.ptr.win, 17, 0L, ft_exit, &(data));

	// ft_printcoor(data.coor);
	mlx_loop(data.ptr.mlx);

}

