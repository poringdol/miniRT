#include "minirt.h"

static void		check_plane(t_cyl cyl, t_near *res,\
							t_cam cam, t_xyz cam1, t_xyz ray)
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
	tmp = intersect_pln(pln, cam.xyz, cam1, ray);
	tmp1 = intersect_pln(pln1, cam.xyz, cam1, ray);
	if (vect_len(vect_cord(tmp.xyz, cyl.o)) <= cyl.diameter / 2)
		res->normal = f_normal(pln.orient, pln.xyz, cam.orient, cam.xyz);
	else if (vect_len(vect_cord(tmp1.xyz, cyl.o1)) <= cyl.diameter / 2)
		res->normal = f_normal(pln1.orient, pln1.xyz, cam.orient, cam.xyz);
	else
		res->flag = 0;
}

static void		cut_cyl(t_cyl cyl, t_near *res, t_canv canv)
{
	t_xyz	xyz1;
	t_near	tmp;

	if (scal_product(cyl.orient, vect_cord(cyl.o, res->xyz)) < 0)
		res->flag2 = 1;
	if (res->flag && scal_product(cyl.orient, vect_cord(cyl.o1, res->xyz)) > 0)
		res->flag2 = 1;
}

static t_canv	sin_cos(t_cyl *cyl, t_xyz cam, t_xyz ray)
{
	t_canv	canv;

	canv.sin_b = cyl->orient.z / vect_len(cyl->orient);
	canv.cos_b = sqrt(fabs(1 - pow(canv.sin_b, 2)));
	canv.cos_a = (canv.cos_b != 0) ? cyl->orient.x /
				(vect_len(cyl->orient) * canv.cos_b) : 0;
	canv.sin_a = sqrt(fabs(1 - pow(canv.cos_a, 2)));
	cyl->o1.x = cyl->o.x + cyl->height * canv.cos_b * canv.cos_a;
	cyl->o1.y = cyl->o.y + cyl->height * canv.cos_b * canv.sin_a;
	cyl->o1.z = cyl->o.z + cyl->height * canv.sin_b;
	return (canv);
}

t_near			intersect_cyl(t_cyl *cyl, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	res;
	t_util	var;
	t_canv	canv;

	ft_bzero(&res, sizeof(t_near));
	ft_bzero(&var, sizeof(t_util));
	canv = sin_cos(cyl, cam.xyz, ray);
	if (ray.x)
	{
		var = fill_util_cyl1(*cyl, cam.xyz, ray, canv);
		res = solution_cyl1(*cyl, var, cam.xyz);
	}
	else if (ray.y)
	{
		var = fill_util_cyl2(*cyl, cam.xyz, ray, canv);
		res = solution_cyl2(*cyl, var, cam.xyz);
	}
	else
		res = solution_cyl3(*cyl, cam.xyz, canv);
	if (res.flag)
		cut_cyl(*cyl, &res, canv);
	if (res.flag2)
		check_plane(*cyl, &res, cam, cam1, ray);
	return (res);
}

t_near			cylinder(t_cyl *cyl, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp;
	t_util	util;

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near));
	while (cyl)
	{
		tmp = intersect_cyl(cyl, cam, cam1, ray);
		if (tmp.flag && (!nearest.flag ||
		(vect_len(vect_cord(cam1, tmp.xyz)) <
		vect_len(vect_cord(cam1, nearest.xyz)))
		))
			nearest = tmp;
		cyl = cyl->next;
	}
	return (nearest);
}