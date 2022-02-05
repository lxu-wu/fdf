#include "../../inc/fdf.h"

t_coor	*ft_coornew(t_model model, int color)
{
	t_coor	*coor;

	coor = malloc(sizeof(t_coor));
	if (!coor)
		return (0);
	coor->model = model;
	coor->cam = ft_project(model, ft_rad(45));
	coor->color = color;
	coor->prev = 0;
	coor->next = 0;
	return (coor);
}

t_coor	*ft_coorlast(t_coor *coor)
{
	t_coor *tmp;

	tmp = coor;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_cooradd_back(t_coor **acoor, t_coor *new)
{
	t_coor	*last_elem;

	if (acoor && new)
	{
		if (!*acoor)
			*acoor = new;
		else
		{
			last_elem = ft_coorlast(*acoor);
			new->prev = last_elem;
			last_elem->next = new;
		}
	}
}

void	ft_coorclear(t_coor **coor)
{
	t_coor	*tmp;

	while (*coor)
	{
		tmp = *coor;
		*coor = (*coor)->next;
		free(tmp);
	}
}

