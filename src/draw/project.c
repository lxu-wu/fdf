#include "../../inc/fdf.h"

t_cam	ft_project(t_model model, float rad)
{
	t_cam	cam;

	cam.x = (model.x - model.y) * cos(rad);
	cam.y = (model.x + model.y) * sin(rad) - model.z;
	return (cam);
}