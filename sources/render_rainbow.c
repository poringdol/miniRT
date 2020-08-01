/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rainbow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:12:50 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/31 05:55:02 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_rainbow(char *save)
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
						rainbow(nearest, g_scene.lht,
							g_scene.lht_d, g_scene.cam->xyz) : BACKGROUND;
			my_mlx_pixel_put(&g_mlx, i, j, nearest.rgb);
		}
	}
	save_print(save);
}

int		rainbow(t_near dot, t_lht *lht, t_lht_d *lht_d, t_xyz cam)
{
	t_xyz	light_ray;
	int		index;
	int		color;
	double	cos_dot_light;
	double	bright;

	color = 0;
	while (lht)
	{
		light_ray = normalize(vect_cord(dot.xyz, cam));
		cos_dot_light = scal_product(dot.normal, light_ray);
		if (cos_dot_light > 0 && !shadow(g_scene, dot, lht->xyz))
		{
			bright = lht->bri * cos_dot_light;
			index = cos_dot_light * 1529.f;
			color = g_color[index];
			color = get_color(color, dot.rgb, lht->rgb, bright);
		}
		lht = lht->next;
	}
	color = directional_light(color, dot, lht_d);
	return (color);
}