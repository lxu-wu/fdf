/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:05:13 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/15 21:08:53 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_ptr;

typedef struct s_model
{
	double	x;
	double	y;
	double	z;
}	t_model;

typedef struct s_cam
{
	double	x;
	double	y;
}	t_cam;

typedef struct s_coor
{
	t_model			model;
	t_cam			cam;
	t_model			pro;
	int				color;
	struct s_coor	*prev;
	struct s_coor	*next;
}	t_coor;

typedef struct s_tra
{
	double	zoom;
	size_t	x;
	size_t	y;
}	t_tra;

typedef struct t_data
{
	t_ptr	ptr;
	t_coor	**coor;
	t_list	*saved;
	t_tra	transfo;
	size_t	len;
	size_t	height;
}	t_data;

void	ft_draw_all(t_data *data);
void	ft_put_pixel(t_ptr *ptr, long x, long y, int color);
int		ft_exit(t_data *data);
void	ft_error(int e);

t_coor	*ft_modelize(char *line, size_t y);
void	ft_extention_valider(char *map);

t_coor	*ft_coornew(t_model model, int color);
t_coor	*ft_coorlast(t_coor *coor);
void	ft_cooradd_back(t_coor **acoor, t_coor *new);
void	ft_coorclear(t_coor **coor);

t_cam	ft_project(t_model model, int mod);
float	ft_rad(float degree);
t_coor	**ft_parsing(char *map);
char	*ft_word(char *str);
char	*ft_strupper(char *str);

void	ft_draw_line(t_cam c1, t_cam c2, int color, t_ptr *ptr);
void	ft_rotx(t_model *model, float rad);
void	ft_rotz(t_model *model, float rad);
void	ft_roty(t_model *model, float rad);

t_coor	*ft_coorfirst(t_coor *coor);
t_list	*ft_saved(t_data *data);
void	ft_data_reset(t_data *data);
size_t	ft_coorsize(t_coor *coor);

void	ft_draw_bg(t_ptr *ptr, int color);
void	ft_iso(t_data *data);
void	ft_data_reset(t_data *data);
void	ft_ttra(t_data *data);
void	ft_resize_model(t_data *data);

void	ft_take_pro(t_data *data);
void	ft_cameralize(t_data *data);
void	ft_draw_p(t_data *data);
void	ft_draw_all_line(t_data *data);
void	ft_draw_all(t_data *data);

void	ft_translation(t_data *data, int key);
void	ft_zoom(t_data *data, int key);
void	ft_vertic(t_data *data, int key);
void	ft_rot(t_data *data, int key);

void	ft_zoom1(t_data *data);
void	ft_zoom2(t_data *data);

void	ft_upper(t_data *data);
void	ft_lower(t_data *data);

void	ft_rot_all(t_data *data, float degree, void (*rot)(t_model *, float));

t_ptr	ft_init_ptr(void);
size_t	ft_coor_len(t_data *data);
size_t	ft_coor_height(t_data *data);

void	ft_ori_zoom(t_data *data, int key);
void	ft_ori_vert(t_data *data, int key, int *v, int *p);
void	ft_ori_rot(t_data *data, int key, int *v);
void	ft_ori_pro(t_data *data, int key, int *v, int *p);
void	ft_ori_reset(t_data *data, int key, int *v, int *p);

#endif
