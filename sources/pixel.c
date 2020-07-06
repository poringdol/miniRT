#include "minirt.h"

t_near	nearest_pix(t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near		nearest;
	t_near		tmp;

	bzero(&nearest, sizeof(t_near));
	nearest.rgb = BACKGROUND;
	bzero(&tmp, sizeof(t_near));
	tmp = plane(g_scene.pln, *g_scene.cam, cam1, ray);
	nearest = (vect_len(vect_cord(cam1, tmp.xyz)) <
	range_of_view(g_scene.canvas, cam, cam1)) ? tmp : nearest;
	tmp = sphere(g_scene.sph, g_scene.cam->xyz, cam1, ray);
	nearest = ((tmp.flag) &&
	(!nearest.flag || vect_len(vect_cord(cam, tmp.xyz)) <
	vect_len(vect_cord(cam, nearest.xyz)))) ? tmp : nearest;
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
