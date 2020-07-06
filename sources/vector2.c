#include "minirt.h"

t_xyz	normal_plane(t_xyz orient, t_xyz cam)
{
	t_xyz	normal1;
	t_xyz	normal2;

	normal1.x = orient.x;
	normal1.y = orient.y;
	normal1.z = orient.z;
	normal2.x = -orient.x;
	normal2.y = -orient.y;
	normal2.z = -orient.z;
	return (scalar(normal1, cam) < 0 ? normal1 : normal2);
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