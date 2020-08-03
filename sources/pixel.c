/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:10:15 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 05:15:30 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*pixel_table(void *arg)
{
	int		i;
	int		j;
	t_xyz	cam1;
	t_xyz	ray;
	t_near	nearest;

	j = *(int *)arg;
	while (j < g_scene.res.height)
	{
		i = -1;
		while (++i < g_scene.res.width)
		{
			cam1 = vect_end(g_scene.canvas, g_scene.res, i, j);
			ray = normalize(vect_cord(g_scene.cam->xyz, cam1));
			nearest = nearest_pix(g_scene.cam->xyz, cam1, ray);
			nearest.rgb = color(g_scene, nearest, g_scene.param, i);
			my_mlx_pixel_put(&g_mlx, i, j, nearest.rgb);
		}
		j += 4;
	}
	pthread_exit(NULL);
	return (NULL);
}

t_near	nearest_pix(t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near		nearest;
	t_near		tmp;

	bzero(&nearest, sizeof(t_near));
	bzero(&tmp, sizeof(t_near));
	tmp = plane(g_scene.pln, *g_scene.cam, cam1, ray);
	nearest = (tmp.flag && vect_len(vect_cord(cam1, tmp.xyz)) <
		range_of_view(g_scene.canvas, cam, cam1)) ? tmp : nearest;
	tmp = sphere(g_scene.sph, g_scene.cam->xyz, cam1, ray);
	nearest = ((tmp.flag) &&
		(!nearest.flag || vect_len(vect_cord(cam, tmp.xyz)) <
		vect_len(vect_cord(cam, nearest.xyz)))) ? tmp : nearest;
	tmp = triangle(g_scene.tri, g_scene.cam->xyz, cam1, ray);
	nearest = ((tmp.flag2) &&
		(!nearest.flag || vect_len(vect_cord(cam, tmp.xyz)) <
		vect_len(vect_cord(cam, nearest.xyz)))) ? tmp : nearest;
	tmp = square(g_scene.sqr, *g_scene.cam, cam1, ray);
	nearest = ((tmp.flag2) &&
		(!nearest.flag || vect_len(vect_cord(cam, tmp.xyz)) <
		vect_len(vect_cord(cam, nearest.xyz)))) ? tmp : nearest;
	tmp = cylinder(g_scene.cyl, *g_scene.cam, cam1, ray);
	nearest = (tmp.flag && (!nearest.flag || vect_len(vect_cord(cam,
		tmp.xyz)) < vect_len(vect_cord(cam, nearest.xyz)))) ? tmp : nearest;
	nearest = nearest_pix_bonus(cam, cam1, ray, nearest);
	return (nearest);
}
