/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:46:10 by pdemocri          #+#    #+#             */
/*   Updated: 2020/09/15 04:52:58 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "bmp.h"
#include "keys.h"

int		key_pressed(int keycode, t_scene *scene)
{
	if (keycode == CAM)
		return (change_camera(&scene));
	else if (keycode == EXIT)
		return (close_exit());
	else if (keycode == SAVE)
		save_print(SAVE);
	else if (keycode == SEPIA)
		return (sepia());
	else if (keycode == REFLECT)
		minirt_bonus(REFLECT);
	else if (keycode == RAINBOW)
		minirt_bonus(RAINBOW);
	else if (keycode == RIPPLES)
		minirt_bonus(RIPPLES);
	return (0);
}

int		change_camera(t_scene **scene)
{
	(*scene)->cam = (*scene)->cam->next;
	mlx_destroy_image(g_mlx.mlx, g_mlx.img);
	mlx_clear_window(g_mlx.mlx, g_mlx.win);
	minirt(0);
	return (0);
}

void	minirt(int param)
{
	init();
	render(param);
	mlx_hook(g_mlx.win, 17, 1 << 17, close_exit, NULL);
	mlx_hook(g_mlx.win, 2, 1 << 0, key_pressed, &g_scene);
	mlx_loop(g_mlx.mlx);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*save;

	save = (argc == 3) ? argv[2] : NULL;
	check_input(argc, argv[1], save, &fd);
	read_rt(fd);
	minirt(argv[2] ? SAVE : 0);
}
