#include "minirt.h"

t_xyz	vect_end(t_canv canv, t_res res, int i, int j)
{
	t_xyz	xyz;

	xyz.x = canv.o.x - canv.x / 2 * canv.sin_a -
		canv.y / 2 * canv.sin_b * canv.cos_a +
		canv.x * i / res.x * canv.sin_a +
		canv.y * j / res.y * canv.sin_b * canv.cos_a;
	xyz.y = canv.o.y + canv.x / 2 * canv.cos_a -
		canv.y / 2 * canv.sin_b * canv.sin_a -
		canv.x * i / res.x * canv.cos_a +
		canv.y * j / res.y * canv.sin_b * canv.sin_a;
	xyz.z = canv.o.z + canv.y / 2 * canv.cos_b -
		canv.y * j / res.y * canv.cos_b;
	return (xyz);
}

double	vect_len(t_xyz vect)
{
	return (sqrt(pow(vect.x, 2) +
				 pow(vect.y, 2) +
				 pow(vect.z, 2)));
}

t_xyz	vect_cord(t_xyz start, t_xyz end)
{
	t_xyz	res;

	res.x = end.x - start.x;
	res.y = end.y - start.y;
	res.z = end.z - start.z;
	return (res);
}

t_xyz	normalize(t_xyz vect)
{
	double		length;
	t_xyz		ray;

	length = sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2));
	ray.x = vect.x / length;
	ray.y = vect.y / length;
	ray.z = vect.z / length;
	return (ray);
}

double	scalar(t_xyz vect1, t_xyz vect2)
{
	double res;

	res = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
	return (res);
}