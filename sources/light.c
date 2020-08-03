/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:09:35 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 06:37:41 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		brightness(t_near dot, t_lht *lht, t_lht_d *lht_d)
{
	t_xyz	light_ray;
	int		color;
	double	cos_dot_light;
	double	bright;

	color = get_color(0, dot.rgb, g_scene.amb.rgb, g_scene.amb.lht_rat);
	while (lht)
	{
		light_ray = normalize(vect_cord(dot.xyz, lht->xyz));
		cos_dot_light = scal_product(dot.normal, light_ray);
		if (cos_dot_light > 0 && !shadow(g_scene, dot, lht->xyz))
		{
			bright = lht->bri * cos_dot_light;
			color = get_color(color, dot.rgb, lht->rgb, bright);
		}
		lht = lht->next;
	}
	color = directional_light(color, dot, lht_d);
	return (color);
}

int		get_color(int color, int rgb, int light_color, double bright)
{
	t_rgb	res;
	t_rgb	lht_rgb;
	int		tmp;

	res.red = rgb >> 16;
	res.green = rgb >> 8 & 0xff;
	res.blue = rgb & 0xff;
	lht_rgb.red = light_color >> 16;
	lht_rgb.green = light_color >> 8 & 0xff;
	lht_rgb.blue = light_color & 0xff;
	tmp = (double)res.red * bright * ((double)lht_rgb.red / 255) +
		(color >> 16);
	res.red = tmp < 255 ? tmp : 255;
	tmp = (double)res.green * bright * ((double)lht_rgb.green / 255) +
		(color >> 8 & 0xff);
	res.green = tmp < 255 ? tmp : 255;
	tmp = (double)res.blue * bright * ((double)lht_rgb.blue / 255) +
		(color & 0xff);
	res.blue = tmp < 255 ? tmp : 255;
	return ((res.red << 16) | (res.green << 8) | (res.blue));
}

int		shadow(t_scene g_scene, t_near dot, t_xyz light)
{
	int		shadow;
	t_xyz	ray;
	t_xyz	dot2;

	dot2 = vect_addit(dot.xyz, vect_multipl(dot.normal, 0.1));
	ray = normalize(vect_cord(dot2, light));
	shadow = shadow_pln(g_scene.pln, light, dot2, ray);
	if (!shadow)
		shadow = shadow_sph(g_scene.sph, light, dot2, ray);
	if (!shadow)
		shadow = shadow_tri(g_scene.tri, light, dot2, ray);
	if (!shadow)
		shadow = shadow_sqr(g_scene.sqr, light, dot2, ray);
	if (!shadow)
		shadow = shadow_cyl(g_scene.cyl, light, dot2, ray);
	if (!shadow)
		shadow = shadow_cub(g_scene.cub, light, dot2, ray);
	if (!shadow)
		shadow = shadow_pyr(g_scene.pyr, light, dot2, ray);
	return (shadow ? 1 : 0);
}
