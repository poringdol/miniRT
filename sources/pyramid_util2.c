/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:54 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/02 04:58:20 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pyr_plane1(t_pyr *pyr)
{
	pyr->tri1.pln.rgb = pyr->sqr.pln.rgb;
	pyr->tri1.top1 = pyr->sqr.top1;
	pyr->tri1.top2 = pyr->sqr.top2;
	pyr->tri1.top3 = pyr->top;
	pyr->tri1.pln.xyz = pyr->top;
	pyr->tri1.pln.orient = vect_product(vect_cord(pyr->tri1.top1,
													pyr->tri1.top2),
										vect_cord(pyr->tri1.top1,
													pyr->top));
	pyr->tri1.pln.orient = normalize(pyr->tri1.pln.orient);
	pyr->tri1.pln.normal = vect_multipl(pyr->tri1.pln.orient, -1);
}

void	pyr_plane2(t_pyr *pyr)
{
	pyr->tri2.pln.rgb = pyr->sqr.pln.rgb;
	pyr->tri2.top1 = pyr->sqr.top2;
	pyr->tri2.top2 = pyr->sqr.top3;
	pyr->tri2.top3 = pyr->top;
	pyr->tri2.pln.xyz = pyr->top;
	pyr->tri2.pln.orient = vect_product(vect_cord(pyr->tri2.top1,
													pyr->tri2.top2),
										vect_cord(pyr->tri2.top1,
													pyr->top));
	pyr->tri2.pln.orient = normalize(pyr->tri2.pln.orient);
	pyr->tri2.pln.normal = vect_multipl(pyr->tri2.pln.orient, -1);
}

void	pyr_plane3(t_pyr *pyr)
{
	pyr->tri3.pln.rgb = pyr->sqr.pln.rgb;
	pyr->tri3.top1 = pyr->sqr.top3;
	pyr->tri3.top2 = pyr->sqr.top4;
	pyr->tri3.top3 = pyr->top;
	pyr->tri3.pln.xyz = pyr->top;
	pyr->tri3.pln.orient = vect_product(vect_cord(pyr->tri3.top1,
													pyr->tri3.top2),
										vect_cord(pyr->tri3.top1,
													pyr->top));
	pyr->tri3.pln.orient = normalize(pyr->tri3.pln.orient);
	pyr->tri3.pln.normal = vect_multipl(pyr->tri3.pln.orient, -1);
}

void	pyr_plane4(t_pyr *pyr)
{
	pyr->tri4.pln.rgb = pyr->sqr.pln.rgb;
	pyr->tri4.top1 = pyr->sqr.top4;
	pyr->tri4.top2 = pyr->sqr.top1;
	pyr->tri4.top3 = pyr->top;
	pyr->tri4.pln.xyz = pyr->top;
	pyr->tri4.pln.orient = vect_product(vect_cord(pyr->tri4.top1,
													pyr->tri4.top2),
										vect_cord(pyr->tri4.top1,
													pyr->top));
	pyr->tri4.pln.orient = normalize(pyr->tri4.pln.orient);
	pyr->tri4.pln.normal = vect_multipl(pyr->tri4.pln.orient, -1);
}
