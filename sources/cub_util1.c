/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util1.c                                        :+:      :+:    :+:   */
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

static t_sqr	cub_tops(t_sc sc, t_sqr sqr)
{
	sqr.t1 = square_top1(sc, sqr);
	sqr.t2 = square_top2(sc, sqr);
	sqr.t3 = square_top3(sc, sqr);
	sqr.t4 = square_top4(sc, sqr);
	return (sqr);
}

static t_sqr	cub_tops2(t_sqr sqr0)
{
	t_sqr	sqr1;

	sqr1 = sqr0;
	sqr1.pln.orient = sqr0.pln.normal;
	sqr1.pln.normal = sqr0.pln.orient;
	sqr1.t1 = vect_addit(sqr0.t1,
							vect_multipl(sqr0.pln.orient, sqr0.side));
	sqr1.t2 = vect_addit(sqr0.t2,
							vect_multipl(sqr0.pln.orient, sqr0.side));
	sqr1.t3 = vect_addit(sqr0.t3,
							vect_multipl(sqr0.pln.orient, sqr0.side));
	sqr1.t4 = vect_addit(sqr0.t4,
							vect_multipl(sqr0.pln.orient, sqr0.side));
	sqr1.pln.xyz = sqr1.t1;
	cub_triangle(&sqr1);
	return (sqr1);
}

void			cub_planes(t_cub *cub)
{
	t_sc	sc;

	while (cub)
	{
		sc = sin_cos(cub->sqr[0].pln.orient);
		cub->sqr[0] = cub_tops(sc, cub->sqr[0]);
		cub->sqr[0].pln.normal = vect_multipl(cub->sqr[0].pln.orient, -1);
		cub_triangle(&cub->sqr[0]);
		cub->sqr[1] = cub_tops2(cub->sqr[0]);
		cub_plane3(cub);
		cub_plane4(cub);
		cub_plane5(cub);
		cub_plane6(cub);
		cub = cub->next;
	}
}
