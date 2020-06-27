#include "minirt.h"

int		sphera(t_xyz sph, t_xyz cam, t_xyz ray)
{
	const t_xyz	cs = {sph.x - cam.x, sph.y - cam.y, sph.z - cam.z};
	const float	a = pow(ray.x, 2) + pow(ray.y, 2) + pow(ray.z, 2);
	const float	b = 2 * (ray.x * cs.x + ray.y * cs.y + ray.z * cs.z);
	const float	c = pow(cs.x, 2) + pow(cs.y, 2) + pow(cs.z, 2) - pow(g_scene.sph->diameter / 2, 2);

	if ((pow(b, 2) - 4 * a * c) < 0)
		return (0);
	return (1);
}

void	render(void)
{
	int			i;
	int			j;
	t_xyz		cam1;
	t_xyz		ray;

	create_canvas(&g_scene.canvas, g_scene.cam, g_scene.res);
	j = -1;
	while (++j < g_scene.res.y)
	{
		i = -1;
		while (++i < g_scene.res.x)
		{
			cam1 = vect_end(g_scene.canvas, g_scene.res, i, j);
			ray = normalize(cam1.x - g_scene.cam->xyz.x,
				cam1.y - g_scene.cam->xyz.y, cam1.z - g_scene.cam->xyz.z);
			if ((sphera(g_scene.sph->xyz, g_scene.cam->xyz, ray)))
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, j, g_scene.tri->rgb);
		}
	}

}

void	create_canvas(t_canv *canvas, t_cam *cam, t_res res)
{
	const float	s = 1;
	const float orient_len = sqrt(pow(cam->orient.x, 2) +
		pow(cam->orient.y, 2) + pow(cam->orient.z, 2));
 
	canvas->x = 2 * s * tan(cam->fov / 2);
	canvas->y = (float)res.y / (float)res.x * canvas->x;
	canvas->sin_b = cam->orient.z / orient_len;
	canvas->cos_b = sqrt(1 - pow(canvas->sin_b, 2));
	canvas->cos_a = cam->orient.x / orient_len;
	canvas->sin_a = sqrt(1 - pow(canvas->cos_a, 2));
	canvas->o.x = cam->xyz.x + s * canvas->cos_a * canvas->cos_b;
	canvas->o.y = cam->xyz.y + s * canvas->sin_a * canvas->cos_b;
	canvas->o.z = cam->xyz.z + s * canvas->sin_b;
}
