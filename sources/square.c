#include "minirt.h"

t_near	square(t_sqr *sqr, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp;
	ft_bzero(&nearest, sizeof(t_near));
	while (sqr)
	{
		tmp = intersect_pln(sqr->pln, cam.xyz, cam1, ray);
		if (tmp.flag2 && (check_triangle(sqr->tri1, tmp.xyz, nearest, cam1) ||
		check_triangle(sqr->tri2, tmp.xyz, nearest, cam1)))
			nearest = tmp;
		sqr = sqr->next;
	}
	return (nearest);
}