#include "minirt.h"

static t_near	solution1(t_subst var, t_pln pln, t_xyz cam)
{
	t_near	res;
	float	divisor;

	ft_bzero(&res, sizeof(t_near));
	if (!(divisor = pln.orient.x + pln.orient.y * var.ay + pln.orient.z * var.az))
		return (res);
	res.xyz.x = (pln.orient.x * pln.xyz.x + pln.orient.y * pln.xyz.y +
			pln.orient.z * pln.xyz.z -
			var.by * pln.orient.y - var.bz * pln.orient.z) / divisor;
	res.xyz.y = res.xyz.x * var.ay + var.by;
	res.xyz.z = res.xyz.x * var.az + var.bz;
	res.rgb	= pln.rgb;
	res.flag = 1;
	res.normal = normal_plane(res.xyz, pln.orient, cam); 
	return (res);
}

t_near			plane(t_pln *pln, t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp;
	float	distance;

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near));

	while (pln)
	{
		tmp = intersect_pln(*pln, cam, ray);
		distance = vect_len(vect_cord(cam1, tmp.xyz));
		if (tmp.flag && (distance < ROV) &&
		scalar(g_scene.cam->orient, vect_cord(cam, tmp.xyz)) > 0 &&
		(!nearest.flag ^ (distance < vect_len(vect_cord(cam, nearest.xyz)))))
			nearest = tmp;
		pln = pln->next;
	}
	return (nearest);
}

t_near			intersect_pln(t_pln pln, t_xyz cam, t_xyz ray)
{
	t_near	res;
	t_subst	var;

	ft_bzero(&res, sizeof(t_near));
	ft_bzero(&var, sizeof(t_subst));
	if (ray.x)
	{
		var = substitution1(res.xyz, cam, ray, 0);
		res = solution1(var, pln, cam);
	}
	return (res);
}