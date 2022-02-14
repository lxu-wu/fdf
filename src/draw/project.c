#include "../../inc/fdf.h"

void	ft_iso(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->coor[i])
	{
		while (data->coor[i])
		{
			ft_rotz(&data->coor[i]->pro, ft_rad(-45));
			ft_rotx(&data->coor[i]->pro, ft_rad(30));
			data->coor[i] = data->coor[i]->next;
		}
		i++;
	}
	ft_data_reset(data);
}

t_cam	ft_project(t_model model, int mod)
{
	static int		e;
	t_cam	cam;

	if (!e)
		e = 1;
	e *= mod;
	// if (e == 1)
	// {
		// ft_rotz(model, ft_rad(-45));
		// ft_rotx(model, ft_rad(30));
	// }
	// ft_roty(&model, ft_rad(90));
	if (e == 1)
	{
		cam.x = model.x;
		cam.y = -model.z;
	}
	else if (e == -1)
	{
		cam.x = model.x; 
		cam.y = model.y;
	}
	return (cam);
}

void	ft_rotx(t_model *model, float rad)
{
	t_model	new;
	
	new.x = model->x;
	new.z = model->z;
	new.y = model->y;
	model->x = (new.x * 1) + (new.z * 0) + (new.y * 0);
	model->z = (new.x * 0) + (new.z * cos(rad)) + (new.y * -sin(rad));
	model->y = (new.x * 0) + (new.z * sin(rad)) + (new.y * cos(rad));
}

void	ft_rotz(t_model *model, float rad)
{
	t_model	new;

	new.x = model->x;
	new.z = model->z;
	new.y = model->y;
	model->x = (new.x * cos(rad)) + (new.z * 0) + (new.y * sin(rad));
	model->z = (new.x * 0) + (new.z * 1) + (new.y * 0);
	model->y = (new.x * -sin(rad)) + (new.z * 0) + (new.y * cos(rad));
}

void	ft_roty(t_model *model, float rad)
{
	t_model	new;

	new.x = model->x;
	new.z = model->z;
	new.y = model->y;
	model->x = (new.x * cos(rad)) + (new.z * -sin(rad)) + (new.y * 0);
	model->z = (new.x * sin(rad)) + (new.z * cos(rad)) + (new.y * 0);
	model->y = (new.x * 0) + (new.z * 0) + (new.y * 1);
}

// x = 	1 0 		0
// 		0 cos(rad) 	-sin(rad)
// 		0 sin(rad) 	cos(rad)

// z = cos(rad)	0 	sin(rad)
// 	0			1	0
// 	-sin(rad)	0	cos(rad)

// y =		cos(rad) 	-sin(rad)	0
// 		sin(rad) 	cos(rad)	0
// 		0			0			1