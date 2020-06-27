# include "minirt.h"
# include "parsing.h"

void init(void)
{
	if (!(g_mlx.mlx = mlx_init()) ||
	!(g_mlx.win = mlx_new_window(g_mlx.mlx, g_scene.res.x,\
		g_scene.res.y, "img")) ||
	!(g_mlx.img = mlx_new_image(g_mlx.mlx, g_scene.res.x, g_scene.res.y)) ||
	!(g_mlx.data = (int *)mlx_get_data_addr(g_mlx.img, &g_mlx.bpp,\
		&g_mlx.size_l, &g_mlx.endian)))
	{
		freemem_struct(INIT_FAIL, 0);
		exit(1);
	}
}