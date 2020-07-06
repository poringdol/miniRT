#include "minirt.h"
#include "keys.h"

int		key_pressed(int keycode, t_mlx *g_mlx)
{
	printf("%i\n", keycode);
	if (keycode == CAM)
		return (change_camera(&g_scene.cam));
	if (keycode == EXIT)
		return (close_exit(g_mlx));
	return (0);
}

int		change_camera(t_cam **camera)
{
	*camera = (*camera)->next;
	mlx_destroy_image(g_mlx.mlx, g_mlx.img);
	mlx_clear_window(g_mlx.mlx, g_mlx.win);
	minirt();
	return (0);
}
	
void	minirt(void)
{
	init();
	render();
	mlx_hook(g_mlx.win, 17, 1 << 17, close_exit, &g_mlx);
	mlx_hook(g_mlx.win, 2, 1 << 0, key_pressed, NULL);
	mlx_loop(g_mlx.mlx);
}

int		main(int argc, char **argv)
{
	int fd;

	check_input(argc, argv[1], &fd);
	read_rt(fd);
	minirt();
}
