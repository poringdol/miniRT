/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:54 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 06:19:33 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_sc		sin_cos(t_xyz orient)
{
	t_sc	sc;

	sc.sin_b = orient.z;
	sc.cos_b = sqrt(fabs(1 - pow(sc.sin_b, 2)));
	sc.cos_a = (sc.cos_b != 0) ? orient.x / sc.cos_b : 0;
	sc.sin_a = (sc.cos_b != 0) ? orient.y / sc.cos_b : sc.sin_b;
	return (sc);
}

static t_sqr	pyr_square(t_sc sc, t_sqr sqr)
{
	sqr.t1 = square_top1(sc, sqr);
	sqr.t2 = square_top2(sc, sqr);
	sqr.t3 = square_top3(sc, sqr);
	sqr.t4 = square_top4(sc, sqr);
	sqr.tri1.t1 = sqr.t1;
	sqr.tri1.t2 = sqr.t2;
	sqr.tri1.t3 = sqr.t3;
	sqr.tri2.t1 = sqr.t3;
	sqr.tri2.t2 = sqr.t4;
	sqr.tri2.t3 = sqr.t1;
	sqr.tri1.pln.normal = sqr.pln.normal;
	sqr.tri1.pln.xyz = sqr.tri1.t1;
	sqr.tri2.pln.normal = sqr.pln.normal;
	sqr.tri2.pln.xyz = sqr.tri2.t1;
	return (sqr);
}

void			pyramid_planes(t_pyr *pyr)
{
	t_sc	sc;

	while (pyr)
	{
		sc = sin_cos(pyr->sqr.pln.orient);
		pyr->sqr = pyr_square(sc, pyr->sqr);
		pyr->sqr.pln.normal = vect_multipl(pyr->sqr.pln.orient, -1);
		pyr->top = vect_addit(pyr->sqr.pln.xyz,
							vect_multipl(pyr->sqr.pln.orient, pyr->height));
		pyr_plane1(pyr);
		pyr_plane2(pyr);
		pyr_plane3(pyr);
		pyr_plane4(pyr);
		pyr = pyr->next;
	}
}
