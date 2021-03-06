/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saved.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:38:11 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/15 16:48:23 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
