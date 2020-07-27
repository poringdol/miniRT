/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_tops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:11:52 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:11:53 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

static t_xyz	top1(t_sc sc, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x + sqr.side / 2 * sc.sin_a - sqr.side /
			2 * sc.sin_b * sc.cos_a;
	res.y = sqr.pln.xyz.y - sqr.side / 2 * sc.cos_a - sqr.side /
			2 * sc.sin_b * sc.sin_a;
	res.z = sqr.pln.xyz.z + sqr.side / 2 * sc.cos_b;
	return (res);
}

static t_xyz	top2(t_sc sc, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x - sqr.side / 2 * sc.sin_a - sqr.side /
			2 * sc.sin_b * sc.cos_a;
	res.y = sqr.pln.xyz.y + sqr.side / 2 * sc.cos_a - sqr.side /
			2 * sc.sin_b * sc.sin_a;
	res.z = sqr.pln.xyz.z + sqr.side / 2 * sc.cos_b;
	return (res);
}

static t_xyz	top3(t_sc sc, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x - sqr.side / 2 * sc.sin_a + sqr.side /
			2 * sc.sin_b * sc.cos_a;
	res.y = sqr.pln.xyz.y + sqr.side / 2 * sc.cos_a + sqr.side /
			2 * sc.sin_b * sc.sin_a;
	res.z = sqr.pln.xyz.z - sqr.side / 2 * sc.cos_b;
	return (res);
}

static t_xyz	top4(t_sc sc, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x + sqr.side / 2 * sc.sin_a + sqr.side /
			2 * sc.sin_b * sc.cos_a;
	res.y = sqr.pln.xyz.y - sqr.side / 2 * sc.cos_a + sqr.side /
			2 * sc.sin_b * sc.sin_a;
	res.z = sqr.pln.xyz.z - sqr.side / 2 * sc.cos_b;
	return (res);
}

void			square_tops(t_sqr *sqr, t_xyz cam)
{
	t_sc	sc;

	while (sqr)
	{
		sc.sin_b = sqr->pln.orient.z;
		sc.cos_b = sqrt(fabs(1 - pow(sc.sin_b, 2)));
		sc.cos_a = (sc.cos_b != 0) ? sqr->pln.orient.x / sc.cos_b : 0;
		sc.sin_a = (sc.cos_b != 0) ? sqr->pln.orient.y / sc.cos_b : sc.sin_b;
		sqr->top1 = top1(sc, *sqr);
		sqr->top2 = top2(sc, *sqr);
		sqr->top3 = top3(sc, *sqr);
		sqr->top4 = top4(sc, *sqr);
		sqr->tri1.top1 = sqr->top1;
		sqr->tri1.top2 = sqr->top2;
		sqr->tri1.top3 = sqr->top3;
		sqr->tri2.top1 = sqr->top3;
		sqr->tri2.top2 = sqr->top4;
		sqr->tri2.top3 = sqr->top1;
		sqr->pln.normal = f_normal(sqr->pln.orient, sqr->pln.xyz, cam);
		sqr = sqr->next;
	}
}
