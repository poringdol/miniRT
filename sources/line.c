#include "minirt.h"

static void	swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

static int	fsteep(int *x1, int *y1, int *x2, int *y2)
{
	char	steep;

	steep = 0;
	if (abs(*x1 - *x2) < abs(*y1 - *y2))
	{
		swap(x1, y1);
		swap(x2, y2);
		steep = 1;
	}
	if (*x1 > *x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	return (steep);
}

void		print_triangle(t_scene g_scene)
{
	while (g_scene.tri)
	{
		print_line(g_scene.tri->top1.x, g_scene.tri->top1.y,\
					g_scene.tri->top2.x, g_scene.tri->top2.y,\
					g_scene.tri->rgb);
		print_line(g_scene.tri->top2.x, g_scene.tri->top2.y,\
					g_scene.tri->top3.x, g_scene.tri->top3.y,\
					g_scene.tri->rgb);
		print_line(g_scene.tri->top3.x, g_scene.tri->top3.y,\
					g_scene.tri->top1.x, g_scene.tri->top1.y,\
					g_scene.tri->rgb);
		g_scene.tri = g_scene.tri->next;
	}
}

void		print_line(int x1, int y1, int x2, int y2, int color)
{
	const char steep = fsteep(&x1, &y1, &x2, &y2);
	const int derror = abs(y2 - y1) * 2;
	int error;
	int y = y1;
	int x = x1;

	error = 0;
	while (x < x2)
	{
		if (steep)
			mlx_pixel_put(g_mlx.mlx, g_mlx.win, y, x, color);
		else
			mlx_pixel_put(g_mlx.mlx, g_mlx.win, x, y, color);
		error += derror;
		if (error > (x2 - x1))
		{
			y += (y2 > y1 ? 1 : -1);
			error -= (x2 - x1) * 2;
		}
		x++;
	}
}
