/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:33:51 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/16 18:11:38 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_exit(t_data *data)
{
	size_t	i;
	t_coor	*tmp;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			tmp = data->coor[i];
			data->coor[i] = data->coor[i]->next;
			free(tmp);
		}
		i++;
	}
	free(data->coor);
	mlx_clear_window(data->ptr.mlx, data->ptr.win);
	mlx_destroy_window(data->ptr.mlx, data->ptr.win);
	exit(0);
}

int	ft_hook(int key, t_data *data)
{
	static int	v = 0;
	static int	p = 0;

	if (key == 53)
		ft_exit(data);
	else if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		ft_translation(data, key);
		ft_draw_all(data);
	}
	else if (key == 12 || key == 14)
		ft_ori_zoom(data, key);
	else if (key == 15 || key == 3)
		ft_ori_vert(data, key, &v, &p);
	else if (key == 5 || key == 4 || key == 17
		|| key == 16 || key == 11 || key == 45)
		ft_ori_rot(data, key, &v);
	else if (key == 35)
		ft_ori_pro(data, key, &v, &p);
	else if (key == 49)
		ft_ori_reset(data, key, &v, &p);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data.coor = ft_parsing(argv[1]);
		data.ptr = ft_init_ptr();
		data.saved = ft_saved(&data);
		ft_data_reset(&data);
		data.len = ft_coor_len(&data);
		ft_data_reset(&data);
		data.height = ft_coor_height(&data);
		ft_data_reset(&data);
		ft_ttra(&data);
		ft_resize_model(&data);
		ft_take_pro(&data);
		ft_iso(&data);
		ft_cameralize(&data);
		ft_draw_p(&data);
		ft_draw_all_line(&data);
		mlx_hook(data.ptr.win, 2, 0L, ft_hook, &(data));
		mlx_hook(data.ptr.win, 17, 0L, ft_exit, &(data));
		mlx_loop(data.ptr.mlx);
	}
	write(2, "Use one argument\n", 17);
	return (1);
}
