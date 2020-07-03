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
# define ROV 50

void	init(void);
void	render(void);
void	camera_loop(t_cam **camera);
void	create_canvas(t_canv *canvas, t_cam *cam, t_res res);

t_xyz	vect_end(t_canv canv, t_res res, int i, int j);
double	vect_len(t_xyz vect);
t_xyz	vect_cord(t_xyz start, t_xyz end);
t_xyz	normalize(t_xyz vect);
double	scalar(t_xyz vect1, t_xyz vect2);

t_near	nearest_pix(t_xyz cam, t_xyz cam1, t_xyz ray);
t_subst	substitution1(t_xyz sph, t_xyz cam, t_xyz ray, double radius);
t_subst	substitution2(t_xyz sph, t_xyz cam, t_xyz ray, double radius);

t_near	sphere(t_sph *sph, t_xyz cam, t_xyz cam1, t_xyz ray);
t_near	intersect_sph(t_sph sph, t_xyz cam, t_xyz ray);
// t_near	solution_sph1(t_subst var, t_sph sph, t_xyz cam);
// t_near	solution_sph2(t_subst var, t_sph sph, t_xyz cam);
// t_near	solution_sph3(t_sph sph, t_xyz cam, t_xyz ray);

t_near	plane(t_pln *pln, t_xyz cam, t_xyz cam1, t_xyz ray);
t_near	intersect_pln(t_pln pln, t_xyz cam, t_xyz ray);
t_xyz	normal_plane(t_xyz dot, t_xyz orient, t_xyz cam);

int	brightness(t_near dot, t_lht *lht);

#endif
