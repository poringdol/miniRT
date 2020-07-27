#include "minirt.h"

void	render(void)
{
	int		i;
	int		j;
	t_xyz	cam1;
	t_xyz	ray;
	t_near	nearest;

	create_canvas(&g_scene.canvas, g_scene.cam, g_scene.res);
	square_tops(g_scene.sqr, g_scene.cam->xyz);
	triangle_plane(g_scene.tri, g_scene.cam->xyz);
	plane_normal(g_scene.pln, g_scene.cam->xyz);
	j = -1;
	while (++j < g_scene.res.y)
	{
		i = -1;
		while (++i < g_scene.res.x)
		{
			int a = 0;
			if (i == 400 && j == 350)
				printf("2");////////////////////////////////////
			cam1 = vect_end(g_scene.canvas, g_scene.res, i, j);
			ray = normalize(vect_cord(g_scene.cam->xyz, cam1));
			nearest = nearest_pix(g_scene.cam->xyz, cam1, ray);
			nearest.rgb = nearest.flag ? brightness(nearest, g_scene.lht) : nearest.rgb;
			// mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, j, nearest.rgb);
			my_mlx_pixel_put(g_mlx, i, j, nearest.rgb);
		}
	}
}

void	create_canvas(t_canv *canvas, t_cam *cam, t_res res)
{
	canvas->width = 2 * CANV_DIST * tan((cam->fov / 2) * PI / 180);
	canvas->height = ((double)res.y / (double)res.x) * canvas->width;
	canvas->sin_b = cam->orient.z;
	canvas->cos_b = sqrt(fabs(1 - pow(canvas->sin_b, 2)));
	canvas->cos_a = (canvas->cos_b != 0) ? cam->orient.x / canvas->cos_b : 0;
	canvas->sin_a = (canvas->cos_b != 0) ? cam->orient.y / canvas->cos_b : canvas->sin_b;
	canvas->o.x = cam->xyz.x + CANV_DIST * canvas->cos_a * canvas->cos_b;
	canvas->o.y = cam->xyz.y + CANV_DIST * canvas->sin_a * canvas->cos_b;
	canvas->o.z = cam->xyz.z + CANV_DIST * canvas->sin_b;
}

float	range_of_view(t_canv canvas, t_xyz cam, t_xyz cam1)
{
	return (ROV * vect_len(vect_cord(cam, cam1)) /
			vect_len(vect_cord(cam, canvas.o)));
}

void	my_mlx_pixel_put(t_mlx *g_mlx, int i, int j, int nearest.rgb)
{
	char    *dst;

    dst = mlx->adr + (j * mlx-> + i * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}