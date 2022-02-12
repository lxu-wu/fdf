#include "../inc/fdf.h"

void	ft_cameralize(t_data *data);
void	ft_printcoor(t_coor **coor)
{
	size_t	i;

	i = 0;
	while (coor[i]->next)
	{
		while (coor[i]->next)
		{
			printf("%f %f, ", (coor[i])->cam.x, (coor[i])->cam.y);
			(coor[i]) = (coor[i])->next;
		}
		printf("\n");
		i++;
	}
}

void	ft_draw_all_line(t_data *data);
int	ft_get_color(char *line, char *obase, size_t *i);

void	ft_data_reset(t_data *data)
{
	size_t	i;
	t_list	*tmp;
	size_t	size;

	i = 0;
	tmp = data->saved;
	while (tmp)
	{
		data->coor[i++] = tmp->content;
		tmp = tmp->next;
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
			while (data->coor[i])
			{
				data->coor[i]->model.x -= 1;
				data->coor[i]->model.y += 1;
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}
	}
	else if (key == 2)
	{
		while (data->coor[i])
		{
			while (data->coor[i])
			{
				data->coor[i]->model.x += 1;
				data->coor[i]->model.y -= 1;
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}	
	}
	else if (key == 1)
	{
		while (data->coor[i])
		{
			while (data->coor[i])
			{
				data->coor[i]->model.x += 1;
				data->coor[i]->model.y += 1;
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}	
	}
	else if (key == 13)
	{
		while (data->coor[i])
		{
			while (data->coor[i])
			{
				data->coor[i]->model.x -= 1;
				data->coor[i]->model.y -= 1;
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}
	}
}

void	ft_zoom(t_data *data, int key)
{
	size_t	i;

	i = 0;
	if (key == 12)
	{
		while (data->coor[i])
		{
			while (data->coor[i])
			{
				data->coor[i]->model.x *= 1.01;
				data->coor[i]->model.y *= 1.01;
				data->coor[i]->model.z *= 1.01;
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}	
	}
	if (key == 14)
	{
		// printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		while (data->coor[i])
		{
			while (data->coor[i])
			{
				data->coor[i]->model.x /= 1.01;
				data->coor[i]->model.y /= 1.01;
				data->coor[i]->model.z /= 1.01;
				// printf("%f,", data->coor[i]->cam.x);
				// printf("%f\n", data->coor[i]->cam.y);
				data->coor[i] = data->coor[i]->next;
			}
			// printf("\n");
			i++;
		}	
	}
}

void	ft_vertic(t_data *data, int key)
{
	size_t	i;

	i = 0;
	if (key == 3)
	{
		while (data->coor[i])
		{
			while (data->coor[i])
			{
				if (data->coor[i]->model.z)
					data->coor[i]->model.z /= 1.2;
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}	
	}
	if (key == 15)
	{
		// printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		while (data->coor[i])
		{
			while (data->coor[i])
			{
				if (data->coor[i]->model.z)
					data->coor[i]->model.z *= 1.2;
				// printf("%f,", data->coor[i]->cam.x);
				// printf("%f\n", data->coor[i]->cam.y);
				data->coor[i] = data->coor[i]->next;
			}
			// printf("\n");
			i++;
		}	
	}
}

void ft_rot(t_data *data, int key)
{
	size_t	i;

	i = 0;
	if (key == 5)
	{
		while (data->coor[i])
		{
			while (data->coor[i])
			{
				// printf("%f %f %f\n", data->coor[i]->model.x, data->coor[i]->model.z, data->coor[i]->model.y);
				ft_rotz(&data->coor[i]->model, ft_rad(1));
				// printf("%f %f %f\n", data->coor[i]->model.x, data->coor[i]->model.z, data->coor[i]->model.y);
				data->coor[i] = data->coor[i]->next;
			}
			i++;
		}
	}
	if (key == 4)
	{
		while (data->coor[i])
		{
			while (data->coor[i])
			{
				ft_rotz(&data->coor[i]->model, ft_rad(-1));
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

	printf("keycode == %d\n", key);
	if (key == 53)
		ft_exit(data);
	else if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		ft_data_reset(data);
		ft_translation(data, key);
		buffer = mlx_get_data_addr(data->ptr.img, &bit_per_pixel, &size_len, &edian);
		buffer = ft_memset(buffer, 0, size_len * WIDTH);
		ft_data_reset(data);
		ft_cameralize(data);
		ft_draw_all_line(data);
	}
	else if (key == 12 || key == 14)
	{
		ft_data_reset(data);
		ft_zoom(data, key);
		buffer = mlx_get_data_addr(data->ptr.img, &bit_per_pixel, &size_len, &edian);
		buffer = ft_memset(buffer, 0, size_len * WIDTH);
		ft_data_reset(data);
		ft_cameralize(data);
		ft_draw_all_line(data);
	}
	else if (key == 15 || key == 3)
	{
		ft_data_reset(data);
		ft_vertic(data, key);
		buffer = mlx_get_data_addr(data->ptr.img, &bit_per_pixel, &size_len, &edian);
		buffer = ft_memset(buffer, 0, size_len * WIDTH);
		ft_data_reset(data);
		ft_cameralize(data);
		ft_draw_all_line(data);
	}
	else if (key == 5 || key == 4)
	{
		ft_data_reset(data);
		ft_rot(data, key);
		buffer = mlx_get_data_addr(data->ptr.img, &bit_per_pixel, &size_len, &edian);
		buffer = ft_memset(buffer, 0, size_len * WIDTH);
		ft_data_reset(data);
		ft_cameralize(data);
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
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "FDF");
	ptr.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	return (ptr);
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
			data->coor[i] = data->coor[i]->next;
			i++;
		}
		i = 0;
	}
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.win, data->ptr.img, 0, 0);
}

void	ft_draw_all(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			ft_put_pixel(&data->ptr, data->coor[i]->cam.x, data->coor[i]->cam.y, data->coor[i]->color);
			printf("%f ", data->coor[i]->cam.x);
			(data->coor)[i] = (data->coor)[i]->next;
		}
		i++;
	}
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.win, data->ptr.img, 0, 0);
}


size_t	ft_coor_len(t_data *data)
{
	size_t	len;
	size_t	tmp;
	size_t	i;

	i = 0;
	len = 0;
	while (data->coor[i])
	{
		tmp = ft_coorsize(data->coor[i++]);
		if (len < tmp)
			len = tmp;
	}
	return (len);
}

size_t	ft_coor_height(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
		i++;
	return (i);
}


void	ft_resize_model(t_data *data)
{
	size_t	i;
	size_t	dy;
	size_t	dx;

	dy = data->height / 2;
	dx = data->len / 2;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			data->coor[i]->model.x -= dx;
			data->coor[i]->model.x *= HEIGHT / data->len;
			data->coor[i]->model.y -= dy;
			data->coor[i]->model.y *= HEIGHT / data->len;
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}
	// becontinue
}

