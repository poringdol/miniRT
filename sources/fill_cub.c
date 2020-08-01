/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:08:54 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/31 02:43:33 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

void		fill_cub(double buf[BUF_S], char *freeline, int l)
{
	t_cub	*new;

	if (buf[7] < 0 || buf[7] > 255 ||
	buf[8] < 0 || buf[8] > 255 || buf[9] < 0 || buf[9] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_cub *)ft_calloc(sizeof(t_cub), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.cub)
		g_scene.cub = new;
	else
	{
		new->next = g_scene.cub;
		g_scene.cub = new;
	}
	g_scene.cub->sqr1.pln.xyz.x = buf[0];
	g_scene.cub->sqr1.pln.xyz.y = buf[1];
	g_scene.cub->sqr1.pln.xyz.z = buf[2];
	g_scene.cub->sqr1.pln.orient.x = buf[3];
	g_scene.cub->sqr1.pln.orient.y = buf[4];
	g_scene.cub->sqr1.pln.orient.z = buf[5];
	g_scene.cub->sqr1.pln.orient = normalize(g_scene.cub->sqr1.pln.orient);
	g_scene.cub->sqr1.side = buf[6];
	g_scene.cub->sqr1.pln.rgb =
			(int)buf[7] << 16 | (int)buf[8] << 8 | (int)buf[9];
}
