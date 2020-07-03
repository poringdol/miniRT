#include "minirt.h"

int		close_exit(t_mlx *g_mlx)
{
	mlx_destroy_image(g_mlx->mlx, g_mlx->img);
	mlx_destroy_window(g_mlx->mlx, g_mlx->win);
	errno = 0;
	if (sizeof(g_mlx)) ////////////////////////
		freemem_struct(NULL, 0);
	exit(0);
}

// int		key_released(int keycode, t_mlx *g_mlx)
// {
// 	if (keycode == 53)
// 		return (close_exit(g_mlx));
// 	return (0);
// }
	
int		main(int argc, char **argv)
{
	int fd;

	check_input(argc, argv[1], &fd);
	read_rt(fd);
	init();
	render();
	// mlx_hook(g_mlx.win, 3, 1L << 1, key_released, &g_mlx);
	mlx_hook(g_mlx.win, 17, 1 << 17, close_exit, &g_mlx);
	// close_exit(&g_mlx);
	mlx_loop(g_mlx.mlx);
}
