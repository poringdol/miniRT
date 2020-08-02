/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:12:41 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/01 08:27:03 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_near	nearest_pix_bonus(t_xyz cam, t_xyz cam1, t_xyz ray, t_near nearest)
{
	t_near		tmp;

	bzero(&tmp, sizeof(t_near));
	tmp = cub(g_scene.cub, *g_scene.cam, cam1, ray);
	nearest = ((tmp.flag2) &&
		(!nearest.flag || vect_len(vect_cord(cam, tmp.xyz)) <
		vect_len(vect_cord(cam, nearest.xyz)))) ? tmp : nearest;
	tmp = pyramid(g_scene.pyr, *g_scene.cam, cam1, ray);
	nearest = ((tmp.flag2) &&
		(!nearest.flag || vect_len(vect_cord(cam, tmp.xyz)) <
		vect_len(vect_cord(cam, nearest.xyz)))) ? tmp : nearest;
	return (nearest);
}
