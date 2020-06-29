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
# define BACKGROUND 0x000000

void	init(void);
void	render(void);
void	create_canvas(t_canv *canvas, t_cam *cam, t_res res);

t_xyz	vect_end(t_canv canv, t_res res, int i, int j);
double	vect_len(t_xyz start, t_xyz end);
t_xyz	normalize(double x, double y, double z);

t_near	nearest_pix(t_xyz cam, t_xyz ray);
t_near	sphere(t_sph *sph, t_xyz cam, t_xyz ray);
t_near	intersect_sph(t_sph sph, t_xyz cam, t_xyz ray);

#endif
