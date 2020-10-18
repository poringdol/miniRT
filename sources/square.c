/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:10:50 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/30 06:13:01 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_inside_square(t_sqr sqr, t_xyz dot)
{
	t_xyz	a;
	t_xyz	b;
	t_xyz	c;
	t_xyz	d;

	a = vect_cord(sqr.t2, sqr.t1);
	b = vect_cord(sqr.t3, sqr.t2);
	c = vect_cord(sqr.t4, sqr.t3);
	d = vect_cord(sqr.t1, sqr.t4);
	if (scal_product(vect_product(a, vect_cord(dot, sqr.t1)),
					vect_product(b, vect_cord(dot, sqr.t2))) > 0 &&
		scal_product(vect_product(b, vect_cord(dot, sqr.t2)),
					vect_product(c, vect_cord(dot, sqr.t3))) > 0 &&
		scal_product(vect_product(c, vect_cord(dot, sqr.t3)),
					vect_product(d, vect_cord(dot, sqr.t4))) > 0)
		return (1);
	return (0);
}

int		check_square(t_sqr sqr, t_xyz dot, t_near near, t_xyz cam1)
{
	if (is_inside_square(sqr, dot) &&
		(!near.flag || vect_len(vect_cord(cam1, dot)) <
			vect_len(vect_cord(cam1, near.xyz))))
		return (1);
	return (0);
}	

t_near		square(t_sqr *sqr, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp;

	ft_bzero(&nearest, sizeof(t_near));
	while (sqr)
	{
		tmp = intersect_pln(sqr->pln, cam.xyz, cam1, ray);
		if (tmp.flag2 && (check_square(*sqr, tmp.xyz, nearest, cam1)))
			nearest = tmp;
		sqr = sqr->next;
	}
	return (nearest);
}
