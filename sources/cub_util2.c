/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:11:54 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 06:19:33 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			cub_triangle(t_sqr *sqr)
{
	sqr->tri1.t1 = sqr->t1;
	sqr->tri1.t2 = sqr->t2;
	sqr->tri1.t3 = sqr->t3;
	sqr->tri2.t1 = sqr->t3;
	sqr->tri2.t2 = sqr->t4;
	sqr->tri2.t3 = sqr->t1;
}

void			cub_plane3(t_cub *cub)
{
	cub->sqr[2] = cub->sqr[0];
	cub->sqr[2].pln.xyz = cub->sqr[0].t1;
	cub->sqr[2].pln.orient = vect_product(vect_cord(cub->sqr[0].t1,
												cub->sqr[1].t2),
										vect_cord(cub->sqr[0].t2,
												cub->sqr[1].t1));
	cub->sqr[2].pln.orient = normalize(cub->sqr[2].pln.orient);
	cub->sqr[2].pln.normal = vect_multipl(cub->sqr[2].pln.orient, -1);
	cub->sqr[2].t1 = cub->sqr[0].t1;
	cub->sqr[2].t2 = cub->sqr[0].t2;
	cub->sqr[2].t3 = cub->sqr[1].t2;
	cub->sqr[2].t4 = cub->sqr[1].t1;
	cub_triangle(&cub->sqr[2]);
}

void			cub_plane4(t_cub *cub)
{
	cub->sqr[3] = cub->sqr[0];
	cub->sqr[3].pln.xyz = cub->sqr[0].t2;
	cub->sqr[3].pln.orient = vect_product(vect_cord(cub->sqr[0].t2,
												cub->sqr[1].t3),
										vect_cord(cub->sqr[0].t3,
												cub->sqr[1].t2));
	cub->sqr[3].pln.orient = normalize(cub->sqr[3].pln.orient);
	cub->sqr[3].pln.normal = vect_multipl(cub->sqr[3].pln.orient, -1);
	cub->sqr[3].t1 = cub->sqr[0].t2;
	cub->sqr[3].t2 = cub->sqr[0].t3;
	cub->sqr[3].t3 = cub->sqr[1].t3;
	cub->sqr[3].t4 = cub->sqr[1].t2;
	cub_triangle(&cub->sqr[3]);
}

void			cub_plane5(t_cub *cub)
{
	cub->sqr[4] = cub->sqr[0];
	cub->sqr[4].pln.xyz = cub->sqr[0].t3;
	cub->sqr[4].pln.orient = cub->sqr[2].pln.normal;
	cub->sqr[4].pln.normal = cub->sqr[2].pln.orient;
	cub->sqr[4].t1 = cub->sqr[0].t3;
	cub->sqr[4].t2 = cub->sqr[0].t4;
	cub->sqr[4].t3 = cub->sqr[1].t4;
	cub->sqr[4].t4 = cub->sqr[1].t3;
	cub_triangle(&cub->sqr[4]);
}

void			cub_plane6(t_cub *cub)
{
	cub->sqr[5] = cub->sqr[0];
	cub->sqr[5].pln.xyz = cub->sqr[0].t4;
	cub->sqr[5].pln.orient = cub->sqr[3].pln.normal;
	cub->sqr[5].pln.normal = cub->sqr[3].pln.orient;
	cub->sqr[5].t1 = cub->sqr[0].t4;
	cub->sqr[5].t2 = cub->sqr[0].t1;
	cub->sqr[5].t3 = cub->sqr[1].t1;
	cub->sqr[5].t4 = cub->sqr[1].t4;
	cub_triangle(&cub->sqr[5]);
}
