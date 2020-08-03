/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:54 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 06:19:33 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pyr_plane1(t_pyr *pyr)
{
	pyr->tri[0].pln.rgb = pyr->sqr.pln.rgb;
	pyr->tri[0].t1 = pyr->sqr.t1;
	pyr->tri[0].t2 = pyr->sqr.t2;
	pyr->tri[0].t3 = pyr->top;
	pyr->tri[0].pln.xyz = pyr->top;
	pyr->tri[0].pln.orient = vect_product(vect_cord(pyr->tri[0].t1,
													pyr->tri[0].t2),
										vect_cord(pyr->tri[0].t1,
													pyr->top));
	pyr->tri[0].pln.orient = normalize(pyr->tri[0].pln.orient);
	pyr->tri[0].pln.normal = vect_multipl(pyr->tri[0].pln.orient, -1);
}

void	pyr_plane2(t_pyr *pyr)
{
	pyr->tri[1].pln.rgb = pyr->sqr.pln.rgb;
	pyr->tri[1].t1 = pyr->sqr.t2;
	pyr->tri[1].t2 = pyr->sqr.t3;
	pyr->tri[1].t3 = pyr->top;
	pyr->tri[1].pln.xyz = pyr->top;
	pyr->tri[1].pln.orient = vect_product(vect_cord(pyr->tri[1].t1,
													pyr->tri[1].t2),
										vect_cord(pyr->tri[1].t1,
													pyr->top));
	pyr->tri[1].pln.orient = normalize(pyr->tri[1].pln.orient);
	pyr->tri[1].pln.normal = vect_multipl(pyr->tri[1].pln.orient, -1);
}

void	pyr_plane3(t_pyr *pyr)
{
	pyr->tri[2].pln.rgb = pyr->sqr.pln.rgb;
	pyr->tri[2].t1 = pyr->sqr.t3;
	pyr->tri[2].t2 = pyr->sqr.t4;
	pyr->tri[2].t3 = pyr->top;
	pyr->tri[2].pln.xyz = pyr->top;
	pyr->tri[2].pln.orient = vect_product(vect_cord(pyr->tri[2].t1,
													pyr->tri[2].t2),
										vect_cord(pyr->tri[2].t1,
													pyr->top));
	pyr->tri[2].pln.orient = normalize(pyr->tri[2].pln.orient);
	pyr->tri[2].pln.normal = vect_multipl(pyr->tri[2].pln.orient, -1);
}

void	pyr_plane4(t_pyr *pyr)
{
	pyr->tri[3].pln.rgb = pyr->sqr.pln.rgb;
	pyr->tri[3].t1 = pyr->sqr.t4;
	pyr->tri[3].t2 = pyr->sqr.t1;
	pyr->tri[3].t3 = pyr->top;
	pyr->tri[3].pln.xyz = pyr->top;
	pyr->tri[3].pln.orient = vect_product(vect_cord(pyr->tri[3].t1,
													pyr->tri[3].t2),
										vect_cord(pyr->tri[3].t1,
													pyr->top));
	pyr->tri[3].pln.orient = normalize(pyr->tri[3].pln.orient);
	pyr->tri[3].pln.normal = vect_multipl(pyr->tri[3].pln.orient, -1);
}
