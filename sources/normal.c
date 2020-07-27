/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:10:01 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:10:03 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	find_normal(t_xyz orient, t_xyz xyz, t_xyz cam)
{
	t_xyz		xyz1;
	t_xyz		xyz2;

	xyz1.x = xyz.x + orient.x;
	xyz1.y = xyz.y + orient.y;
	xyz1.z = xyz.z + orient.z;
	xyz2.x = xyz.x - orient.x;
	xyz2.y = xyz.y - orient.y;
	xyz2.z = xyz.z - orient.z;
	return (vect_len(vect_cord(cam, xyz1)) <
			vect_len(vect_cord(cam, xyz2)) ? 1 : 0);
}

t_xyz		f_normal(t_xyz orient, t_xyz xyz, t_xyz cam)
{
	float		scalar;
	t_xyz		normal;
	t_xyz		neg_orient;

	neg_orient = vect_multipl(orient, -1);
	scalar = scal_product(orient, vect_cord(cam, xyz));
	if (scalar)
		normal = (scalar < 0) ? orient : neg_orient;
	else
		normal = find_normal(orient, xyz, cam) ? orient : neg_orient;
	return (normalize(normal));
}

t_xyz		normalize(t_xyz vect)
{
	double		length;
	t_xyz		ray;

	length = sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2));
	ray.x = vect.x / length;
	ray.y = vect.y / length;
	ray.z = vect.z / length;
	return (ray);
}

void		plane_normal(t_pln *pln, t_xyz cam)
{
	while (pln)
	{
		pln->normal = f_normal(pln->orient, pln->xyz, cam);
		pln = pln->next;
	}
}

t_xyz		cylinder_normal(t_cyl cyl, t_xyz dot)
{
	t_pln		pln;
	t_near		res;

	ft_bzero(&pln, sizeof(t_pln));
	pln.orient = cyl.orient;
	pln.xyz = dot;
	res = intersect_pln(pln, cyl.o, cyl.o1, cyl.orient);
	return (vect_cord(res.xyz, dot));
}
