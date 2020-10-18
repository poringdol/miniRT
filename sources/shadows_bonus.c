/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:10:35 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 07:02:04 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	shadow_pyr_sqr(t_pyr *pyr, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	intersect = intersect_pln(pyr->sqr.pln, light, dot, ray);
	if (intersect.flag2 &&
		is_inside_square(pyr->sqr, intersect.xyz) &&
		scal_product(vect_cord(intersect.xyz, dot),
					vect_cord(intersect.xyz, light)) < 0)
		shadow++;
	return (shadow);
}

int			shadow_pyr(t_pyr *pyr, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;
	int		i;

	shadow = 0;
	i = -1;
	while (pyr && !shadow)
	{
		shadow = shadow_pyr_sqr(pyr, light, dot, ray) ? 1 : 0;
		while (!shadow && ++i < 4)
		{
			intersect = intersect_pln(pyr->tri[i].pln, light, dot, ray);
			if (intersect.flag2 &&
				is_inside_triangle(pyr->tri[i], intersect.xyz) &&
				scal_product(vect_cord(intersect.xyz, dot),
							vect_cord(intersect.xyz, light)) < 0)
				shadow++;
		}
		pyr = pyr->next;
	}
	return (shadow);
}

int			shadow_cub(t_cub *cub, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;
	int		i;

	shadow = 0;
	i = -1;
	while (cub && !shadow)
	{
		while (++i < 6 && !shadow)
		{
			intersect = intersect_pln(cub->sqr[0].pln, light, dot, ray);
			if (intersect.flag2 &&
			is_inside_square(cub->sqr[0], intersect.xyz) &&
			scal_product(vect_cord(intersect.xyz, dot),
			vect_cord(intersect.xyz, light)) < 0)
				shadow++;
		}
		cub = cub->next;
	}
	return (shadow);
}
