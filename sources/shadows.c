#include "minirt.h"

int		shadow_pln(t_pln *pln, t_xyz dot, t_xyz dot1, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	while (pln && !shadow)
	{
		intersect = intersect_pln(*pln, dot, dot1, ray);
		if (intersect.flag/* && vect_len(vect_cord(dot, intersect.xyz)) > 0.0001*/)
			shadow++;
		pln = pln->next;
	}
	return (shadow);
}

int		shadow_sph(t_sph *sph, t_xyz dot, t_xyz ray, int shadow)
{
	t_near	intersect;

	while (sph && !shadow)
	{
		intersect = intersect_sph(*sph, dot, ray);
		if (intersect.flag && scalar(ray, vect_cord(dot, intersect.xyz)) > 0)
			shadow++;
		sph = sph->next;
	}
	return (shadow);
}