/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_antialising.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:12:50 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/31 01:08:51 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_antialiasing(char *save)
{
	int		i;
	int		j;
	t_xyz	cam1;
	t_xyz	ray;
	t_near	nearest;

	j = -1;
	while (++j < g_scene.res.height)
	{
		i = -1;
		while (++i < g_scene.res.width)
		{
			cam1 = vect_end(g_scene.canvas, g_scene.res, i, j);
			ray = normalize(vect_cord(g_scene.cam->xyz, cam1));
			nearest = nearest_pix(g_scene.cam->xyz, cam1, ray);
			nearest.rgb = nearest.flag ?
						brightness_bonus(nearest, g_scene.lht,
							g_scene.lht_d, g_scene.cam->xyz) : BACKGROUND;
			my_mlx_pixel_put(&g_mlx, i, j, nearest.rgb);
		}
	}
	save_print(save);
}

int		brightness_bonus(t_near dot, t_lht *lht, t_lht_d *lht_d, t_xyz cam)
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
			color = reflect_light(color, dot, light_ray, cam);
		}
		lht = lht->next;
	}
	color = directional_light(color, dot, lht_d);
	return (color);
}

int		reflect_light(int color, t_near dot, t_xyz light, t_xyz cam)
{
	t_xyz	reflect;
	double	rate;
	t_rgb	res;
	int		tmp;

	reflect = normalize(vect_cord(light, vect_multipl(dot.normal, 2 *
				scal_product(dot.normal, light))));
	rate = scal_product(reflect, normalize(vect_cord(dot.xyz, cam)));
	if (rate < 0)
		return (color);
	tmp = (color >> 16) + (color >> 16) * pow(rate, SHINE);
	res.red = tmp < 255 ? tmp : 255;
	tmp = (color >> 8 & 0xff) + (color >> 8 & 0xff) * pow(rate, SHINE);
	res.green = tmp < 255 ? tmp : 255;
	tmp = (color & 0xff) + (color & 0xff) * pow(rate, SHINE);
	res.blue = tmp < 255 ? tmp : 255;
	return ((res.red << 16) | (res.green << 8) | (res.blue));
}

