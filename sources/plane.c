#include "minirt.h"

static t_near	solution1(t_subst var, t_pln pln, t_xyz ray, t_xyz cam1)
{
	t_near	res;
	float	x;
	float	divisor;

	ft_bzero(&res, sizeof(t_near));
	if (!(divisor = pln.orient.x + pln.orient.y * var.ay + pln.orient.z * var.az))
		return (res);
	x = (pln.orient.x * pln.xyz.x + pln.orient.y * pln.xyz.y +
			pln.orient.z * pln.xyz.z -
			var.by * pln.orient.y - var.bz * pln.orient.z) / divisor;
	if (((x - cam1.x) / ray.x) < -0.000001)
		return (res);
	res.xyz.x = x;
	res.xyz.y =	res.xyz.x * var.ay + var.by;
	res.xyz.z = res.xyz.x * var.az + var.bz;
	res.rgb	= pln.rgb;
	res.flag = 1;
	res.normal = pln.normal; 
	return (res);
}

static t_near	solution2(t_subst var, t_pln pln, t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near	res;
	float	y;
	float	divisor;

	ft_bzero(&res, sizeof(t_near));
	if (!(divisor = pln.orient.y + pln.orient.z * var.az))
		return (res);
	y = -(pln.orient.x * (cam.x - pln.xyz.x) - pln.orient.y *
		pln.xyz.y + pln.orient.z * (var.bz - pln.xyz.z)) / divisor;
	if (((y - cam1.y) / ray.y) < -0.000001)
		return (res);
	res.xyz.x = cam.x;
	res.xyz.y = y;
	res.xyz.z = res.xyz.y * var.az + var.bz;
	res.rgb	= pln.rgb;
	res.flag = 1;
	res.normal = pln.normal;
	return (res);
}

static t_near	solution3(t_pln pln, t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near	res;
	float	z;

	ft_bzero(&res, sizeof(t_near));
	if (!pln.orient.z)
		return (res);
	z = (pln.orient.z * pln.xyz.z - pln.orient.x *
		(cam.x - pln.xyz.x) - pln.orient.y * (cam.y - pln.xyz.y)) / pln.orient.z;
	if (((z - cam1.z) / ray.z) < -0.000001)
		return (res);
	res.xyz.x = cam.x;
	res.xyz.y = cam.y;
	res.xyz.z = z;
	res.rgb = pln.rgb;
	res.flag = 1;
	return (res);
}

t_near			plane(t_pln *pln, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp;
	t_pln	*tmp_pln;

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near));
	tmp_pln = pln;
	while (tmp_pln)
	{
		tmp_pln->normal = normal_plane(tmp_pln->orient, cam.orient);
		tmp_pln = tmp_pln->next;
	}
	while (pln)
	{
		tmp = intersect_pln(*pln, cam.xyz, cam1, ray);
		if (!nearest.flag || (tmp.flag &&
		(vect_len(vect_cord(cam1, tmp.xyz)) <
		vect_len(vect_cord(cam1, nearest.xyz)))))
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