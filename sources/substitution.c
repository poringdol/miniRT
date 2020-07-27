/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:11:10 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:11:11 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_subst	substitution_sph1(t_xyz sph, t_xyz cam, t_xyz ray, double radius)
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
	res.discr = pow(res.b, 2) - (4 * res.a * res.c);
	return (res);
}

t_subst	substitution_sph2(t_xyz sph, t_xyz cam, t_xyz ray, double radius)
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

t_util	substitution_cyl1(t_cyl cyl, t_xyz cam, t_xyz ray, t_canv canv)
{
	t_util	util;

	util.ay = ray.y / ray.x;
	util.by = -cam.x * util.ay + cam.y;
	util.az = ray.z / ray.x;
	util.bz = -cam.x * util.az + cam.z;
	util.k = canv.sin_b * (canv.cos_a + util.ay * canv.sin_a) -
			util.az * canv.cos_b;
	util.l = canv.sin_b * (canv.sin_a * (util.by - cyl.o.y) -
			cyl.o.x * canv.cos_a) - canv.cos_b * (util.bz - cyl.o.z);
	util.n = util.ay * canv.cos_a - canv.sin_a;
	util.m = cyl.o.x * canv.sin_a + canv.cos_a * (util.by - cyl.o.y);
	util.a = pow(util.k, 2) + pow(util.n, 2);
	util.b = 2 * (util.k * util.l + util.n * util.m);
	util.c = pow(util.l, 2) + pow(util.m, 2) - pow(cyl.diameter / 2, 2);
	util.discr = pow(util.b, 2) - 4 * util.a * util.c;
	return (util);
}

t_util	substitution_cyl2(t_cyl cyl, t_xyz cam, t_xyz ray, t_canv canv)
{
	t_util	util;

	util.az = ray.z / ray.y;
	util.bz = -cam.y * util.az + cam.z;
	util.k = canv.sin_a * canv.sin_b - util.az * canv.cos_b;
	util.l = -cyl.o.y * canv.sin_a * canv.sin_b -
			canv.cos_b * (util.bz - cyl.o.z);
	util.m = cyl.o.y * pow(canv.cos_a, 2);
	util.a = pow(util.k, 2) + pow(canv.cos_a, 2);
	util.b = 2 * (util.k * util.l - util.m);
	util.c = pow(util.l, 2) + cyl.o.y * util.m - pow(cyl.diameter / 2, 2);
	util.discr = pow(util.b, 2) - 4 * util.a * util.c;
	return (util);
}

t_util	substitution_cyl3(t_cyl cyl, t_xyz cam, t_xyz ray, t_canv canv)
{
	t_util	util;

	util.k = cyl.o.z * canv.cos_b + ((cam.x - cyl.o.x) * canv.cos_a +
			(cam.y - cyl.o.y) * canv.sin_a) * canv.sin_b;
	util.a = pow(canv.cos_b, 2);
	util.b = -2 * canv.cos_b * util.k;
	util.c = pow(util.k, 2) + pow(-(cam.x - cyl.o.x) * canv.sin_a +
			(cam.y - cyl.o.y) * canv.cos_a, 2) - pow(cyl.diameter / 2, 2);
	util.discr = pow(util.b, 2) - 4 * util.a * util.c;
	return (util);
}
