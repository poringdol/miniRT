#include "minirt.h"

t_xyz	vect_multipl(t_xyz xyz, float rate)
{
	t_xyz	res;

	res.x = xyz.x * rate;
	res.y = xyz.y * rate;
	res.z = xyz.z * rate;
	return (res);
}

t_xyz	vect_addit(t_xyz xyz, t_xyz rate)
{
	t_xyz	res;

	res.x = xyz.x + rate.x;
	res.y = xyz.y + rate.y;
	res.z = xyz.z + rate.z;
	return (res);
}