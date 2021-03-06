/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu-wu <lxu-wu@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:07:54 by lxu-wu            #+#    #+#             */
/*   Updated: 2022/02/15 20:30:49 by lxu-wu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_error(int e)
{
	if (e == 1)
		write(2, "Error\n", 6);
	else if (e == 2)
		write(2, "Malloc Failed\n", 14);
	else if (e == 3)
		perror("open: ");
	else if (e == 4)
		write(2, "Invalide color or use prefix 0x/0X\n", 35);
	else
		printf("in ft_error %d\n", e);
	exit(1);
}
