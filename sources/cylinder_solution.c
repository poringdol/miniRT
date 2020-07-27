#include "minirt.h"

t_near	solution_cyl1(t_cyl cyl, t_util var, t_xyz cam)
{
	t_near	tmp1;
	t_near	tmp2;
	t_near	res;

	ft_bzero(&res, sizeof(t_near));
	if (var.discr < 0)
		return (res);
	res.flag = 1;
	res.rgb = cyl.rgb;
	if (var.a == 0)
	{
		res.xyz.x = -var.c / var.b;
		res.xyz.y = res.xyz.x * var.ay + var.by;
		res.xyz.z = res.xyz.x * var.az + var.bz;
		return (res);
	}
	tmp1.xyz.x = (-var.b + sqrt(var.discr)) / (2 * var.a);
	tmp1.xyz.y = tmp1.xyz.x * var.ay + var.by;
	tmp1.xyz.z = tmp1.xyz.x * var.az + var.bz;
	tmp2.xyz.x = (-var.b - sqrt(var.discr)) / (2 * var.a);
	tmp2.xyz.y = tmp2.xyz.x * var.ay + var.by;
	tmp2.xyz.z = tmp2.xyz.x * var.az + var.bz;
	res.xyz = vect_len(vect_cord(cam, tmp1.xyz)) <
				vect_len(vect_cord(cam, tmp2.xyz)) ? tmp1.xyz : tmp2.xyz;
	return (res);
}

t_near	solution_cyl2(t_cyl cyl, t_util var, t_xyz cam)
{
	t_near	tmp1;
	t_near	tmp2;
	t_near	res;

	ft_bzero(&res, sizeof(t_near));
	if (var.discr < 0)
		return (res);
	res.flag = 1;
	res.rgb = cyl.rgb;
	if (var.a == 0)
	{
		res.xyz.x = cam.x;
		res.xyz.y = -var.c / var.b;
		res.xyz.z = res.xyz.y * var.az + var.bz;
		return (res);
	}
	tmp1.xyz.x = cam.x;
	tmp1.xyz.y = (-var.b + sqrt(var.discr)) / (2 * var.a);
	tmp1.xyz.z = tmp1.xyz.y * var.az + var.bz;
	tmp2.xyz.x = cam.x;
	tmp2.xyz.y = (-var.b - sqrt(var.discr)) / (2 * var.a);
	tmp2.xyz.z = tmp2.xyz.y * var.az + var.bz;
	res.xyz = vect_len(vect_cord(cam, tmp1.xyz)) <
				vect_len(vect_cord(cam, tmp2.xyz)) ? tmp1.xyz : tmp2.xyz;
	return (res);
}

t_near	solution_cyl3(t_cyl cyl, t_util var, t_xyz cam)
{
	t_near	tmp1;
	t_near	tmp2;
	t_near	res;

	ft_bzero(&res, sizeof(t_near));
	if (var.discr < 0)
		return (res);
	res.flag = 1;
	res.rgb = cyl.rgb;
	tmp1.xyz = cam;
	tmp2.xyz = cam;
	if (var.a == 0)
	{
		res.xyz = cam;
		res.xyz.z = -var.c / var.b;
		return (res);
	}
	tmp1.xyz.z = (-var.b + sqrt(var.discr)) / (2 * var.a);
	tmp2.xyz.z = (-var.b + sqrt(var.discr)) / (2 * var.a);
	res.xyz = vect_len(vect_cord(cam, tmp1.xyz)) <
				vect_len(vect_cord(cam, tmp2.xyz)) ? tmp1.xyz : tmp2.xyz;
	return (res);
}
