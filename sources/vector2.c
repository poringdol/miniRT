/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:11:37 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/30 06:44:15 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_xyz	vect_multipl(t_xyz xyz, double rate)
{
	t_xyz	res;

	res.x = xyz.x * rate;
	res.y = xyz.y * rate;
	res.z = xyz.z * rate;
	return (res);
}

t_xyz	vect_addit(t_xyz xyz, t_xyz rate)
{
	t_xyz	res;

	res.x = xyz.x + rate.x;
	res.y = xyz.y + rate.y;
	res.z = xyz.z + rate.z;
	return (res);
}
