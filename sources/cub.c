/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:30 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 05:56:07 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_near	check_cub(t_cub *cub, t_near nearest, t_near tmp[6], t_xyz cam1)
{
	int		i;

	i = -1;
	while (++i < 6)
	{
		if (tmp[i].flag2 && (check_square(cub->sqr[i], tmp[i].xyz, nearest, cam1)))
			nearest = tmp[i];
	}
	return (nearest);
}

t_near			cub(t_cub *cub, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp[6];
	int		i;

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near) * 6);
	while (cub)
	{
		i = -1;
		while (++i < 6)
		{
			if (scal_product(ray, cub->sqr[i].pln.normal) <= 0)
				tmp[i] = intersect_pln(cub->sqr[i].pln, cam.xyz, cam1, ray);
		}
		nearest = check_cub(cub, nearest, tmp, cam1);
		cub = cub->next;
	}
	return (nearest);
}
