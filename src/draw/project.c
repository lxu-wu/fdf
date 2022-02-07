#include "../../inc/fdf.h"

t_cam	ft_project(t_model model, float rad)
{
	t_cam	cam;

	cam.x = (model.x - model.y) * cos(rad) * 100 + 500;
	cam.y = ((model.x + model.y) * sin(rad) - model.z) * 100 + 200;
	return (cam);
}

void	ft_rotx(t_model *model, float rad)
{
	model->x = round((model->x * 1) + (model->x * 0) + (model->x * 0));
	model->z = round(((float)model->z * 0) + ((float)model->z * cos(rad)) + ((float)model->z * -sin(rad)));
	model->y = round((float)(model->y * 0) + (float)(model->y * sin(rad)) + (float)(model->y * cos(rad)));
}

void	ft_rotz(t_model *model, float rad)
{
	model->x = round(((float)model->x * cos(rad)) + (float)(model->x * 0) + ((float)model->x * sin(rad)));
	model->z = (model->z * 0) + (model->z * 1) + (model->z * 0);
	model->y = round(((float)model->y * -sin(rad)) + (float)(model->y * 0) + ((float)model->y * cos(rad)));
}

void	ft_roty(t_model *model, float rad)
{
	model->x = round(((float)model->x * cos(rad)) + ((float)model->x * -sin(rad)) + (float)(model->x * 0));
	model->z = round(((float)model->z * sin(rad)) + ((float)model->z * cos(rad)) + (float)(model->z * 0));
	model->y = round(((float)model->y * 0) + ((float)model->y * 0) + (float)(model->y * 1));
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