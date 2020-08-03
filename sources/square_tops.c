/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_tops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:11:52 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 06:19:33 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

t_xyz	square_top1(t_sc sc, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x + sqr.side / 2 * sc.sin_a - sqr.side /
			2 * sc.sin_b * sc.cos_a;
	res.y = sqr.pln.xyz.y - sqr.side / 2 * sc.cos_a - sqr.side /
			2 * sc.sin_b * sc.sin_a;
	res.z = sqr.pln.xyz.z + sqr.side / 2 * sc.cos_b;
	return (res);
}

t_xyz	square_top2(t_sc sc, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x - sqr.side / 2 * sc.sin_a - sqr.side /
			2 * sc.sin_b * sc.cos_a;
	res.y = sqr.pln.xyz.y + sqr.side / 2 * sc.cos_a - sqr.side /
			2 * sc.sin_b * sc.sin_a;
	res.z = sqr.pln.xyz.z + sqr.side / 2 * sc.cos_b;
	return (res);
}

t_xyz	square_top3(t_sc sc, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x - sqr.side / 2 * sc.sin_a + sqr.side /
			2 * sc.sin_b * sc.cos_a;
	res.y = sqr.pln.xyz.y + sqr.side / 2 * sc.cos_a + sqr.side /
			2 * sc.sin_b * sc.sin_a;
	res.z = sqr.pln.xyz.z - sqr.side / 2 * sc.cos_b;
	return (res);
}

t_xyz	square_top4(t_sc sc, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x + sqr.side / 2 * sc.sin_a + sqr.side /
			2 * sc.sin_b * sc.cos_a;
	res.y = sqr.pln.xyz.y - sqr.side / 2 * sc.cos_a + sqr.side /
			2 * sc.sin_b * sc.sin_a;
	res.z = sqr.pln.xyz.z - sqr.side / 2 * sc.cos_b;
	return (res);
}

void	square_tops(t_sqr *sqr, t_xyz cam)
{
	t_sc	sc;

	while (sqr)
	{
		sc.sin_b = sqr->pln.orient.z;
		sc.cos_b = sqrt(fabs(1 - pow(sc.sin_b, 2)));
		sc.cos_a = (sc.cos_b != 0) ? sqr->pln.orient.x / sc.cos_b : 0;
		sc.sin_a = (sc.cos_b != 0) ? sqr->pln.orient.y / sc.cos_b : sc.sin_b;
		sqr->t1 = square_top1(sc, *sqr);
		sqr->t2 = square_top2(sc, *sqr);
		sqr->t3 = square_top3(sc, *sqr);
		sqr->t4 = square_top4(sc, *sqr);
		sqr->tri1.t1 = sqr->t1;
		sqr->tri1.t2 = sqr->t2;
		sqr->tri1.t3 = sqr->t3;
		sqr->tri2.t1 = sqr->t3;
		sqr->tri2.t2 = sqr->t4;
		sqr->tri2.t3 = sqr->t1;
		sqr->pln.normal = f_normal(sqr->pln.orient, sqr->pln.xyz, cam);
		sqr = sqr->next;
	}
}
