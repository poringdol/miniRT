#include "minirt.h"

t_util	fill_util_cyl1(t_cyl cyl, t_xyz cam, t_xyz ray, t_canv canv)
{
	t_util	util;

	util.ay = ray.y / ray.x;
	util.by = -cam.x * util.ay + cyl.o.y;
	util.az = ray.z / ray.x;
	util.bz = -cam.x * util.az + cyl.o.z;
	util.k = canv.cos_a * canv.sin_b + util.ay * canv.sin_a * canv.sin_b -
			util.az * canv.cos_b;
	util.l = canv.sin_b * (-cyl.o.x * canv.cos_a + util.by * canv.sin_a -
			cyl.o.y * canv.sin_a) - canv.cos_b * (util.bz - cyl.o.z);
	util.n = util.ay * canv.cos_a - canv.sin_a;
	util.m = cyl.o.x * canv.sin_a + canv.cos_a * (util.by - cyl.o.y);
	util.a = pow(util.k, 2) + pow(util.n, 2);
	util.b = 2 * (util.k * util.l + util.n * util.m);
	util.c = pow(util.l, 2) + pow(util.m, 2) - pow(cyl.diameter / 2, 2);
	util.discr = pow(util.b, 2) - 4 * util.a * util.c;
	return (util);
}

t_near	solution_cyl1(t_cyl cyl, t_util var, t_xyz cam)
{
	t_near	tmp1;
	t_near	tmp2;
	t_near	res;

	ft_bzero(&res, sizeof(t_near));
	if (var.discr < 0)
		return (res);
	tmp1.xyz.x = (-var.b + sqrt(var.discr)) / (2 * var.a);
	tmp1.xyz.y = tmp1.xyz.x * var.ay + var.by;
	tmp1.xyz.z = tmp1.xyz.x * var.az + var.bz;
	tmp2.xyz.x = (-var.b - sqrt(var.discr)) / (2 * var.a);
	tmp2.xyz.y = tmp2.xyz.x * var.ay + var.by;
	tmp2.xyz.z = tmp2.xyz.x * var.az + var.bz;
	res.xyz = vect_len(vect_cord(cam, tmp1.xyz)) <
				vect_len(vect_cord(cam, tmp2.xyz)) ? tmp1.xyz : tmp2.xyz;
	res.flag = 1;
	res.rgb = cyl.rgb;
	res.normal = cylinder_normal(cyl, res.xyz);
	return (res);
}

t_util	fill_util_cyl2(t_cyl cyl, t_xyz cam, t_xyz ray, t_canv canv)
{
	t_util	util;

	util.az = ray.z / ray.x;
	util.bz = -cam.x * util.az + cyl.o.z;
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

t_near	solution_cyl2(t_cyl cyl, t_util var, t_xyz cam)
{
	t_near	tmp1;
	t_near	tmp2;
	t_near	res;

	ft_bzero(&res, sizeof(t_near));
	if (var.discr < 0)
		return (res);
	tmp1.xyz.x = cyl.o.x;
	tmp1.xyz.y = (-var.b + var.discr) / (2 * var.a);
	tmp1.xyz.z = tmp1.xyz.y * var.az + var.bz;
	tmp2.xyz.x = cyl.o.x;
	tmp2.xyz.y = (-var.b - var.discr) / (2 * var.a);
	tmp2.xyz.z = tmp2.xyz.y * var.az + var.bz;
	res.xyz = vect_len(vect_cord(cam, tmp1.xyz)) <
				vect_len(vect_cord(cam, tmp2.xyz)) ? tmp1.xyz : tmp2.xyz;
	res.flag = 1;
	res.rgb = cyl.rgb;
	res.normal = cylinder_normal(cyl, res.xyz);
	return (res);
}

t_near	solution_cyl3(t_cyl cyl, t_xyz cam, t_canv canv)
{
	t_near	tmp1;
	t_near	tmp2;
	t_near	res;
	t_util	var;

	var.a = pow(canv.cos_b, 2);
	var.b = 2 * cyl.o.z * pow(canv.cos_b, 2);
	var.c = pow(cyl.o.z, 2) * pow(canv.cos_b, 2) - pow(cyl.diameter / 2, 2);
	var.discr = pow(var.b, 2) - 4 * var.a * var.c;
	ft_bzero(&res, sizeof(t_near));
	if (var.discr < 0)
		return (res);
	tmp1.xyz.x = cyl.o.x;
	tmp1.xyz.y = (-var.b + var.discr) / (2 * var.a);
	tmp1.xyz.z = tmp1.xyz.y * var.az + var.bz;
	tmp2.xyz.x = cyl.o.x;
	tmp2.xyz.y = (-var.b - var.discr) / (2 * var.a);
	tmp2.xyz.z = tmp2.xyz.y * var.az + var.bz;
	res.xyz = vect_len(vect_cord(cam, tmp1.xyz)) <
				vect_len(vect_cord(cam, tmp2.xyz)) ? tmp1.xyz : tmp2.xyz;
	res.flag = 1;
	res.rgb = cyl.rgb;
	res.normal = cylinder_normal(cyl, res.xyz);
	return (res);
}