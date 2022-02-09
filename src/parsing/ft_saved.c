#include "../../inc/fdf.h"

t_list	*ft_saved(t_data *data)
{
	t_list	*lst;
	size_t	i;

	lst = 0;
	i = 0;
	while (data->coor[i])
		ft_lstadd_back(&lst, ft_lstnew(data->coor[i++]));
	return (lst);
}