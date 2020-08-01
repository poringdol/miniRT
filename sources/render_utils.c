/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:12:52 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/01 05:38:35 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	color_table(void)
{
	int		i;
	t_rgb	rgb;

	if (g_color[0])
		return ;
	i = 0;
	ft_bzero(&rgb, sizeof(rgb));
	rgb.red = 255;
	while (rgb.green < 255)
		g_color[i++] = (rgb.red << 16) | (++rgb.green << 8) | rgb.blue;
	g_color[i++] = (rgb.red << 16) | (rgb.green << 8) | rgb.blue;
	while (rgb.red)
		g_color[i++] = (--rgb.red << 16) | (rgb.green << 8) | rgb.blue;
	while (rgb.blue < 255)
		g_color[i++] = (rgb.red << 16) | (rgb.green << 8) | ++rgb.blue;
	while (rgb.green)
		g_color[i++] = (rgb.red << 16) | (--rgb.green << 8) | rgb.blue;
	while (rgb.red < 255)
		g_color[i++] = (++rgb.red << 16) | (rgb.green << 8) | rgb.blue;
	while (rgb.blue > 1)
		g_color[i++] = (rgb.red << 16) | (rgb.green << 8) | --rgb.blue;
}

void	render_utils(void)
{
	create_canvas(&g_scene.canvas, g_scene.cam, g_scene.res);
	square_tops(g_scene.sqr, g_scene.cam->xyz);
	triangle_plane(g_scene.tri, g_scene.cam->xyz);
	plane_normal(g_scene.pln, g_scene.cam->xyz);
	cub_planes(g_scene.cub);
	color_table();
}
