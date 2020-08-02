/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:10:29 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/02 23:49:54 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

void		save_print(int param)
{
	if (param == SAVE)
		image_to_bmp();
	else
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_mlx.img, 0, 0);
}

void		render(int param)
{
	// int			j[4];
	// pthread_t	tread1;
	// pthread_t	tread2;
	// pthread_t	tread3;
	// pthread_t	tread4;

	// g_scene.param = param;
	// render_utils();
	// j[0] = 0;
	// j[1] = 1;
	// j[2] = 2;
	// j[3] = 3;
	// pthread_create(&tread1, NULL, pixel_table, &j[0]);
	// pthread_create(&tread2, NULL, pixel_table, &j[1]);
	// pthread_create(&tread3, NULL, pixel_table, &j[2]);
	// pthread_create(&tread4, NULL, pixel_table, &j[3]);
	// pthread_join(tread1, NULL);
	// pthread_join(tread2, NULL);
	// pthread_join(tread3, NULL);
	// pthread_join(tread4, NULL);

	render_utils();
	int i = 0;
	g_scene.param = param;
	pixel_table(&i);

	save_print(param);
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

double		range_of_view(t_canv canvas, t_xyz cam, t_xyz cam1)
{
	return (ROV * vect_len(vect_cord(cam, cam1)) /
			vect_len(vect_cord(cam, canvas.o)));
}

void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int			offset;

	offset = (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)(mlx->pix_addr + offset) = color;
}
