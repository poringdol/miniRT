#include "minirt.h"

t_xyz	normal_plane(t_xyz dot, t_xyz orient, t_xyz cam)
{
	t_xyz	normal1;
	t_xyz	normal2;

	normal1.x = dot.x + orient.x;
	normal1.y = dot.y + orient.y;
	normal1.z = dot.z + orient.z;
	normal2.x = dot.x - orient.x;
	normal2.y = dot.y - orient.y;
	normal2.z = dot.z - orient.z;
	return (vect_len(vect_cord(cam, normal1)) <
			vect_len(vect_cord(cam, normal2)) ?
			vect_cord(dot, normal1) : vect_cord(dot, normal2));
}
