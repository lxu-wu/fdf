#include "../../inc/fdf.h"

float	ft_rad(float degree)
{
	float	rad;

	rad = (degree / 180) * M_PI;
	return (rad);
}