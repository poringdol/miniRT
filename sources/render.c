#include "minirt.h"

void	render(void)
{
	int		i;
	int		j;
	t_xyz	cam1;
	t_xyz	ray;
	t_near	nearest;

	create_canvas(&g_scene.canvas, g_scene.cam, g_scene.res);
	j = -1;
	while (++j < g_scene.res.y)
	{
		i = -1;
		while (++i < g_scene.res.x)
		{
			cam1 = vect_end(g_scene.canvas, g_scene.res, i, j);
			ray = normalize(vect_cord(g_scene.cam->xyz, cam1));
			nearest = nearest_pix(g_scene.cam->xyz, cam1, ray);
			nearest.rgb = nearest.flag ? brightness(nearest, g_scene.lht) : nearest.rgb;
			mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, j, nearest.rgb);
			// nearest = shadow(nearest, g_scene.lgh);
			/////////////////////////////////////////////////////////проверка, что объект не за камерой
		}
	}
}

void	create_canvas(t_canv *canvas, t_cam *cam, t_res res)
{
	double	orient_len;

	orient_len = sqrt(pow(cam->orient.x, 2) +
	pow(cam->orient.y, 2) + pow(cam->orient.z, 2));
	canvas->x = 2 * CANV_DIST * tan(cam->fov / 2);
	canvas->y = ((double)res.y / (double)res.x) * canvas->x;
	canvas->sin_b = cam->orient.z / orient_len;
	canvas->cos_b = sqrt(1 - pow(canvas->sin_b, 2));
	canvas->cos_a = cam->orient.x / (orient_len * canvas->cos_b);
	canvas->sin_a = sqrt(1 - pow(canvas->cos_a, 2));
	canvas->o.x = cam->xyz.x + CANV_DIST * canvas->cos_a * canvas->cos_b;
	canvas->o.y = cam->xyz.y + CANV_DIST * canvas->sin_a * canvas->cos_b;
	canvas->o.z = cam->xyz.z + CANV_DIST * canvas->sin_b;
}
