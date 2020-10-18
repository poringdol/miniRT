/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:10:35 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 06:19:33 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		shadow_pln(t_pln *pln, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	while (pln && !shadow)
	{
		intersect = intersect_pln(*pln, light, dot, ray);
		if (intersect.flag
			&& vect_len(vect_cord(light, intersect.xyz)) <
			(vect_len(vect_cord(light, dot)) - 0.1)
			&& scal_product(vect_cord(light, dot),
							vect_cord(light, intersect.xyz)) - 0.1 > 0)
			shadow++;
		pln = pln->next;
	}
	return (shadow);
}

int		shadow_sph(t_sph *sph, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	while (sph && !shadow)
	{
		intersect = intersect_sph(*sph, dot, ray);
		if (intersect.flag2 &&
		scal_product(vect_cord(dot, intersect.xyz),
					vect_cord(light, intersect.xyz)) < 0)
			shadow++;
		sph = sph->next;
	}
	return (shadow);
}

int		shadow_tri(t_tri *tri, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	while (tri && !shadow)
	{
		intersect = intersect_pln(tri->pln, light, dot, ray);
		if (intersect.flag2 &&
			is_inside_triangle(*tri, intersect.xyz) &&
			scal_product(vect_cord(intersect.xyz, dot),
						vect_cord(intersect.xyz, light)) < 0)
			shadow++;
		tri = tri->next;
	}
	return (shadow);
}

int		shadow_sqr(t_sqr *sqr, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	while (sqr && !shadow)
	{
		intersect = intersect_pln(sqr->pln, light, dot, ray);
		if (intersect.flag2 &&
			is_inside_square(*sqr, intersect.xyz) &&
			scal_product(vect_cord(intersect.xyz, dot),
						vect_cord(intersect.xyz, light)) < 0)
			shadow++;
		sqr = sqr->next;
	}
	return (shadow);
}

int		shadow_cyl(t_cyl *cyl, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	while (cyl && !shadow)
	{
		intersect = intersect_cyl(cyl, light, dot, ray);
		if (intersect.flag2
			&& vect_len(vect_cord(light, intersect.xyz)) <
			(vect_len(vect_cord(light, dot)) - 0.1)
			&& scal_product(vect_cord(light, dot),
							vect_cord(light, intersect.xyz)) - 0.1 > 0)
			shadow++;
		else if (intersect.flag &&
			scal_product(vect_cord(intersect.xyz, dot),
						vect_cord(intersect.xyz, light)) < 0)
			shadow++;
		cyl = cyl->next;
	}
	return (shadow);
}
