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

float	vect_len(t_xyz start, t_xyz end)
{
	return (sqrt(pow(end.x - start.x, 2) +
				 pow(end.y - start.y, 2) +
				 pow(end.z - start.z, 2)));
}

t_xyz	normalize(float x, float y, float z)
{
	float		length;
	t_xyz		ray;

	length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	// ray.x = round(x / length * pow(10, 4)) / pow(10, 4);
	// ray.y = round(y / length * pow(10, 4)) / pow(10, 4);
	// ray.z = round(z / length * pow(10, 4)) / pow(10, 4);
	ray.x = x / length;
	ray.y = y / length;
	ray.z = z / length;
	return (ray);
}