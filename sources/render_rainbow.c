/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rainbow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:12:50 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/01 06:16:35 by pdemocri         ###   ########.fr       */
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
			nearest.rgb = g_color[(int)(i *
				sqrt(scal_product(vect_cord(nearest.xyz, g_scene.cam->xyz),
											nearest.normal))) % 1529];
			nearest.rgb = nearest.flag ?
						brightness(nearest, g_scene.lht,
							g_scene.lht_d) : BACKGROUND;
			my_mlx_pixel_put(&g_mlx, i, j, nearest.rgb);
		}
	}
	save_print(save);
}
