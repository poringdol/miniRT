/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:11:10 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 18:55:28 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_util	substitution_con1(t_con con, t_xyz cam, t_xyz ray, t_canv canv)
{
	t_util	u;

	u.ay = ray.y / ray.x;
	u.by = -cam.x * u.ay + cam.y;
	u.az = ray.z / ray.x;
	u.bz = -cam.x * u.az + cam.z;
	u.k = canv.sin_b * (canv.cos_a + u.ay * canv.sin_a) -
			u.az * canv.cos_b;
	u.l = u.by * canv.sin_a * canv.sin_b - u.bz * canv.cos_b +
			(-con.o.x * canv.cos_a - con.o.y * canv.sin_a) * canv.sin_b +
			con.o.z * canv.cos_b;
	u.n = u.ay * canv.cos_a - canv.sin_a;
	u.m = u.by * canv.cos_a + con.o.x * canv.sin_a - con.o.y *
			canv.cos_a;
	u.i = canv.cos_b * (canv.cos_a + u.ay * canv.sin_a) +
			u.az * canv.sin_b;
	u.j = u.by * canv.sin_a * canv.cos_b + u.bz * canv.sin_b +
			(-con.o.x * canv.cos_a - con.o.y * canv.sin_a) * canv.cos_b -
			con.o.z * canv.sin_b;
	u.a = pow(u.k, 2) + pow(u.n, 2) - pow(u.i, 2) / pow(con.height, 2);
	u.b = 2 * (u.k * u.l + u.n * u.m - u.i * u.j / pow(con.height, 2));
	u.c = pow(u.l, 2) + pow(u.m, 2) - pow(u.j, 2) / pow(con.height, 2);
	u.discr = pow(u.b, 2) - 4 * u.a * u.c;
	return (u);
}
