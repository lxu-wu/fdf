#include "../../inc/fdf.h"

t_coor	*ft_coornew(t_model model, int color)
{
	t_coor	*coor;

	coor = malloc(sizeof(t_coor));
	if (!coor)
		return (0);
	coor->model = model;	
	// coor->cam = ft_project(coor->model, ft_rad(30));
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


size_t	ft_coorsize(t_coor *coor)
{
	int		i;
	t_coor	*current;

	if (!coor)
		return (0);
	i = 1;
	current = coor;
	while (current->next != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
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

t_coor	*ft_coorfirst(t_coor *coor)
{
	t_coor *tmp;

	tmp = coor;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

