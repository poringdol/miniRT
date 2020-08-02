/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:11:10 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/02 21:21:00 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_util	substitution_con1(t_con con, t_xyz cam, t_xyz ray, t_canv canv)
{
	t_util	util;

	util.ay = ray.y / ray.x;
	util.by = -cam.x * util.ay + cam.y;
	util.az = ray.z / ray.x;
	util.bz = -cam.x * util.az + cam.z;
	util.k = canv.sin_b * (canv.cos_a + util.ay * canv.sin_a) -
			util.az * canv.cos_b;
	util.l = util.by * canv.sin_a * canv.sin_b - util.bz * canv.cos_b +
			(-con.o.x * canv.cos_a - con.o.y * canv.sin_a) * canv.sin_b +
			con.o.z * canv.cos_b;
	util.n = util.ay * canv.cos_a - canv.sin_a;
	util.m = util.by * canv.cos_a + con.o.x * canv.sin_a - con.o.y *
			canv.cos_a;
	util.i = canv.cos_b * (canv.cos_a + util.ay * canv.sin_a) +
			util.az * canv.sin_b;
	util.j = util.by * canv.sin_a * canv.cos_b + util.bz * canv.sin_b +
			(-con.o.x * canv.cos_a - con.o.y * canv.sin_a) * canv.cos_b -
			con.o.z * canv.sin_b;
	util.a = pow(util.k, 2) + pow(util.n, 2) - pow(util.i, 2) / pow(con.height, 2);
	util.b = 2 * (util.k * util.l + util.n * util.m - util.i * util.j / pow(con.height, 2));
	util.c = pow(util.l, 2) + pow(util.m, 2) - pow(util.j, 2) / pow(con.height, 2);;
	util.discr = pow(util.b, 2) - 4 * util.a * util.c;
	return (util);
}

// t_util	substitution_cyl2(t_cyl cyl, t_xyz cam, t_xyz ray, t_canv canv)
// {
// 	t_util	util;

// 	util.az = ray.z / ray.y;
// 	util.bz = -cam.y * util.az + cam.z;
// 	util.k = canv.sin_a * canv.sin_b - util.az * canv.cos_b;
// 	util.l = ((cam.x - cyl.o.x) * canv.cos_a - cyl.o.y * canv.sin_a) *
// 			canv.sin_b - (util.bz - cyl.o.z) * canv.cos_b;
// 	util.n = canv.cos_a;
// 	util.m = (-cam.x - cyl.o.x) * canv.sin_a - cyl.o.y * canv.cos_a;
// 	util.a = pow(util.k, 2) + pow(util.n, 2);
// 	util.b = 2 * (util.k * util.l + util.n * util.m);
// 	util.c = pow(util.l, 2) + cyl.o.y * util.m - pow(cyl.diameter / 2, 2);
// 	util.discr = pow(util.b, 2) - 4 * util.a * util.c;
// 	return (util);
// }

// t_util	substitution_cyl3(t_cyl cyl, t_xyz cam, t_canv canv)
// {
// 	t_util	util;

// 	util.k = canv.cos_b;
// 	util.l = cyl.o.z * canv.cos_b + ((cam.x - cyl.o.x) * canv.cos_a +
// 			(cam.y - cyl.o.y) * canv.sin_a) * canv.sin_b;
// 	util.m = pow((-cam.x - cyl.o.x) * canv.sin_a + (cam.y - cyl.o.y) *
// 			canv.cos_a, 2) - pow(cyl.diameter / 2, 2);
// 	util.a = pow(util.k, 2);
// 	util.b = -2 * util.k * util.l;
// 	util.c = pow(util.l, 2) + util.m;
// 	util.discr = pow(util.b, 2) - 4 * util.a * util.c;
// 	return (util);
// }
