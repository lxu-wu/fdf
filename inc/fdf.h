#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

#include <stdio.h>

# define WIDTH 1000
# define HEIGHT 800

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_ptr;

typedef	struct s_model
{
	long	x;
	long	y;
	long	z;
}	t_model;

typedef	struct s_cam
{
	long	x;
	long	y;
}	t_cam;

typedef struct s_coor
{
	t_model			model;
	t_cam			cam;
	int				color;
	struct s_coor	*prev;
	struct s_coor	*next;
}	t_coor;

typedef struct t_data
{
	t_ptr	ptr;
	t_coor	**coor;
}	t_data;

void	ft_put_pixel(t_ptr *ptr, long x, long y, int color);
int		ft_exit(t_data *data);
void	ft_error(int e);

t_coor	*ft_coornew(t_model model, int color);
t_coor	*ft_coorlast(t_coor *coor);
void	ft_cooradd_back(t_coor **acoor, t_coor *new);
void	ft_coorclear(t_coor **coor);

t_cam	ft_project(t_model model, float rad);

float	ft_rad(float degree);
t_coor	**ft_parsing(char *map);
char	*ft_word(char *str);

#endif