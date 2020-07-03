#include "minirt.h"

t_subst	substitution1(t_xyz sph, t_xyz cam, t_xyz ray, double radius)
{
	t_subst	res;

	ft_bzero(&res, sizeof(t_subst));
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


	ft_bzero(&res, sizeof(t_subst));
	res.az = ray.z / ray.y;
	res.bz = (-cam.y) * res.az + cam.z - sph.z;
	res.a = 1 + pow(res.az, 2);
	res.b = -2 * (sph.y - res.az * res.bz);
	res.c = pow(sph.y, 2) + pow(res.bz, 2) + pow(cam.x - sph.x, 2) -
		pow(radius, 2);
	res.discr = pow(res.b, 2) - (4 * res.a * res.c);
	return (res);
}

