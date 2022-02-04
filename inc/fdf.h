#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

#include <stdio.h>


# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_ptr;

typedef	struct s_modelcoor
{
	long	x;
	long	y;
	long	z;
}	t_modelcoor;

typedef	struct s_camcoor
{
	long	x;
	long	y;
}	t_camcoor;

typedef struct s_coor
{
	t_modelcoor		model;
	t_camcoor		cam;
	struct s_coor	*prev;
	struct s_coor	*next;
}	t_coor;

typedef struct t_data
{
	t_ptr	ptr;
	t_coor	*coor;
}	t_data;

void	ft_put_pixel(t_ptr *ptr, long x, long y, int color);
int		ft_exit(t_ptr *ptr);

#endif