#include <math.h>
#include "minirt.h"
#include "parsing.h"

void	fill_r(double buf[BUF_S], char *freeline, int l)
{
	if (g_scene.res.x || g_scene.res.y)
		exit(freemem_line(freeline) + freemem_struct(DOUBLE_R, l));
	g_scene.res.x = ((int)buf[0] > RESOLUTION_X) ? RESOLUTION_X : (int)buf[0];
	g_scene.res.y = ((int)buf[1] > RESOLUTION_Y) ? RESOLUTION_Y : (int)buf[1];
	if (!g_scene.res.x || !g_scene.res.y)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
}

void	fill_a(double buf[BUF_S], char *freeline, int l)
{
	if (g_scene.amb.lht_rat || g_scene.amb.rgb)
		exit(freemem_line(freeline) + freemem_struct(DOUBLE_A, l));
	if (buf[0] < 0 || buf[0] > 1 || buf[1] < 0 || buf[1] > 255 ||
	buf[2] < 0 || buf[2] > 255 || buf[3] < 0 || buf[3] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	g_scene.amb.lht_rat = buf[0];
	g_scene.amb.rgb = (int)buf[1] << 16 | (int)buf[2] << 8 | (int)buf[3];
}

void	fill_c(double buf[BUF_S], char *freeline, int l)
{
	t_cam	*new;

	if (buf[6] <= 0 || buf[6] >= 180 ||
	(buf[3] == 0 && buf[4] == 0 && buf[5] == 0))
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_cam *)ft_calloc(sizeof(t_cam), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.cam)
		g_scene.cam = new;
	else
	{
		new->next = g_scene.cam;
		g_scene.cam = new;
	}
	g_scene.cam->xyz.x = buf[0];
	g_scene.cam->xyz.y = buf[1];
	g_scene.cam->xyz.z = buf[2];
	g_scene.cam->orient.x = buf[3];
	g_scene.cam->orient.y = buf[4];
	g_scene.cam->orient.z = buf[5];
	g_scene.cam->orient = normalize(g_scene.cam->orient);
	g_scene.cam->fov = buf[6];
}

void	fill_l(double buf[BUF_S], char *freeline, int l)
{
	t_lht	*new;

	if (buf[3] < 0 || buf[3] > 1 || buf[4] < 0 || buf[4] > 255 ||
	buf[5] < 0 || buf[5] > 255 || buf[6] < 0 || buf[6] > 255)
		exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	if (!(new = (t_lht *)ft_calloc(sizeof(t_lht), 1)))
		exit(freemem_line(freeline) + freemem_struct(NULL, 0));
	if (!g_scene.lht)
		g_scene.lht = new;
	else
	{
		new->next = g_scene.lht;
		g_scene.lht = new;
	}
	g_scene.lht->xyz.x = buf[0];
	g_scene.lht->xyz.y = buf[1];
	g_scene.lht->xyz.z = buf[2];
	g_scene.lht->bri = buf[3];
	g_scene.lht->rgb = (int)buf[4] << 16 | (int)buf[5] << 8 | (int)buf[6];
}