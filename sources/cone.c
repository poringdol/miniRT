/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:08:15 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/02 21:18:59 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_canv	sin_cos(t_con *con)
{
	t_canv	canv;

	canv.sin_b = con->orient.z;
	canv.cos_b = sqrt(fabs(1 - pow(canv.sin_b, 2)));
	canv.cos_a = (canv.cos_b != 0) ? (con->orient.x / canv.cos_b) : 0;
	canv.sin_a = (canv.cos_b != 0) ? (con->orient.y / canv.cos_b) : canv.sin_b;
	return (canv);
}

t_near	solution_con1(t_con con, t_util var, t_xyz cam)
{
	t_near	tmp1;
	t_near	tmp2;
	t_near	res;

	ft_bzero(&res, sizeof(t_near));
	if (var.discr < 0)
		return (res);
	res.flag = 1;
	res.rgb = con.rgb;
	if (var.a == 0)
	{
		res.xyz.x = -var.c / var.b;
		res.xyz.y = res.xyz.x * var.ay + var.by;
		res.xyz.z = res.xyz.x * var.az + var.bz;
		return (res);
	}
	tmp1.xyz.x = (-var.b + sqrt(var.discr)) / (2 * var.a);
	tmp1.xyz.y = tmp1.xyz.x * var.ay + var.by;
	tmp1.xyz.z = tmp1.xyz.x * var.az + var.bz;
	tmp2.xyz.x = (-var.b - sqrt(var.discr)) / (2 * var.a);
	tmp2.xyz.y = tmp2.xyz.x * var.ay + var.by;
	tmp2.xyz.z = tmp2.xyz.x * var.az + var.bz;
	res.xyz = vect_len(vect_cord(cam, tmp1.xyz)) <
				vect_len(vect_cord(cam, tmp2.xyz)) ? tmp1.xyz : tmp2.xyz;
	return (res);
}

t_near			intersect_con(t_con *con, t_xyz cam, t_xyz ray)
{
	t_near			res;
	t_util			var;
	const t_canv	canv = sin_cos(con);

	ft_bzero(&res, sizeof(t_near));
	if (ray.x)
	{
		var = substitution_con1(*con, cam, ray, canv);
		res = solution_con1(*con, var, cam);
	}
	// else if (ray.y)
	// {
	// 	var = substitution_cyl2(*con, cam, ray, canv);
	// 	res = solution_cyl2(*con, var, cam);
	// }
	// else
	// {
	// 	var = substitution_cyl3(*cyl, cam, canv);
	// 	res = solution_cyl3(*cyl, var, cam);
	// }
	// if (res.flag && cut_cyl(*cyl, &res, ray))
	// 	check_plane(*cyl, &res, cam, cam1);
	// if (res.flag && !res.flag2)
	// 	res.normal = cylinder_normal(*cyl, res.xyz);
	return (res);
}

t_near			cone(t_con *con, t_cam cam, t_xyz cam1, t_xyz ray)
{
	t_near	nearest;
	t_near	tmp;

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near));
	while (con)
	{
		tmp = intersect_con(con, cam.xyz, ray);
		if ((tmp.flag || tmp.flag2) && (!nearest.flag ||
		(vect_len(vect_cord(cam1, tmp.xyz)) <
		vect_len(vect_cord(cam1, nearest.xyz)))))
		{
			nearest = tmp;
			nearest.flag = 1;
		}
		con = con->next;
	}
	return (nearest);
}
