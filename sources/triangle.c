/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:11:16 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 06:19:33 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	triangle_plane(t_tri *tri, t_xyz cam)
{
	while (tri)
	{
		tri->pln.orient = vect_product(vect_cord(tri->t1, tri->t2),
									vect_cord(tri->t1, tri->t3));
		tri->pln.normal = f_normal(tri->pln.orient, tri->t1, cam);
		tri->pln.xyz = tri->t1;
		tri->pln.rgb = tri->rgb;
		tri = tri->next;
	}
}

int		is_inside_triangle(t_tri tri, t_xyz dot)
{
	t_xyz	a;
	t_xyz	b;
	t_xyz	c;

	a = vect_cord(tri.t2, tri.t1);
	b = vect_cord(tri.t3, tri.t2);
	c = vect_cord(tri.t1, tri.t3);
	if (scal_product(vect_product(a, vect_cord(dot, tri.t1)),
					vect_product(b, vect_cord(dot, tri.t2))) > 0 &&
		scal_product(vect_product(b, vect_cord(dot, tri.t2)),
					vect_product(c, vect_cord(dot, tri.t3))) > 0)
		return (1);
	return (0);
}

int		check_s(t_xyz dot, t_xyz xyz1, t_xyz xyz2, t_xyz xyz3)
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
	if (is_inside_triangle(tri, dot) &&
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
