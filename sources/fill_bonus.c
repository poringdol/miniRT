/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:08:54 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 05:55:20 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

void		fill_ld(double buf[BUF_S], char *freeline, int l)
{
	t_lht_d	*new;

	if ((buf[0] == 0 && buf[1] == 0 && buf[2] == 0) ||
			buf[3] < 0 || buf[3] > 1 || buf[4] < 0 || buf[4] > 255 ||
			buf[5] < 0 || buf[5] > 255 || buf[6] < 0 || buf[6] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_lht_d *)ft_calloc(sizeof(t_lht_d), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.lht_d)
		g_scene.lht_d = new;
	else
	{
		new->next = g_scene.lht_d;
		g_scene.lht_d = new;
	}
	g_scene.lht_d->direct.x = buf[0];
	g_scene.lht_d->direct.y = buf[1];
	g_scene.lht_d->direct.z = buf[2];
	g_scene.lht_d->bri = buf[3];
	g_scene.lht_d->rgb = (int)buf[4] << 16 | (int)buf[5] << 8 | (int)buf[6];
	normalize(g_scene.lht_d->direct);
}

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
	g_scene.cub->sqr[0].pln.xyz.x = buf[0];
	g_scene.cub->sqr[0].pln.xyz.y = buf[1];
	g_scene.cub->sqr[0].pln.xyz.z = buf[2];
	g_scene.cub->sqr[0].pln.orient.x = buf[3];
	g_scene.cub->sqr[0].pln.orient.y = buf[4];
	g_scene.cub->sqr[0].pln.orient.z = buf[5];
	g_scene.cub->sqr[0].pln.orient = normalize(g_scene.cub->sqr[0].pln.orient);
	g_scene.cub->sqr[0].side = buf[6];
	g_scene.cub->sqr[0].pln.rgb =
			(int)buf[7] << 16 | (int)buf[8] << 8 | (int)buf[9];
}

void		fill_pyramid(double buf[BUF_S], char *freeline, int l)
{
	t_pyr	*new;

	if (buf[7] < 0 || buf[7] > 255 ||
	buf[8] < 0 || buf[8] > 255 || buf[9] < 0 || buf[9] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_pyr *)ft_calloc(sizeof(t_pyr), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.pyr)
		g_scene.pyr = new;
	else
	{
		new->next = g_scene.pyr;
		g_scene.pyr = new;
	}
	g_scene.pyr->sqr.pln.xyz.x = buf[0];
	g_scene.pyr->sqr.pln.xyz.y = buf[1];
	g_scene.pyr->sqr.pln.xyz.z = buf[2];
	g_scene.pyr->sqr.pln.orient.x = buf[3];
	g_scene.pyr->sqr.pln.orient.y = buf[4];
	g_scene.pyr->sqr.pln.orient.z = buf[5];
	g_scene.pyr->sqr.pln.orient = normalize(g_scene.pyr->sqr.pln.orient);
	g_scene.pyr->sqr.side = buf[6];
	g_scene.pyr->height = buf[7];
	g_scene.pyr->sqr.pln.rgb =
			(int)buf[8] << 16 | (int)buf[9] << 8 | (int)buf[10];
}

void	fill_cone(double buf[BUF_S], char *freeline, int l)
{
	t_con	*new;

	if (buf[7] < 0 || buf[7] > 255 ||
	buf[8] < 0 || buf[8] > 255 || buf[9] < 0 || buf[9] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_con *)ft_calloc(sizeof(t_con), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.con)
		g_scene.con = new;
	else
	{
		new->next = g_scene.con;
		g_scene.con = new;
	}
	g_scene.cyl->o.x = buf[0];
	g_scene.cyl->o.y = buf[1];
	g_scene.cyl->o.z = buf[2];
	g_scene.cyl->orient.x = buf[3];
	g_scene.cyl->orient.y = buf[4];
	g_scene.cyl->orient.z = buf[5];
	g_scene.cyl->orient = normalize(g_scene.cyl->orient);
	g_scene.cyl->height = buf[6];
	g_scene.cyl->rgb = (int)buf[7] << 16 | (int)buf[8] << 8 | (int)buf[9];
}
