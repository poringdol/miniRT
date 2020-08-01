/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:54 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/01 03:32:09 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_sc		sin_cos(t_xyz orient)
{
	t_sc		sc;

	sc.sin_b = orient.z;
	sc.cos_b = sqrt(fabs(1 - pow(sc.sin_b, 2)));
	sc.cos_a = (sc.cos_b != 0) ? orient.x / sc.cos_b : 0;
	sc.sin_a = (sc.cos_b != 0) ? orient.y / sc.cos_b : sc.sin_b;
	return (sc);
}

static t_sqr	cub_tops(t_sc sc, t_sqr sqr)
{
	sqr.top1 = square_top1(sc, sqr);
	sqr.top2 = square_top2(sc, sqr);
	sqr.top3 = square_top3(sc, sqr);
	sqr.top4 = square_top4(sc, sqr);
	return (sqr);
}

static t_sqr	cub_tops2(t_sqr sqr1)
{
	t_sqr sqr2;

	sqr2 = sqr1;
	sqr2.pln.orient = sqr1.pln.normal;
	sqr2.pln.normal = sqr1.pln.orient;
	sqr2.top1 = vect_addit(sqr1.top1,
							vect_multipl(sqr1.pln.orient, sqr1.side));
	sqr2.top2 = vect_addit(sqr1.top2,
							vect_multipl(sqr1.pln.orient, sqr1.side));
	sqr2.top3 = vect_addit(sqr1.top3,
							vect_multipl(sqr1.pln.orient, sqr1.side));
	sqr2.top4 = vect_addit(sqr1.top4,
							vect_multipl(sqr1.pln.orient, sqr1.side));
	sqr2.pln.xyz = sqr2.top1;
	cub_triangle(&sqr2);
	return (sqr2);
}

void			cub_planes(t_cub *cub)
{
	t_sc 		sc;

	while (cub)
	{
		sc = sin_cos(cub->sqr1.pln.orient);
		cub->sqr1 = cub_tops(sc, cub->sqr1);
		cub->sqr1.pln.normal = vect_multipl(cub->sqr1.pln.orient, -1);
		cub_triangle(&cub->sqr1);
		cub->sqr2 = cub_tops2(cub->sqr1);
		cub_plane3(cub);
		cub_plane4(cub);
		cub_plane5(cub);
		cub_plane6(cub);
		cub = cub->next;
	}
}
