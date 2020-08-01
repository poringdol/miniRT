/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:54 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/01 03:13:27 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			cub_triangle(t_sqr *sqr)
{
	sqr->tri1.top1 = sqr->top1;
	sqr->tri1.top2 = sqr->top2;
	sqr->tri1.top3 = sqr->top3;
	sqr->tri2.top1 = sqr->top3;
	sqr->tri2.top2 = sqr->top4;
	sqr->tri2.top3 = sqr->top1;
}

void			cub_plane3(t_cub *cub)
{
	cub->sqr3 = cub->sqr1;
	cub->sqr3.pln.xyz = cub->sqr1.top1;
	cub->sqr3.pln.orient = vect_product(vect_cord(cub->sqr1.top1,
												cub->sqr2.top2),
										vect_cord(cub->sqr1.top2,
												cub->sqr2.top1));
	cub->sqr3.pln.orient = normalize(cub->sqr3.pln.orient);
	cub->sqr3.pln.normal = vect_multipl(cub->sqr3.pln.orient, -1);
	cub->sqr3.top1 = cub->sqr1.top1;
	cub->sqr3.top2 = cub->sqr1.top2;
	cub->sqr3.top3 = cub->sqr2.top2;
	cub->sqr3.top4 = cub->sqr2.top1;
	cub_triangle(&cub->sqr3);
}

void			cub_plane4(t_cub *cub)
{
	cub->sqr4 = cub->sqr1;
	cub->sqr4.pln.xyz = cub->sqr1.top2;
	cub->sqr4.pln.orient = vect_product(vect_cord(cub->sqr1.top2,
												cub->sqr2.top3),
										vect_cord(cub->sqr1.top3,
												cub->sqr2.top2));
	cub->sqr4.pln.orient = normalize(cub->sqr4.pln.orient);
	cub->sqr4.pln.normal = vect_multipl(cub->sqr4.pln.orient, -1);
	cub->sqr4.top1 = cub->sqr1.top2;
	cub->sqr4.top2 = cub->sqr1.top3;
	cub->sqr4.top3 = cub->sqr2.top3;
	cub->sqr4.top4 = cub->sqr2.top2;
	cub_triangle(&cub->sqr4);
}

void			cub_plane5(t_cub *cub)
{
	cub->sqr5 = cub->sqr1;
	cub->sqr5.pln.xyz = cub->sqr1.top3;
	cub->sqr5.pln.orient = cub->sqr3.pln.normal;
	cub->sqr5.pln.normal = cub->sqr3.pln.orient;
	cub->sqr5.top1 = cub->sqr1.top3;
	cub->sqr5.top2 = cub->sqr1.top4;
	cub->sqr5.top3 = cub->sqr2.top4;
	cub->sqr5.top4 = cub->sqr2.top3;
	cub_triangle(&cub->sqr5);
}

void			cub_plane6(t_cub *cub)
{
	cub->sqr6 = cub->sqr1;
	cub->sqr6.pln.xyz = cub->sqr1.top4;
	cub->sqr6.pln.orient = cub->sqr4.pln.normal;
	cub->sqr6.pln.normal = cub->sqr4.pln.orient;
	cub->sqr6.top1 = cub->sqr1.top4;
	cub->sqr6.top2 = cub->sqr1.top1;
	cub->sqr6.top3 = cub->sqr2.top1;
	cub->sqr6.top4 = cub->sqr2.top4;
	cub_triangle(&cub->sqr6);
}
