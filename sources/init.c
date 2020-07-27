/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:09:29 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:09:29 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

void	init(void)
{
	if (!g_mlx.mlx)
		g_mlx.mlx = mlx_init();
	if (g_mlx.mlx && !g_mlx.win)
		g_mlx.win = mlx_new_window(g_mlx.mlx, g_scene.res.width,\
		g_scene.res.height, "img");
	if (g_mlx.mlx && g_mlx.win)
	g_mlx.img = mlx_new_image(g_mlx.mlx, g_scene.res.width, g_scene.res.height);
	g_mlx.pix_addr = mlx_get_data_addr(g_mlx.img, &g_mlx.bits_per_pixel,
		&g_mlx.line_length, &g_mlx.endian);
	if (!g_mlx.mlx || !g_mlx.win || !g_mlx.img)
		close_exit(&g_mlx);
}

int		close_exit(t_mlx *g_mlx)
{
	mlx_destroy_image(g_mlx->mlx, g_mlx->img);
	mlx_destroy_window(g_mlx->mlx, g_mlx->win);
	errno = 0;
	if (sizeof(g_mlx)) ////////////////////////
		freemem_struct(NULL, 0);
	exit(0);
}
