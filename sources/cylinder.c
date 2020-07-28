/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:08:15 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:08:36 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		check_plane(t_cyl cyl, t_near *res,\
							t_xyz cam, t_xyz cam1)
{
	t_near	tmp;
	t_near	tmp1;
	t_pln	pln;
	t_pln	pln1;

	ft_bzero(&pln, sizeof(t_pln));
	pln.orient = cyl.orient;
	pln.xyz = cyl.o;
	pln1.orient = cyl.orient;
	pln1.xyz = cyl.o1;
	tmp = intersect_pln(pln, cam, cam1, res->normal);
	tmp1 = intersect_pln(pln1, cam, cam1, res->normal);
	if (vect_len(vect_cord(tmp.xyz, cyl.o)) <= cyl.diameter / 2)
		res->normal = f_normal(pln.orient, pln.xyz, cam);
	else if (vect_len(vect_cord(tmp1.xyz, cyl.o1)) <= cyl.diameter / 2)
		res->normal = f_normal(pln1.orient, pln1.xyz, cam);
	else
		res->flag2 = 0;
	res->flag = 0;
}

static int		cut_cyl(t_cyl cyl, t_near *res, t_xyz ray)
{
	res->normal = ray;
	if (scal_product(cyl.orient, vect_cord(cyl.o, res->xyz)) < 0)
		res->flag2 = 1;
	if (res->flag && scal_product(cyl.orient, vect_cord(cyl.o1, res->xyz)) > 0)
		res->flag2 = 1;
	return ((int)res->flag2);
}

static t_canv	sin_cos(t_cyl *cyl)
{
	t_canv	canv;

	canv.sin_b = cyl->orient.z;
	canv.cos_b = sqrt(fabs(1 - pow(canv.sin_b, 2)));
	canv.cos_a = (canv.cos_b != 0) ? (cyl->orient.x / canv.cos_b) : 0;
	canv.sin_a = (canv.cos_b != 0) ? (cyl->orient.y / canv.cos_b) : canv.sin_b;
	cyl->o1.x = cyl->o.x + cyl->height * canv.cos_b * canv.cos_a;
	cyl->o1.y = cyl->o.y + cyl->height * canv.cos_b * canv.sin_a;
	cyl->o1.z = cyl->o.z + cyl->height * canv.sin_b;
	return (canv);
}

t_near			intersect_cyl(t_cyl *cyl, t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near	res;
	t_util	var;
	t_canv	canv;

	ft_bzero(&res, sizeof(t_near));
	ft_bzero(&var, sizeof(t_util));
	canv = sin_cos(cyl);
	if (ray.x)
	{
		var = substitution_cyl1(*cyl, cam, ray, canv);
		res = solution_cyl1(*cyl, var, cam);
	}
	else if (ray.y)
	{
		var = substitution_cyl2(*cyl, cam, ray, canv);
		res = solution_cyl2(*cyl, var, cam);
	}
	else
	{
		var = substitution_cyl3(*cyl, cam, canv);
		res = solution_cyl3(*cyl, var, cam);
	}
	if (res.flag && cut_cyl(*cyl, &res, ray))
		check_plane(*cyl, &res, cam, cam1);
	if (res.flag && !res.flag2)
		res.normal = cylinder_normal(*cyl, res.xyz);
	return (res);
}

t_near			cylinder(t_cyl *cyl, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp;

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near));
	while (cyl)
	{
		tmp = intersect_cyl(cyl, cam.xyz, cam1, ray);
		if ((tmp.flag || tmp.flag2) && (!nearest.flag ||
		(vect_len(vect_cord(cam1, tmp.xyz)) <
		vect_len(vect_cord(cam1, nearest.xyz)))))
		{
			nearest = tmp;
			nearest.flag = 1;
		}
		cyl = cyl->next;
	}
	return (nearest);
}
