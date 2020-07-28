/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:13:28 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:13:29 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "errors.h"
# include "globals.h"

# define CANV_DIST 1
# define BACKGROUND 0x000000
# define ROV 100
# define PI 3.14159265358

void	init(void);
void	minirt(char *save);
void	render(char *save);
int		close_exit(void);
void	camera_loop(t_cam **camera);
void	create_canvas(t_canv *canvas, t_cam *cam, t_res res);

t_xyz	vect_end(t_canv canv, t_res res, int i, int j);
double	vect_len(t_xyz vect);
t_xyz	vect_cord(t_xyz start, t_xyz end);
t_xyz	normalize(t_xyz vect);
t_xyz	vect_multipl(t_xyz xyz, float rate);
t_xyz	vect_addit(t_xyz xyz, t_xyz rate);
double	scal_product(t_xyz vect1, t_xyz vect2);
t_xyz	vect_product(t_xyz xyz1, t_xyz xyz2);
t_xyz	f_normal(t_xyz orient, t_xyz xyz, t_xyz cam);

t_near	nearest_pix(t_xyz cam, t_xyz cam1, t_xyz ray);
float	range_of_view(t_canv canvas, t_xyz cam, t_xyz cam1);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

t_near	plane(t_pln *pln, t_cam cam, t_xyz cam1, t_xyz ray);
t_near	intersect_pln(t_pln pln, t_xyz cam, t_xyz cam1, t_xyz ray);
void	plane_normal(t_pln *pln, t_xyz cam);
t_xyz	triangle_normal(t_tri *tri, t_xyz cam_orient);

t_near	sphere(t_sph *sph, t_xyz cam, t_xyz cam1, t_xyz ray);
t_near	intersect_sph(t_sph sph, t_xyz cam, t_xyz ray);
t_subst	substitution_sph1(t_xyz sph, t_xyz cam, t_xyz ray, double radius);
t_subst	substitution_sph2(t_xyz sph, t_xyz cam, t_xyz ray, double radius);

t_near	triangle(t_tri *tri, t_xyz cam, t_xyz cam1, t_xyz ray);
void	triangle_plane(t_tri *tri, t_xyz cam);
int		check_triangle(t_tri tri, t_xyz dot, t_near near, t_xyz cam1);
int		check_side(t_xyz dot, t_xyz xyz1, t_xyz xyz2, t_xyz xyz3);

t_near	square(t_sqr *sqr, t_cam cam, t_xyz cam1, t_xyz ray);
void	square_tops(t_sqr *sqr, t_xyz cam);

t_near	cylinder(t_cyl *cyl, t_cam cam, t_xyz cam1, t_xyz ray);
t_near	intersect_cyl(t_cyl *cyl, t_xyz cam, t_xyz cam1, t_xyz ray);
t_util	substitution_cyl1(t_cyl cyl, t_xyz cam, t_xyz ray, t_canv canv);
t_util	substitution_cyl2(t_cyl cyl, t_xyz cam, t_xyz ray, t_canv canv);
t_util	substitution_cyl3(t_cyl cyl, t_xyz cam, t_xyz ray, t_canv canv);
t_near	solution_cyl1(t_cyl cyl, t_util var, t_xyz cam);
t_near	solution_cyl2(t_cyl cyl, t_util var, t_xyz cam);
t_near	solution_cyl3(t_cyl cyl, t_util var, t_xyz cam);
t_xyz	cylinder_normal(t_cyl cyl, t_xyz dot);

int		change_camera(t_cam **camera);
int		key_pressed(int keycode, t_mlx *g_mlx);

int		brightness(t_near dot, t_lht *lht);
int		shadow(t_scene g_scene, t_near dot, t_xyz light);
int		shadow_pln(t_pln *pln, t_xyz dot, t_xyz dot1, t_xyz ray);
int		shadow_sph(t_sph *sph, t_xyz light, t_xyz dot, t_xyz ray);
int		shadow_tri(t_tri *tri, t_xyz light, t_xyz dot, t_xyz ray);
int		get_color(int color, int rgb, int light_color, double bright);
#endif
