/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:11:16 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:11:18 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	triangle_plane(t_tri *tri, t_xyz cam)
{
	while (tri)
	{
		tri->pln.orient = vect_product(vect_cord(tri->top1, tri->top2),
									vect_cord(tri->top1, tri->top3));
		tri->pln.normal = f_normal(tri->pln.orient, tri->top1, cam);
		tri->pln.xyz = tri->top1;
		tri->pln.rgb = tri->rgb;
		tri = tri->next;
	}
}

int		check_side(t_xyz dot, t_xyz xyz1, t_xyz xyz2, t_xyz xyz3)
{
	t_pln		pln1;
	t_pln		pln2;
	t_near		res1;
	t_near		res2;
	const t_xyz	side = vect_cord(xyz1, xyz2);

	ft_bzero(&res1, sizeof(t_near));
	ft_bzero(&res2, sizeof(t_near));
	pln1.xyz = dot;
	pln1.orient = normalize(side);
	res1 = intersect_pln(pln1, xyz1, xyz2, side);
	pln2.xyz = xyz3;
	pln2.orient = normalize(side);
	res2 = intersect_pln(pln2, xyz1, xyz2, side);
	if (res1.flag2 && res2.flag2 &&
		scal_product(vect_cord(res1.xyz, dot), vect_cord(res2.xyz, xyz3)) >= 0)
		return (1);
	return (0);
}

int		check_triangle(t_tri tri, t_xyz dot, t_near near, t_xyz cam1)
{
	if (check_side(dot, tri.top1, tri.top2, tri.top3) &&
		check_side(dot, tri.top2, tri.top3, tri.top1) &&
		check_side(dot, tri.top3, tri.top1, tri.top2) &&
		(!near.flag || vect_len(vect_cord(cam1, dot)) <
		vect_len(vect_cord(cam1, near.xyz))))
		return (1);
	return (0);
}

t_near	triangle(t_tri *tri, t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near		nearest;
	t_near		tmp;

	ft_bzero(&nearest, sizeof(t_near));
	while (tri)
	{
		tmp = intersect_pln(tri->pln, cam, cam1, ray);
		if (tmp.flag2 && check_triangle(*tri, tmp.xyz, nearest, cam1))
			nearest = tmp;
		tri = tri->next;
	}
	return (nearest);
}
