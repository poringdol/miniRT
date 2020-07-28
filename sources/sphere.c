/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:10:42 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:10:43 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_near	solution1(t_subst var, t_sph sph, t_xyz cam)
{
	t_near	res;
	t_near	res1;
	t_near	res2;

	ft_bzero(&res, sizeof(t_near));
	res.flag = 1;
	res.flag2 = var.discr == 0 ? 0 : 1;
	res.rgb = sph.rgb;
	res1.xyz.x = (-var.b + sqrt(var.discr)) / (2 * var.a);
	res1.xyz.y = (res1.xyz.x - cam.x) * var.ay + cam.y;
	res1.xyz.z = (res1.xyz.x - cam.x) * var.az + cam.z;
	res2.xyz.x = (-var.b - sqrt(var.discr)) / (2 * var.a);
	res2.xyz.y = (res2.xyz.x - cam.x) * var.ay + cam.y;
	res2.xyz.z = (res2.xyz.x - cam.x) * var.az + cam.z;
	res.xyz = (vect_len(vect_cord(cam, res1.xyz)) <
	vect_len(vect_cord(cam, res2.xyz)) ? res1.xyz : res2.xyz);
	res.normal = normalize(vect_cord(sph.o, res.xyz));
	return (res);
}

static t_near	solution2(t_subst var, t_sph sph, t_xyz cam)
{
	t_near	res;
	t_near	res1;
	t_near	res2;

	ft_bzero(&res, sizeof(t_near));
	res.flag = 1;
	res.flag2 = var.discr == 0 ? 0 : 1;
	res.rgb = sph.rgb;
	res1.xyz.x = cam.x;
	res1.xyz.y = (-var.b + sqrt(var.discr)) / (2 * var.a);
	res1.xyz.z = (res1.xyz.y - cam.y) * var.az + cam.z;
	res2.xyz.x = cam.x;
	res2.xyz.y = (-var.b - sqrt(var.discr)) / (2 * var.a);
	res2.xyz.z = (res2.xyz.y - cam.y) * var.az + cam.z;
	res.xyz = (vect_len(vect_cord(cam, res1.xyz)) <
	vect_len(vect_cord(cam, res2.xyz)) ? res1.xyz : res2.xyz);
	res.normal = normalize(vect_cord(sph.o, res.xyz));
	return (res);
}

static t_near	solution3(t_sph sph, t_xyz cam)
{
	double	discr;
	t_near	res;
	t_near	res1;
	t_near	res2;
	double	c;

	c = pow(sph.o.z, 2) + pow(cam.x - sph.o.x, 2) +
		pow(cam.y - sph.o.y, 2) - pow(sph.diameter / 2, 2);
	ft_bzero(&res, sizeof(t_near));
	discr = pow(2 * sph.o.z, 2) - 4 * 1 * c;
	if (discr < 0)
		return (res);
	res1.xyz = cam;
	res2.xyz = cam;
	res1.xyz.z = (2 * sph.o.z + sqrt(discr)) / 2;
	res2.xyz.z = (2 * sph.o.z - sqrt(discr)) / 2;
	res.xyz = (vect_len(vect_cord(cam, res1.xyz)) <
	vect_len(vect_cord(cam, res2.xyz)) ? res1.xyz : res2.xyz);
	res.rgb = sph.rgb;
	res.flag = 1;
	res.flag2 = discr == 0 ? 0 : 1;
	res.normal = normalize(vect_cord(sph.o, res.xyz));
	return (res);
}

t_near			sphere(t_sph *sph, t_xyz cam, t_xyz cam1, t_xyz ray)
{
	t_near		nearest;
	t_near		tmp;

	ft_bzero(&nearest, sizeof(t_near));
	ft_bzero(&tmp, sizeof(t_near));
	while (sph)
	{
		if (vect_len(vect_cord(sph->o, cam1)) > (sph->diameter / 2))
		{
			tmp = intersect_sph(*sph, cam, ray);
			if ((tmp.flag &&
			scal_product(g_scene.cam->orient, vect_cord(cam, tmp.xyz)) > 0 &&
			(!nearest.flag ||
			(vect_len(vect_cord(cam, tmp.xyz))) <
			(vect_len(vect_cord(cam, nearest.xyz))))))
				nearest = tmp;
		}
		sph = sph->next;
	}
	return (nearest);
}

t_near			intersect_sph(t_sph sph, t_xyz cam, t_xyz ray)
{
	t_near	res;
	t_subst	var;

	ft_bzero(&res, sizeof(t_near));
	ft_bzero(&var, sizeof(t_subst));
	if (ray.x)
	{
		var = substitution_sph1(sph.o, cam, ray, sph.diameter / 2);
		if (var.discr < 0)
			return (res);
		res = solution1(var, sph, cam);
	}
	else if (ray.y)
	{
		var = substitution_sph2(sph.o, cam, ray, sph.diameter / 2);
		if (var.discr < 0)
			return (res);
		res = solution2(var, sph, cam);
	}
	else
		res = solution3(sph, cam);
	return (res);
}
