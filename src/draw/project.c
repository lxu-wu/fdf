#include "../../inc/fdf.h"

t_cam	ft_project(t_model model, float rad)
{
	t_cam	cam;

	cam.x = ((model.x - model.y) * 50) * cos(rad) + 500;
	cam.y = (((model.x + model.y) * 50) * sin(rad) - (model.z * 20)) + 200;
	return (cam);
}

void	ft_rotx(t_model *model, float rad)
{
	model->x = round((model->x * 1) + (model->x * 0) + (model->x * 0));
	model->z = round((model->z * 0) + (model->z * cos(rad)) + (model->z * -sin(rad)));
	model->y = round((model->y * 0) + (model->y * sin(rad)) + (model->y * cos(rad)));
}

void	ft_rotz(t_model *model, float rad)
{
	model->x = round((model->x * cos(rad)) + (model->x * 0) + (model->x * sin(rad)));
	model->z = (model->z * 0) + (model->z * 1) + (model->z * 0);
	model->y = round((model->y * -sin(rad)) + (model->y * 0) + (model->y * cos(rad)));
}

void	ft_roty(t_model *model, float rad)
{
	model->x = round((model->x * cos(rad)) + (model->x * -sin(rad)) + (model->x * 0));
	model->z = round((model->z * sin(rad)) + (model->z * cos(rad)) + (model->z * 0));
	model->y = round((model->y * 0) + (model->y * 0) + (model->y * 1));
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