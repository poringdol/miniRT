/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:30 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/02 04:57:07 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_near	check_pyramid(t_pyr *pyr, t_near nearest,
								t_near tmp[5], t_xyz cam1)
{
	if (tmp[0].flag2 && (check_triangle(pyr->sqr.tri1, tmp[0].xyz, nearest,
		cam1) || check_triangle(pyr->sqr.tri2, tmp[0].xyz, nearest, cam1)))
		nearest = tmp[0];
	if (tmp[1].flag2 && (check_triangle(pyr->tri1, tmp[1].xyz, nearest, cam1)))
		nearest = tmp[1];
	if (tmp[2].flag2 && (check_triangle(pyr->tri2, tmp[2].xyz, nearest, cam1)))
		nearest = tmp[2];
	if (tmp[3].flag2 && (check_triangle(pyr->tri3, tmp[3].xyz, nearest, cam1)))
		nearest = tmp[3];
	if (tmp[4].flag2 && (check_triangle(pyr->tri4, tmp[4].xyz, nearest, cam1)))
		nearest = tmp[4];
	return (nearest);
}

t_near			pyramid(t_pyr *pyr, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp[5];

	ft_bzero(&nearest, sizeof(t_near));
	while (pyr)
	{
		if (scal_product(ray, pyr->sqr.pln.normal) <= 0)
			tmp[0] = intersect_pln(pyr->sqr.pln, cam.xyz, cam1, ray);
		if (scal_product(ray, pyr->tri1.pln.normal) <= 0)
			tmp[1] = intersect_pln(pyr->tri1.pln, cam.xyz, cam1, ray);
		if (scal_product(ray, pyr->tri2.pln.normal) <= 0)
			tmp[2] = intersect_pln(pyr->tri2.pln, cam.xyz, cam1, ray);
		if (scal_product(ray, pyr->tri3.pln.normal) <= 0)
			tmp[3] = intersect_pln(pyr->tri3.pln, cam.xyz, cam1, ray);
		if (scal_product(ray, pyr->tri4.pln.normal) <= 0)
			tmp[4] = intersect_pln(pyr->tri4.pln, cam.xyz, cam1, ray);
		nearest = check_pyramid(pyr, nearest, tmp, cam1);
		pyr = pyr->next;
	}
	return (nearest);
}