void	ft_cameralize(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			data->coor[i]->pro.x = data->coor[i]->model.x * data->transfo.zoom;
			data->coor[i]->pro.z = data->coor[i]->model.z * data->transfo.zoom;
			data->coor[i]->pro.y = data->coor[i]->model.y * data->transfo.zoom;
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}
	ft_data_reset(data);
	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			data->coor[i]->cam = ft_project(data->coor[i]->pro, data->transfo, ft_rad(30), 1);
			data->coor[i]->cam.x += data->transfo.x;
			data->coor[i]->cam.y += data->transfo.y;
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}
	ft_data_reset(data);
}

void	ft_ttra(t_data *data)
{
	data->transfo.rx = 0;
	data->transfo.rz = 0;
	data->transfo.ry = 0;
	data->transfo.x = WIDTH / 2;
	data->transfo.y = HEIGHT / 2;
	data->transfo.zoom = 1;
}

int	main(int argc, char **argv)
{
	t_data	data;
	// t_data	tmp;

	data.coor = ft_parsing(argv[1]);
	// printf("1\n");
	data.ptr = ft_init_ptr();
	data.saved = ft_saved(&data);
	ft_data_reset(&data);



	data.len = ft_coor_len(&data);
	ft_data_reset(&data);


	data.height = ft_coor_height(&data);
	ft_data_reset(&data);

	ft_ttra(&data);

	ft_resize_model(&data);
	ft_data_reset(&data);

	
	ft_cameralize(&data);
	// size_t i = 0;
	// printf("%d\n", ft_atoi_base(ft_word("FFFFFFFF"), "0123456789ABCDEF"));
	ft_draw_all(&data);
	// ft_data_reset(&data);
	// ft_draw_all_line(&data);
	// ft_data_reset(&data);
	// ft_printcoor(data.coor);
	// printf("%p\n", data.ptr.img);
	// mlx_key_hook ( data.ptr., int (*funct_ptr)(), void *param );
	
	// t_cam cam;
	// t_cam cam1;

	// cam1.x = 10;
	// cam1.y = 10;
	// cam.x = 200;
	// cam.y = 200;
	// ft_draw_line(cam, cam1, 0x00FFFFFF, &data.ptr);
	// mlx_put_image_to_window(data.ptr.mlx, data.ptr.win, data.ptr.img, 0, 0);
	// mlx_put_image_to_window(data.ptr.mlx, data.ptr.win, data.ptr.img, 0, 0);
	// mlx_pixel_put(data.ptr.mlx, data.ptr.win, 500, 500, 0X00FF00FF);

	// mlx_hook(data.ptr.win, 2, 0L, ft_hook, &(data));
	// mlx_hook(data.ptr.win, 17, 0L, ft_exit, &(data));
	// ft_printcoor(data.coor);
	mlx_loop(data.ptr.mlx);

}

