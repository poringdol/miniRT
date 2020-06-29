#include "minirt.h"

t_subst	substitution1(t_xyz sph, t_xyz cam, t_xyz ray, double radius)
{
	t_subst	res;

	res.ay = ray.y / ray.x;
	res.by = (-cam.x) * res.ay + cam.y - sph.y;
	res.az = ray.z / ray.x;
	res.bz = (-cam.x) * res.az + cam.z - sph.z;
	res.a = 1 + pow(res.ay, 2) + pow(res.az, 2);
	res.b = 2 * (res.ay * res.by + res.az * res.bz - sph.x);
	res.c = pow(sph.x, 2) + pow(res.by, 2) + pow(res.bz, 2) - pow(radius, 2);
	res.discr = pow(res.b, 2) - 4 * res.a * res.c;
	return (res);
}

t_subst	substitution2(t_xyz sph, t_xyz cam, t_xyz ray, double radius)
{
	t_subst	res;

	res.ay = 0;
	res.by = 0;
	res.az = ray.z / ray.y;
	res.bz = (-cam.y) * res.az + cam.z - sph.z;
	res.a = 1 + pow(res.az, 2);
	res.b = -2 * (sph.y - res.az * res.bz);
	res.c = pow(sph.y, 2) + pow(res.bz, 2) + pow(cam.x - sph.x, 2) -
		pow(radius, 2);
	res.discr = pow(res.b, 2) - (4 * res.a * res.c);
	return (res);
}

t_near	solution0(t_subst var, t_sph sph, t_xyz cam)
{
	t_near	res;

	res.xyz.x = (pow(sph.diameter / 2, 2) - pow(var.bz, 2) - pow(var.by, 2) -
	sph.xyz.x) / (2 * (var.ay * var.by + var.az * var.bz - sph.xyz.x));
	res.xyz.y = (res.xyz.x - cam.x) * var.ay + cam.y;
	res.xyz.z = (res.xyz.x - cam.x) * var.az + cam.z;
	res.flag = 1;
	res.rgb = sph.rgb;
	return (res);
}

t_near	solution1(t_subst var, t_sph sph, t_xyz cam)
{
	t_near	res;
	t_near	res1;
	t_near	res2;

	ft_bzero(&res, sizeof(t_near));
	res1.xyz.x = (-var.b + sqrt(var.discr)) / (2 * var.a);
	res1.xyz.y = (res1.xyz.x - cam.x) * var.ay + cam.y;
	res1.xyz.z = (res1.xyz.x - cam.x) * var.az + cam.z;
	res2.xyz.x = (-var.b - sqrt(var.discr)) / (2 * var.a);
	res2.xyz.y = (res2.xyz.x - cam.x) * var.ay + cam.y;
	res2.xyz.z = (res2.xyz.x - cam.x) * var.az + cam.z;
	res.xyz = (vect_len(cam, res1.xyz) < vect_len(cam, res2.xyz) ?
		res1.xyz : res2.xyz);
	res.flag = 1;
	res.rgb = sph.rgb;
	return (res);
}

t_near	solution2(t_subst var, t_sph sph, t_xyz cam)
{
	t_near	res;
	t_near	res1;
	t_near	res2;

	ft_bzero(&res, sizeof(t_near));
	res1.xyz.x = cam.x;
	res1.xyz.y = (-var.b + sqrt(var.discr)) / (2 * var.a);
	res1.xyz.z = (res1.xyz.y - cam.y) * var.az + cam.z;
	res2.xyz.x = cam.x;
	res2.xyz.y = (-var.b - sqrt(var.discr)) / (2 * var.a);
	res2.xyz.z = (res2.xyz.y - cam.y) * var.az + cam.z;
	res.xyz = (vect_len(cam, res1.xyz) < vect_len(cam, res2.xyz) ?
		res1.xyz : res2.xyz);
	res.flag = 1;
	res.rgb = sph.rgb;
	return (res);
}

t_near	solution3(t_sph sph, t_xyz cam, t_xyz ray)
{
	double	discr;
	t_near	res;
	t_near	res1;
	t_near	res2;

	ft_bzero(&res, sizeof(t_near));
	discr = pow(cam.x - sph.xyz.x, 2) + pow(cam.y - sph.xyz.y, 2) -
	pow(sph.diameter / 2, 2);
	if (discr < 0)
		return (res);
	res1.xyz = ray;
	res2.xyz = ray;
	res1.xyz.z = sph.xyz.z + sqrt(discr);
	res2.xyz.z = sph.xyz.z - sqrt(discr);
	res.xyz = (vect_len(cam, res1.xyz) < vect_len(cam, res2.xyz) ?
	res1.xyz : res2.xyz);
	res.rgb = sph.rgb;
	res.flag = 1;
	return (res);
}

t_near	intersect_sph2(t_sph sph, t_xyz cam, t_xyz ray)
{
	t_near	res;
	t_subst	var;

	ft_bzero(&res, sizeof(t_near));
	if (ray.x)
	{
		var = substitution1(sph.xyz, cam, ray, sph.diameter / 2);
		if (var.a == 0)
			res = solution0(var, sph, cam);
		else if (var.discr < 0)
			return (res);
		else
			res = solution1(var, sph, cam);
	}
	else if (ray.y)
	{
		var = substitution2(sph.xyz, cam, ray, sph.diameter / 2);
		if (var.discr < 0)
			return (res);
		res = solution2(var, sph, cam);
	}
	else
		res = solution3(sph, cam, ray);
	return (res);
}