#include <stdio.h>
#include "mlx.h"
#include "minirt.h"

int main(int argc, char **argv)
{
    int fd;
    // void *mlx_ptr;
    // void *win_ptr;

    check_input(argc, argv[1], &fd);
    read_rt(fd);
    printf ("x = %i, y = %i\n", g_scene.res->x, g_scene.res->y);
}
//     int color = 150;
//     t_res res;
//     res.x = 100;
//     res.y = 50;

//     mlx_ptr = mlx_init();
//     if (!(win_ptr = mlx_new_window(mlx_ptr, 100, 100, "image")))
//         return (0);

//     int i = 0, j = 0;
//     while (j++ < res.y && i++ < res.x)
//         mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
    // mlx_loop(mlx_ptr);
    // mlx_destroy_window(mlx_ptr, win_ptr);
    // mlx_string_put(mlx_ptr, win_ptr, 20, 20, 9109504, "11111111");
// }
