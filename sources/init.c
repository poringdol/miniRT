# include "minirt.h"
# include "parsing.h"

void init(void)
{
	if (!g_mlx.mlx)
		g_mlx.mlx = mlx_init();
	if (g_mlx.mlx && !g_mlx.win)
		g_mlx.win = mlx_new_window(g_mlx.mlx, g_scene.res.x,\
		g_scene.res.y, "img");
	if (g_mlx.mlx && g_mlx.mlx)
	g_mlx.img = mlx_new_image(g_mlx.mlx, g_scene.res.x, g_scene.res.y);
	// g_mlx.data = (int *)mlx_get_data_addr(g_mlx.img, &g_mlx.bpp,
	// 	&g_mlx.size_l, &g_mlx.endian);
	if (!g_mlx.mlx || !g_mlx.win || !g_mlx.img)
		close_exit(&g_mlx);
}

int		close_exit(t_mlx *g_mlx)
{
	// mlx_destroy_image(g_mlx->mlx, g_mlx->img);
	// mlx_destroy_window(g_mlx->mlx, g_mlx->win);
	errno = 0;
	if (sizeof(g_mlx)) ////////////////////////
		freemem_struct(NULL, 0);
	exit(0);
}