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
	if (tmp[0].flag2 && (check_triangle(cub->sqr[0].tri1, tmp[0].xyz, nearest,
		cam1) || check_triangle(cub->sqr[0].tri2, tmp[0].xyz, nearest, cam1)))
		nearest = tmp[0];
	if (tmp[1].flag2 && (check_triangle(cub->sqr[1].tri1, tmp[1].xyz, nearest,
		cam1) || check_triangle(cub->sqr[1].tri2, tmp[1].xyz, nearest, cam1)))
		nearest = tmp[1];
	if (tmp[2].flag2 && (check_triangle(cub->sqr[2].tri1, tmp[2].xyz, nearest,
		cam1) || check_triangle(cub->sqr[2].tri2, tmp[2].xyz, nearest, cam1)))
		nearest = tmp[2];
	if (tmp[3].flag2 && (check_triangle(cub->sqr[3].tri1, tmp[3].xyz, nearest,
		cam1) || check_triangle(cub->sqr[3].tri2, tmp[3].xyz, nearest, cam1)))
		nearest = tmp[3];
	if (tmp[4].flag2 && (check_triangle(cub->sqr[4].tri1, tmp[4].xyz, nearest,
		cam1) || check_triangle(cub->sqr[4].tri2, tmp[4].xyz, nearest, cam1)))
		nearest = tmp[4];
	if (tmp[5].flag2 && (check_triangle(cub->sqr[5].tri1, tmp[5].xyz, nearest,
		cam1) || check_triangle(cub->sqr[5].tri2, tmp[5].xyz, nearest, cam1)))
		nearest = tmp[5];
	return (nearest);
}

t_near			cub(t_cub *cub, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp[6];

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near) * 6);
	while (cub)
	{
		if (scal_product(ray, cub->sqr[0].pln.normal) <= 0)
			tmp[0] = intersect_pln(cub->sqr[0].pln, cam.xyz, cam1, ray);
		if (scal_product(ray, cub->sqr[1].pln.normal) <= 0)
			tmp[1] = intersect_pln(cub->sqr[1].pln, cam.xyz, cam1, ray);
		if (scal_product(ray, cub->sqr[2].pln.normal) <= 0)
			tmp[2] = intersect_pln(cub->sqr[2].pln, cam.xyz, cam1, ray);
		if (scal_product(ray, cub->sqr[3].pln.normal) <= 0)
			tmp[3] = intersect_pln(cub->sqr[3].pln, cam.xyz, cam1, ray);
		if (scal_product(ray, cub->sqr[4].pln.normal) <= 0)
			tmp[4] = intersect_pln(cub->sqr[4].pln, cam.xyz, cam1, ray);
		if (scal_product(ray, cub->sqr[5].pln.normal) <= 0)
			tmp[5] = intersect_pln(cub->sqr[5].pln, cam.xyz, cam1, ray);
		nearest = check_cub(cub, nearest, tmp, cam1);
		cub = cub->next;
	}
	return (nearest);
}
