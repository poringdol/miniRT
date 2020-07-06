#include "minirt.h"

int		brightness(t_near dot, t_lht *lht)
{
	t_xyz	light_ray;
	int		color;
	double	n_dot;
	double	bright;

	color = get_color(0, dot.rgb, g_scene.amb.rgb, g_scene.amb.lht_rat);
	t_rgb rgb;
	rgb.red = color >> 16;
	rgb.green = color >> 8 & 0xff;
	rgb.blue = color & 0xff;
	if (!sizeof(rgb)) return 0;
	while (lht)
	{
		light_ray = vect_cord(dot.xyz, lht->xyz);
		n_dot = (scalar(dot.normal, light_ray));
		if (n_dot > 0 && !shadow(g_scene, dot, lht->xyz))
		{
			bright = lht->bri * (n_dot / (vect_len(dot.normal) *
				vect_len(light_ray)));
			color = get_color(color, dot.rgb, lht->rgb, bright);
		}
		lht = lht->next;
	}
	return (color);
}

int		get_color(int color, int rgb, int light_color, double bright)
{
	t_rgb	res;
	t_rgb	lht_rgb;

	res.red = rgb >> 16;
	res.green = rgb >> 8 & 0xff;
	res.blue = rgb & 0xff;
	lht_rgb.red = light_color >> 16;
	lht_rgb.green = light_color >> 8 & 0xff;
	lht_rgb.blue = light_color & 0xff;
	res.red = (float)res.red * bright * ((float)lht_rgb.red / 255) +
		(color >> 16);
	res.red = res.red < 255 ? res.red : 255;
	res.green = (float)res.green * bright * ((float)lht_rgb.green / 255) +
		(color >> 8 & 0xff);
	res.green = res.green < 255 ? res.green : 255;
	res.blue = (float)res.blue * bright * ((float)lht_rgb.blue / 255) +
		(color & 0xff);
	res.blue = res.blue < 255 ? res.blue : 255;
	return ((res.red << 16) | (res.green << 8) | (res.blue));
}

int		shadow(t_scene g_scene, t_near dot, t_xyz light)
{
	int		shadow;
	t_xyz	ray;
	// t_xyz	dot1;

	dot.xyz.x += dot.normal.x;
	dot.xyz.y += dot.normal.y;
	dot.xyz.z += dot.normal.z;
	ray = normalize(vect_cord(dot.xyz, light));
	// dot1.x = dot.xyz.x + ray.x;
	// dot1.y = dot.xyz.y + ray.y;
	// dot1.z = dot.xyz.z + ray.z;
	shadow = shadow_pln(g_scene.pln, dot.xyz, light, ray);
	if (!shadow)
		shadow = shadow_sph(g_scene.sph, dot.xyz, ray, shadow);
	return (shadow ? 1 : 0);
}