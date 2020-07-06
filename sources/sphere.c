#include "minirt.h"

static t_near	solution1(t_subst var, t_sph sph, t_xyz cam)
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
	res.xyz = (vect_len(vect_cord(cam, res1.xyz)) <
	vect_len(vect_cord(cam, res2.xyz)) ? res1.xyz : res2.xyz);
	res.flag = 1;
	res.rgb = sph.rgb;
	res.normal = normalize(vect_cord(sph.xyz, res.xyz));
	return (res);
}

static t_near	solution2(t_subst var, t_sph sph, t_xyz cam)
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
	res.xyz = (vect_len(vect_cord(cam, res1.xyz)) <
	vect_len(vect_cord(cam, res2.xyz)) ? res1.xyz : res2.xyz);
	res.flag = 1;
	res.rgb = sph.rgb;
	res.normal = normalize(vect_cord(sph.xyz, res.xyz));
	return (res);
}

static t_near	solution3(t_sph sph, t_xyz cam, t_xyz ray)
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
	res.xyz = (vect_len(vect_cord(cam, res1.xyz)) <
	vect_len(vect_cord(cam, res2.xyz)) ? res1.xyz : res2.xyz);
	res.rgb = sph.rgb;
	res.flag = 1;
	res.normal = normalize(vect_cord(sph.xyz, res.xyz));
	return (res);
}

t_near			sphere(t_sph *sph, t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near		nearest;
	t_near		tmp;

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near));
	while (sph)
	{
		if (vect_len(vect_cord(sph->xyz, cam1)) > (sph->diameter / 2))
		{
			tmp = intersect_sph(*sph, cam, ray);
			if ((tmp.flag &&
			scalar(g_scene.cam->orient, vect_cord(cam, tmp.xyz)) > 0 &&
			(!nearest.flag ||
			(vect_len(vect_cord(cam, tmp.xyz))) <
			(vect_len(vect_cord(cam, nearest.xyz))))))
				nearest = tmp;
		}
		sph = sph->next;
	}
	return (nearest);
}

t_near			intersect_sph(t_sph sph, t_xyz cam, t_xyz ray)
{
	t_near	res;
	t_subst	var;

	ft_bzero(&res, sizeof(t_near));
	ft_bzero(&var, sizeof(t_subst));
	if (ray.x)
	{
		var = substitution1(sph.xyz, cam, ray, sph.diameter / 2);
		if (var.discr < 0)
			return (res);
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
