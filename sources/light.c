#include "minirt.h"

int	brightness(t_near dot, t_lht *lht)
{
	t_rgb	rgb;
	t_xyz	light_ray;
	double	n_dot;
	double	bright;

	bright = g_scene.amb.lht_rat;
	rgb.red = dot.rgb >> 16;
	rgb.green = dot.rgb >> 8 & 0xff;
	rgb.blue = dot.rgb & 0xff;
	while (lht)
	{
		light_ray = vect_cord(dot.xyz, lht->xyz);
		n_dot = (scalar(dot.normal, light_ray));
		if (n_dot > 0)
			bright += lht->bri * (n_dot / (vect_len(dot.normal) * vect_len(light_ray)));
		lht = lht->next;
	}
	rgb.red = ((float)rgb.red * bright) < 255 ? ((float)rgb.red * bright) : 255;
	rgb.green = ((float)rgb.green * bright) < 255 ? ((float)rgb.green * bright) : 255;
	rgb.blue = ((float)rgb.blue * bright) < 255 ? ((float)rgb.blue * bright) : 255;
	return ((rgb.red << 16) | (rgb.green << 8) | (rgb.blue));
}