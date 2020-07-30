/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:12:52 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/30 07:19:45 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_utils(void)
{
	create_canvas(&g_scene.canvas, g_scene.cam, g_scene.res);
	square_tops(g_scene.sqr, g_scene.cam->xyz);
	triangle_plane(g_scene.tri, g_scene.cam->xyz);
	plane_normal(g_scene.pln, g_scene.cam->xyz);
}

/*
**cub_tops(g_scene.cub, g_scene.cam->xyz);
*/
