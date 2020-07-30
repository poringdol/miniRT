/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_directional.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:12:33 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/30 07:19:55 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		directional_light(int color, t_near dot, t_lht_d *lht)
{
	double	cos_dot_lht;
	double	bright;

	while (lht)
	{
		cos_dot_lht = scal_product(dot.normal, lht->direct);
		if (cos_dot_lht < 0 && !shadow_direct(g_scene, dot, lht->direct))
		{
			bright = lht->bri * -cos_dot_lht;
			color = get_color(color, dot.rgb, lht->rgb, bright);
		}
		lht = lht->next;
	}
	return (color);
}

int		shadow_direct(t_scene g_scene, t_near dot, t_xyz light_ray)
{
	int		shadow;
	t_xyz	light_dot;
	t_xyz	dot2;

	dot2 = vect_addit(dot.xyz, vect_multipl(dot.normal, 0.01));
	light_dot = vect_addit(dot2, vect_multipl(light_ray, -500));
	shadow = shadow_pln(g_scene.pln, light_dot, dot2, light_ray);
	if (!shadow)
		shadow = shadow_sph(g_scene.sph, light_dot, dot2, light_ray);
	if (!shadow)
		shadow = shadow_tri(g_scene.tri, light_dot, dot2, light_ray);
	if (!shadow)
		shadow = shadow_sqr(g_scene.sqr, light_dot, dot2, light_ray);
	if (!shadow)
		shadow = shadow_cyl(g_scene.cyl, light_dot, dot2, light_ray);
	return (shadow ? 1 : 0);
}
