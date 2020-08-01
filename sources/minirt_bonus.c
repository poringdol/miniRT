/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 04:43:29 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/01 04:43:33 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "bonus.h"
#include "globals.h"

void	minirt_bonus(char *param)
{
	mlx_destroy_image(g_mlx.mlx, g_mlx.img);
	mlx_clear_window(g_mlx.mlx, g_mlx.win);
	init();
	if (!ft_strcmp(param, "reflect"))
		render_antialiasing(param);
	else if (!ft_strcmp(param, "rainbow"))
		render_rainbow(param);
	mlx_hook(g_mlx.win, 17, 1 << 17, close_exit, NULL);
	mlx_hook(g_mlx.win, 2, 1 << 0, key_pressed, &g_scene);
	mlx_loop(g_mlx.mlx);
}
