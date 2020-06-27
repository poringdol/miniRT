#include "parsing.h"

void	fill_pl(float buf[BUF_S], char *freeline, int l)
{
	t_pln	*new;

	if (buf[3] < -1 || buf[3] > 1 || buf[4] < -1 || buf[4] > 1 ||
	buf[5] < -1 || buf[5] > 1 || buf[6] < 0 || buf[6] > 255 ||
	buf[7] < 0 || buf[7] > 255 || buf[8] < 0 || buf[8] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_pln *)ft_calloc(sizeof(t_pln), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.pln)
		g_scene.pln = new;
	else
	{
		new->next = g_scene.pln;
		g_scene.pln = new;
	}
	g_scene.pln->xyz.x = buf[0];
	g_scene.pln->xyz.y = buf[1];
	g_scene.pln->xyz.z = buf[2];
	g_scene.pln->orient.x = buf[3];
	g_scene.pln->orient.y = buf[4];
	g_scene.pln->orient.z = buf[5];
	g_scene.pln->rgb = (int)buf[6] << 16 | (int)buf[7] << 8 | (int)buf[8];
}

void	fill_sp(float buf[BUF_S], char *freeline, int l)
{
	t_sph	*new;

	if (buf[4] < 0 || buf[4] > 255 || buf[5] < 0 || buf[5] > 255 ||
	buf[6] < 0 || buf[6] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_sph *)ft_calloc(sizeof(t_sph), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.sph)
		g_scene.sph = new;
	else
	{
		new->next = g_scene.sph;
		g_scene.sph = new;
	}
	g_scene.sph->xyz.x = buf[0];
	g_scene.sph->xyz.y = buf[1];
	g_scene.sph->xyz.z = buf[2];
	g_scene.sph->diameter = buf[3];
	g_scene.sph->rgb = (int)buf[4] << 16 | (int)buf[5] << 8 | (int)buf[6];
}

void	fill_sq(float buf[BUF_S], char *freeline, int l)
{
	t_sqr	*new;

	if (buf[3] < -1 || buf[3] > 1 || buf[4] < -1 || buf[4] > 1 ||
	buf[5] < -1 || buf[5] > 1 || buf[7] < 0 || buf[7] > 255 ||
	buf[8] < 0 || buf[8] > 255 || buf[9] < 0 || buf[9] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_sqr *)ft_calloc(sizeof(t_sqr), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.sqr)
		g_scene.sqr = new;
	else
	{
		new->next = g_scene.sqr;
		g_scene.sqr = new;
	}
	g_scene.sqr->xyz.x = buf[0];
	g_scene.sqr->xyz.y = buf[1];
	g_scene.sqr->xyz.z = buf[2];
	g_scene.sqr->orient.x = buf[3];
	g_scene.sqr->orient.y = buf[4];
	g_scene.sqr->orient.z = buf[5];
	g_scene.sqr->size = buf[6];
	g_scene.sqr->rgb = (int)buf[7] << 16 | (int)buf[8] << 8 | (int)buf[9];
}

void	fill_cy(float buf[BUF_S], char *freeline, int l)
{
	t_cyl	*new;

	if (buf[3] < -1 || buf[3] > 1 || buf[4] < -1 || buf[4] > 1 ||
	buf[5] < -1 || buf[5] > 1 || buf[8] < 0 || buf[8] > 255 ||
	buf[9] < 0 || buf[9] > 255 || buf[10] < 0 || buf[10] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_cyl *)ft_calloc(sizeof(t_cyl), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.cyl)
		g_scene.cyl = new;
	else
	{
		new->next = g_scene.cyl;
		g_scene.cyl = new;
	}
	g_scene.cyl->xyz.x = buf[0];
	g_scene.cyl->xyz.y = buf[1];
	g_scene.cyl->xyz.z = buf[2];
	g_scene.cyl->orient.x = buf[3];
	g_scene.cyl->orient.y = buf[4];
	g_scene.cyl->orient.z = buf[5];
	g_scene.cyl->diameter = buf[6];
	g_scene.cyl->height = buf[7];
	g_scene.cyl->rgb = (int)buf[8] << 16 | (int)buf[9] << 8 | (int)buf[10];
}

void	fill_tr(float buf[BUF_S], char *freeline, int l)
{
	t_tri	*new;

	if (buf[9] < 0 || buf[9] > 255 || buf[10] < 0 || buf[10] > 255 ||
	buf[11] < 0 || buf[11] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_tri *)ft_calloc(sizeof(t_tri), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.tri)
		g_scene.tri = new;
	else
	{
		new->next = g_scene.tri;
		g_scene.tri = new;
	}
	g_scene.tri->xyz1.x = buf[0];
	g_scene.tri->xyz1.y = buf[1];
	g_scene.tri->xyz1.z = buf[2];
	g_scene.tri->xyz2.x = buf[3];
	g_scene.tri->xyz2.y = buf[4];
	g_scene.tri->xyz2.z = buf[5];
	g_scene.tri->xyz3.x = buf[6];
	g_scene.tri->xyz3.y = buf[7];
	g_scene.tri->xyz3.z = buf[8];
	g_scene.tri->rgb = (int)buf[9] << 16 | (int)buf[10] << 8 | (int)buf[11];
}
