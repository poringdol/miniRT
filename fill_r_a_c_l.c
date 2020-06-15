#include <errno.h>
#include "minirt.h"
#include "minirt_struct.h"

void	fill_r(float buf[BUF_S])
{
	if (g_scene.res)
		exit(ft_putstr_fd(DOUBLE_R, 2));
	if (!(g_scene.res = (t_res *)ft_calloc(sizeof(t_res), 1)))
		exit(ft_putstr_fd(strerror(errno), 2));
	g_scene.res->x = (int)buf[0];
	g_scene.res->y = (int)buf[1];
	if (!g_scene.res->x || !g_scene.res->y)
		exit(ft_putstr_fd(INVAL_P, 2));
}

void	fill_a(float buf[BUF_S])
{
	if (g_scene.amb)
		exit(ft_putstr_fd(DOUBLE_A, 2));
	if (!(g_scene.amb = (t_amb *)ft_calloc(sizeof(t_amb), 1)))
		exit(ft_putstr_fd(strerror(errno), 2));
	if (buf[0] < 0 || buf[0] > 1 || buf[1] < 0 || buf[1] > 255 ||
	buf[2] < 0 || buf[2] > 255 || buf[3] < 0 || buf[3] > 255)
		exit(ft_putstr_fd(INVAL_P, 2));
	g_scene.amb->lht_rat = buf[0];
	g_scene.amb->rgb = (int)buf[1] << 16 | (int)buf[2] << 8 | (int)buf[3];
}

void	fill_c(float buf[BUF_S])
{
	t_cam	*new;

	if (buf[3] < -1 || buf[3] > 1 || buf[4] < -1 || buf[4] > 1 ||
	buf[5] < -1 || buf[5] > 1 || buf[6] < 0 || buf[6] > 180)
		exit(ft_putstr_fd(INVAL_P, 2));
	if (!(new = (t_cam *)ft_calloc(sizeof(t_cam), 1)))
		exit(ft_putstr_fd(strerror(errno), 2));
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
	g_scene.cam->fov = buf[6];
}

void	fill_l(float buf[BUF_S])
{
	t_lht	*new;

	if (buf[3] < 0 || buf[3] > 1 || buf[4] < 0 || buf[4] > 255 ||
	buf[5] < 0 || buf[5] > 255 || buf[6] < 0 || buf[6] > 255)
		exit(ft_putstr_fd(INVAL_P, 2));
	if (!(new = (t_lht *)ft_calloc(sizeof(t_lht), 1)))
		exit(ft_putstr_fd(strerror(errno), 2));
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
	g_scene.lht->lht_bri = buf[3];
	g_scene.lht->rgb = (int)buf[4] << 16 | (int)buf[5] << 8 | (int)buf[6];
}
