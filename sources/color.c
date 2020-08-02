/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 07:02:59 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/02 07:16:33 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int	color(t_scene scene, t_near near, int param, int i)
{
	if (!param)
		near.rgb = near.flag ? brightness(near, scene.lht, scene.lht_d) :
							BACKGROUND;
	else if (param == REFLECT)
		near.rgb = near.flag ? brightness_bonus(near, g_scene.lht,
							g_scene.lht_d, g_scene.cam->xyz) : BACKGROUND;
	else if (param == RAINBOW)
	{
		near.rgb = g_color[(int)(i *
				sqrt(scal_product(vect_cord(near.xyz, g_scene.cam->xyz),
											near.normal))) % 1529];
		near.rgb = near.flag ? brightness(near, g_scene.lht, g_scene.lht_d) :
								BACKGROUND;
	}
	else if (param == RIPPLES)
	{
		near.rgb = g_color[(int)(i *
				pow(scal_product(vect_cord(near.xyz, g_scene.cam->xyz),
											near.normal), 2)) % 1529];
		near.rgb = near.flag ? brightness(near, g_scene.lht, g_scene.lht_d) :
								BACKGROUND;
	}
	return (near.rgb);
}
