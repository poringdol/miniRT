/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:11:29 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/31 16:54:23 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_xyz	vect_end(t_canv canv, t_res res, int i, int j)
{
	t_xyz	xyz;

	xyz.x = canv.o.x - canv.width / 2 * canv.sin_a -
		canv.height / 2 * canv.sin_b * canv.cos_a +
		canv.width * i / res.width * canv.sin_a +
		canv.height * j / res.height * canv.sin_b * canv.cos_a;
	xyz.y = canv.o.y + canv.width / 2 * canv.cos_a -
		canv.height / 2 * canv.sin_b * canv.sin_a -
		canv.width * i / res.width * canv.cos_a +
		canv.height * j / res.height * canv.sin_b * canv.sin_a;
	xyz.z = canv.o.z + canv.height / 2 * canv.cos_b -
		canv.height * j / res.height * canv.cos_b;
	return (xyz);
}

double	vect_len(t_xyz vect)
{
	return (sqrt(pow(vect.x, 2) +
				pow(vect.y, 2) +
				pow(vect.z, 2)));
}

t_xyz	vect_cord(t_xyz start, t_xyz end)
{
	t_xyz	res;

	res.x = end.x - start.x;
	res.y = end.y - start.y;
	res.z = end.z - start.z;
	return (res);
}

double	scal_product(t_xyz vect1, t_xyz vect2)
{
	double res;

	res = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
	return (res);
}

t_xyz	vect_product(t_xyz xyz1, t_xyz xyz2)
{
	t_xyz	res;

	res.x = xyz1.y * xyz2.z - xyz1.z * xyz2.y;
	res.y = xyz1.z * xyz2.x - xyz1.x * xyz2.z;
	res.z = xyz1.x * xyz2.y - xyz1.y * xyz2.x;
	return (res);
}
