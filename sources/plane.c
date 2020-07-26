#include "minirt.h"

static t_near	solution1(t_subst var, t_pln pln, t_xyz ray, t_xyz cam1)
{
	t_near	res;
	float	divisor;

	ft_bzero(&res, sizeof(t_near));
	if (!(divisor = pln.orient.x + pln.orient.y * var.ay +
			pln.orient.z * var.az))
		return (res);
	res.xyz.x = (pln.orient.x * pln.xyz.x + pln.orient.y * pln.xyz.y +
			pln.orient.z * pln.xyz.z -
			var.by * pln.orient.y - var.bz * pln.orient.z) / divisor;
	res.xyz.y =	res.xyz.x * var.ay + var.by;
	res.xyz.z = res.xyz.x * var.az + var.bz;
	res.rgb	= pln.rgb;
	res.flag = (((res.xyz.x - cam1.x) / ray.x) < -0.01) ? 0 : 1;
	res.flag2 = 1;
	res.normal = pln.normal; 
	return (res);
}

static t_near	solution2(t_subst var, t_pln pln, t_xyz cam,
							t_xyz cam1, t_xyz ray)
{
	t_near	res;
	float	divisor;

	ft_bzero(&res, sizeof(t_near));
	if (!(divisor = pln.orient.y + pln.orient.z * var.az))
		return (res);
	res.xyz.x = cam.x;
	res.xyz.y = -(pln.orient.x * (cam.x - pln.xyz.x) - pln.orient.y *
		pln.xyz.y + pln.orient.z * (var.bz - pln.xyz.z)) / divisor;
	res.xyz.z = res.xyz.y * var.az + var.bz;
	res.rgb	= pln.rgb;
	res.flag = (((res.xyz.y - cam1.y) / ray.y) < -0.01) ? 0 : 1;
	res.flag2 = 1;
	res.normal = pln.normal;
	return (res);
}

static t_near	solution3(t_pln pln, t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near	res;

	ft_bzero(&res, sizeof(t_near));
	if (!pln.orient.z)
		return (res);
	res.xyz.x = cam.x;
	res.xyz.y = cam.y;
	res.xyz.z = (pln.orient.z * pln.xyz.z - pln.orient.x *
		(cam.x - pln.xyz.x) - pln.orient.y * (cam.y - pln.xyz.y)) /
		pln.orient.z;
	res.rgb = pln.rgb;
	res.flag = (((res.xyz.z - cam1.z) / ray.z) < -0.01) ? 0 : 1;
	res.flag2 = 1;
	res.normal = pln.normal;
	return (res);
}

t_near			plane(t_pln *pln, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp;

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near));
	while (pln)
	{
		tmp = intersect_pln(*pln, cam.xyz, cam1, ray);
		if (tmp.flag && (!nearest.flag ||
		(vect_len(vect_cord(cam1, tmp.xyz)) <
		vect_len(vect_cord(cam1, nearest.xyz)))
		))
			nearest = tmp;
		pln = pln->next;
	}
	return (nearest);
}

t_near			intersect_pln(t_pln pln, t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near	res;
	t_subst	var;

	ft_bzero(&res, sizeof(t_near));
	ft_bzero(&var, sizeof(t_subst));
	if (ray.x)
	{
		var = substitution1(res.xyz, cam, ray, 0);
		res = solution1(var, pln, ray, cam1);
	}
	else if (ray.y)
	{
		var = substitution2(res.xyz, cam, ray, 0);
		res = solution2(var, pln, cam, cam1, ray);
	}
	else
		res = solution3(pln, cam, cam1, ray);
	return (res);
}