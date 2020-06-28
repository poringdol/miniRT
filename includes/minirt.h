#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "parsing.h"
# include "structs.h"
# include "error.h"
# include "globals.h"

# define CANV_DIST 1
# define BACKGROUND 0xffffff

void	init(void);
void	print_triangle(t_scene g_scene);
void	print_line(int x1, int y1, int x2, int y2, int color);
void	print_circle(t_scene g_scene);
void	render(void);
void	create_canvas(t_canv *canvas, t_cam *cam, t_res res);
t_xyz	vect_end(t_canv canv, t_res res, int i, int j);
float	vect_len(t_xyz start, t_xyz end);
t_xyz	normalize(float x, float y, float z);
float	discriminant(float diameter, t_xyz ray, t_xyz cam_sph);
t_near	nearest_pix(t_xyz cam, t_xyz ray);
t_near	sphere(t_sph *sph, t_xyz cam, t_xyz ray);
t_near	intersect_sph(t_sph sph, t_xyz cam, t_xyz ray);

#endif
