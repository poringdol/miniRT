/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:30 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 17:41:00 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_near	check_pyramid(t_pyr *pyr, t_near nearest,
								t_near tmp[5], t_xyz cam1)
{
	int		i;

	i = 0;
	if (tmp[0].flag2 && check_square(pyr->sqr, tmp[0].xyz, nearest, cam1))
		nearest = tmp[0];
	while (++i < 5)
	{
		if (tmp[i].flag2 &&
			(check_triangle(pyr->tri[i - 1], tmp[i].xyz, nearest, cam1)))
			nearest = tmp[i];
	}
	return (nearest);
}

t_near			pyramid(t_pyr *pyr, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp[5];
	int		i;

	ft_bzero(&nearest, sizeof(t_near));
	while (pyr)
	{
		if (scal_product(ray, pyr->sqr.pln.normal) <= 0)
			tmp[0] = intersect_pln(pyr->sqr.pln, cam.xyz, cam1, ray);
		i = 0;
		while (++i < 5)
		{
			if (scal_product(ray, pyr->tri[i - 1].pln.normal) <= 0)
				tmp[i] = intersect_pln(pyr->tri[i - 1].pln, cam.xyz, cam1, ray);
		}		
		nearest = check_pyramid(pyr, nearest, tmp, cam1);
		pyr = pyr->next;
	}
	return (nearest);
}
