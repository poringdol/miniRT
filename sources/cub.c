/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:30 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/30 07:21:01 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_near	cub(t_cub *cub, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp;

	ft_bzero(&nearest, sizeof(t_near));
	while (cub)
	{
		tmp = intersect_pln(cub->sqr1.pln, cam.xyz, cam1, ray);
		if (tmp.flag2 && (check_triangle(cub->sqr1.tri1, tmp.xyz,
				nearest, cam1) ||
				check_triangle(cub->sqr1.tri2, tmp.xyz, nearest, cam1)))
			nearest = tmp;
		cub = cub->next;
	}
	return (nearest);
}
