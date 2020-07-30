/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:54 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/30 06:11:57 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_xyz	side_orient(t_xyz xyz, double x, double y, double z)
{
	t_xyz			normal;

	normal.x = xyz.x + x;
	normal.y = xyz.y + y;
	normal.z = xyz.z + z;
	return (normal);
}

static t_sqr	side(t_sqr sqr, t_xyz orient, t_xyz dot)
{
	t_sqr			side;
	t_sc			sc;

	side.pln.xyz = dot;
	side.pln.orient = orient;
	side.pln.normal = vect_multipl(side.pln.orient, -1);
	sc.sin_b = side.pln.orient.z;
	sc.cos_b = sqrt(fabs(1 - pow(sc.sin_b, 2)));
	sc.cos_a = (sc.cos_b != 0) ? side.pln.orient.x / sc.cos_b : 0;
	sc.sin_a = (sc.cos_b != 0) ? side.pln.orient.y / sc.cos_b : sc.sin_b;
	side.side = sqr.side;
	side.pln.rgb = sqr.pln.rgb;
	square_top1(sc, side);
	square_top2(sc, side);
	square_top3(sc, side);
	square_top4(sc, side);
	return (side);
}

void			cub_sides(t_cub *cub, t_sc sc)
{
	const double	x = cub->sqr1.pln.orient.x;
	const double	y = cub->sqr1.pln.orient.y;
	const double	z = cub->sqr1.pln.orient.z;
	t_xyz			orient;

	orient = side_orient(cub->sqr1.pln.orient, x, y + 0, z + 0);
	cub->sqr2 = side(cub->sqr1, orient,
				vect_addit(cub->sqr1.pln.xyz,
				vect_multipl(orient, -1 * cub->sqr1.side)));
	orient = side_orient(cub->sqr1.pln.orient, x + 0, y + 0, z + 0);
	cub->sqr3 = side(cub->sqr1, orient,
				vect_addit(cub->sqr1.pln.xyz,
				vect_multipl(orient, -1 * cub->sqr1.side)));
	orient = side_orient(cub->sqr1.pln.orient, x + 0, y + 0, z + 0);
	cub->sqr4 = side(cub->sqr1, orient,
				vect_addit(cub->sqr1.pln.xyz,
				vect_multipl(orient, -1 * cub->sqr1.side)));
	orient = side_orient(cub->sqr1.pln.orient, x + 0, y + 0, z + 0);
	cub->sqr5 = side(cub->sqr1, orient,
				vect_addit(cub->sqr1.pln.xyz,
				vect_multipl(orient, -1 * cub->sqr1.side)));
	orient = side_orient(cub->sqr1.pln.orient, x + 0, y + 0, z + 0);
	cub->sqr6 = side(cub->sqr1, orient,
				vect_addit(cub->sqr1.pln.xyz,
				vect_multipl(orient, -1 * cub->sqr1.side)));
}

void			cub_tops(t_cub *cub, t_xyz cam)
{
	t_sc			sc;

	while (cub)
	{
		sc.sin_b = cub->sqr1.pln.orient.z;
		sc.cos_b = sqrt(fabs(1 - pow(sc.sin_b, 2)));
		sc.cos_a = (sc.cos_b != 0) ? cub->sqr1.pln.orient.x / sc.cos_b : 0;
		sc.sin_a = (sc.cos_b != 0) ?
					cub->sqr1.pln.orient.y / sc.cos_b : sc.sin_b;
		cub->sqr1.top1 = square_top1(sc, cub->sqr1);
		cub->sqr1.top2 = square_top2(sc, cub->sqr1);
		cub->sqr1.top3 = square_top3(sc, cub->sqr1);
		cub->sqr1.top4 = square_top4(sc, cub->sqr1);
		cub->sqr1.tri1.top1 = cub->sqr1.top1;
		cub->sqr1.tri1.top2 = cub->sqr1.top2;
		cub->sqr1.tri1.top3 = cub->sqr1.top3;
		cub->sqr1.tri2.top1 = cub->sqr1.top3;
		cub->sqr1.tri2.top2 = cub->sqr1.top4;
		cub->sqr1.tri2.top3 = cub->sqr1.top1;
		cub->sqr1.pln.normal = vect_multipl(cub->sqr1.pln.orient, -1);
		cub->o = vect_addit(cub->sqr1.pln.xyz,
				vect_multipl(cub->sqr1.pln.normal, cub->sqr1.side / 2));
		cub_sides(cub, sc);
		cub = cub->next;
	}
}
