/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:34:55 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/15 19:35:03 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

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
	t_coor	*tmp;

	tmp = coor;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}
