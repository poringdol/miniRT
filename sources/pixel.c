#include "minirt.h"

t_near	nearest_pix(t_xyz cam, t_xyz ray)
{
	t_near		nearest;
	t_near		tmp;

	bzero(&nearest, sizeof(t_near));
	nearest.rgb = BACKGROUND;
	bzero(&tmp, sizeof(t_near));
	// tmp = plane(g_scene.sph->xyz, g_scene.cam->xyz, ray);
	// nearest = (!nearest.flag ||
	// 		vect_len(cam, tmp.xyz) < vect_len(cam, nearest.xyz)) ? tmp : nearest;
	tmp = sphere(g_scene.sph, g_scene.cam->xyz, ray);
	nearest = ((!nearest.flag && tmp.flag) ||
			vect_len(cam, tmp.xyz) < vect_len(cam, nearest.xyz)) ? tmp : nearest;
	// tmp = square(g_scene.sph->xyz, g_scene.cam->xyz, ray);
	// nearest = (!nearest.flag ||
	// 		vect_len(cam, tmp.xyz) < vect_len(cam, nearest.xyz)) ? tmp : nearest;
	// tmp = cylinder(g_scene.sph->xyz, g_scene.cam->xyz, ray);
	// nearest = (!nearest.flag ||
	// 		vect_len(cam, tmp.xyz) < vect_len(cam, nearest.xyz)) ? tmp : nearest;
	// tmp = triangle(g_scene.sph->xyz, g_scene.cam->xyz, ray);
	// nearest = (!nearest.flag ||
	// 		vect_len(cam, tmp.xyz) < vect_len(cam, nearest.xyz)) ? tmp : nearest;
	return (nearest);
}





t_near	sphere(t_sph *sph, t_xyz cam, t_xyz ray)
{
	t_near		nearest;
	t_near		tmp;
	float q1;
	float q2;

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near));
	while (sph)
	{
		tmp = intersect_sph(*sph, cam, ray);
		if (((vect_len(sph->xyz, cam)) > (sph->diameter / 2)) &&
		((tmp.flag && !nearest.flag) || (tmp.flag &&
		(q1 = vect_len(cam, tmp.xyz)) < (q2 = vect_len(cam, nearest.xyz)))))
			nearest = tmp;
		sph = sph->next;
	}
	return (nearest);
}
