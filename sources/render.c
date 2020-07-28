/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:10:29 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:10:29 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	save_print(char *save)
{
	char *str;

	if (save)
		image_to_bmp();
	else
	{
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_mlx.img, 0, 0);
		mlx_string_put(g_mlx.mlx, g_mlx.win, 10, 20, 0xffffff, "cam.x = ");
		mlx_string_put(g_mlx.mlx, g_mlx.win, 70, 20, 0xffffff, str = ft_itoa(g_scene.cam->xyz.x));
		free(str);
		mlx_string_put(g_mlx.mlx, g_mlx.win, 10, 35, 0xffffff, "cam.y = ");
		mlx_string_put(g_mlx.mlx, g_mlx.win, 70, 35, 0xffffff, str = ft_itoa(g_scene.cam->xyz.y));
		free(str);
		mlx_string_put(g_mlx.mlx, g_mlx.win, 10, 50, 0xffffff, "cam.z = ");
		mlx_string_put(g_mlx.mlx, g_mlx.win, 70, 50, 0xffffff, str = ft_itoa(g_scene.cam->xyz.z));
		free(str);
		mlx_string_put(g_mlx.mlx, g_mlx.win, 10, 65, 0xffffff, "orient.x = ");
		mlx_string_put(g_mlx.mlx, g_mlx.win, 100, 65, 0xffffff, str = ft_itoa(g_scene.cam->orient.x));
		free(str);
		mlx_string_put(g_mlx.mlx, g_mlx.win, 10, 80, 0xffffff, "orient.y = ");
		mlx_string_put(g_mlx.mlx, g_mlx.win, 100, 80, 0xffffff, str = ft_itoa(g_scene.cam->orient.y));
		free(str);
		mlx_string_put(g_mlx.mlx, g_mlx.win, 10, 95, 0xffffff, "orient.z = ");
		mlx_string_put(g_mlx.mlx, g_mlx.win, 100, 95, 0xffffff, str = ft_itoa(g_scene.cam->orient.z));
		free(str);
	}
}

void		render(char *save)
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
	while (++j < g_scene.res.height)
	{
		i = -1;
		while (++i < g_scene.res.width)
		{
			cam1 = vect_end(g_scene.canvas, g_scene.res, i, j);
			ray = normalize(vect_cord(g_scene.cam->xyz, cam1));
			nearest = nearest_pix(g_scene.cam->xyz, cam1, ray);
			nearest.rgb = nearest.flag ? brightness(nearest, g_scene.lht) :
						nearest.rgb;
			my_mlx_pixel_put(&g_mlx, i, j, nearest.rgb);
		}
	}
	save_print(save);
}

void		create_canvas(t_canv *canvas, t_cam *cam, t_res res)
{
	canvas->width = 2 * CANV_DIST * tan((cam->fov / 2) * PI / 180);
	canvas->height = ((double)res.height / (double)res.width) * canvas->width;
	canvas->sin_b = cam->orient.z;
	canvas->cos_b = sqrt(fabs(1 - pow(canvas->sin_b, 2)));
	canvas->cos_a = (canvas->cos_b != 0) ? cam->orient.x / canvas->cos_b : 0;
	canvas->sin_a = (canvas->cos_b != 0) ? cam->orient.y / canvas->cos_b :
					canvas->sin_b;
	canvas->o.x = cam->xyz.x + CANV_DIST * canvas->cos_a * canvas->cos_b;
	canvas->o.y = cam->xyz.y + CANV_DIST * canvas->sin_a * canvas->cos_b;
	canvas->o.z = cam->xyz.z + CANV_DIST * canvas->sin_b;
}

float		range_of_view(t_canv canvas, t_xyz cam, t_xyz cam1)
{
	return (ROV * vect_len(vect_cord(cam, cam1)) /
			vect_len(vect_cord(cam, canvas.o)));
}

void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int		offset;

	offset = (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)(mlx->pix_addr + offset) = color;
}
