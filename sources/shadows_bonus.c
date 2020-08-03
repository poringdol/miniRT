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
	t_near	inter;
	int		shadow;

	shadow = 0;
	inter = intersect_pln(pyr->sqr.pln, light, dot, ray);
	if (inter.flag2 &&
		((check_s(inter.xyz, pyr->sqr.t1, pyr->sqr.t2, pyr->sqr.t3) &&
		check_s(inter.xyz, pyr->sqr.t2, pyr->sqr.t3, pyr->sqr.t1) &&
		check_s(inter.xyz, pyr->sqr.t3, pyr->sqr.t1, pyr->sqr.t2)) ||
		(check_s(inter.xyz, pyr->sqr.t1, pyr->sqr.t3, pyr->sqr.t4) &&
		check_s(inter.xyz, pyr->sqr.t3, pyr->sqr.t4, pyr->sqr.t1) &&
		check_s(inter.xyz, pyr->sqr.t4, pyr->sqr.t1, pyr->sqr.t3))) &&
		scal_product(vect_cord(inter.xyz, dot),
					vect_cord(inter.xyz, light)) < 0)
		shadow++;
	return (shadow);
}

int			shadow_pyr(t_pyr *p, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	itr;
	int		shadow;
	int		i;

	shadow = 0;
	i = -1;
	while (p && !shadow)
	{
		shadow = shadow_pyr_sqr(p, light, dot, ray) ? 1 : 0;
		while (!shadow && ++i < 4)
		{
			itr = intersect_pln(p->tri[i].pln, light, dot, ray);
			if (itr.flag2 &&
				check_s(itr.xyz, p->tri[i].t1, p->tri[i].t2, p->tri[i].t3) &&
				check_s(itr.xyz, p->tri[i].t2, p->tri[i].t3, p->tri[i].t1) &&
				check_s(itr.xyz, p->tri[i].t3, p->tri[i].t1, p->tri[i].t2) &&
				scal_product(vect_cord(itr.xyz, dot),
							vect_cord(itr.xyz, light)) < 0)
				shadow++;
		}
		p = p->next;
	}
	return (shadow);
}

int			shadow_cub(t_cub *c, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	inter;
	int		shadow;
	int		i;

	shadow = 0;
	i = -1;
	while (c && !shadow)
	{
		while (++i < 6 && !shadow)
		{
			inter = intersect_pln(c->sqr[0].pln, light, dot, ray);
			if (inter.flag2 &&
			((check_s(inter.xyz, c->sqr[i].t1, c->sqr[i].t2, c->sqr[i].t3) &&
			check_s(inter.xyz, c->sqr[i].t2, c->sqr[i].t3, c->sqr[i].t1) &&
			check_s(inter.xyz, c->sqr[i].t3, c->sqr[i].t1, c->sqr[i].t2)) ||
			(check_s(inter.xyz, c->sqr[i].t1, c->sqr[i].t3, c->sqr[i].t4) &&
			check_s(inter.xyz, c->sqr[i].t3, c->sqr[i].t4, c->sqr[i].t1) &&
			check_s(inter.xyz, c->sqr[i].t4, c->sqr[i].t1, c->sqr[i].t3))) &&
			scal_product(vect_cord(inter.xyz, dot),
			vect_cord(inter.xyz, light)) < 0)
				shadow++;
		}
		c = c->next;
	}
	return (shadow);
}
