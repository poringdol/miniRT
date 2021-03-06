/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 07:22:33 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 06:35:08 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define LIGHT 1000
# define SHINE 64

int		fill_scene_bonus(double buf[BUF_S],
							char *line, char *freeline, int l);
int		sepia(void);
int		directional_light(int color, t_near dot, t_lht_d *lht);
int		shadow_direct(t_scene g_scene, t_near dot, t_xyz ray);
void	minirt_bonus(int param);
void	render_antialiasing(char *save);
int		brightness_bonus(t_near dot, t_lht *lht, t_lht_d *lht_d, t_xyz cam);
int		reflect_light(int color, t_near dot, t_xyz light, t_xyz cam);
void	color_table(void);
void	render_rainbow(char *save);
t_near	cub(t_cub *cub, t_cam cam, t_xyz cam1, t_xyz ray);
void	fill_cub(double buf[BUF_S], char *freeline, int l);
void	fill_pyramid(double buf[BUF_S], char *freeline, int l);
void	fill_cone(double buf[BUF_S], char *freeline, int l);
t_near	nearest_pix_bonus(t_xyz cam, t_xyz cam1, t_xyz ray, t_near nearest);
void	cub_triangle(t_sqr *sqr);
void	cub_planes(t_cub *cub);
void	cub_plane3(t_cub *cub);
void	cub_plane4(t_cub *cub);
void	cub_plane5(t_cub *cub);
void	cub_plane6(t_cub *cub);
int		shadow_cub(t_cub *c, t_xyz light, t_xyz dot, t_xyz ray);
t_near	pyramid(t_pyr *pyr, t_cam cam, t_xyz cam1, t_xyz ray);
void	pyramid_planes(t_pyr *pyr);
void	pyr_plane1(t_pyr *pyr);
void	pyr_plane2(t_pyr *pyr);
void	pyr_plane3(t_pyr *pyr);
void	pyr_plane4(t_pyr *pyr);
int		shadow_pyr(t_pyr *pyr, t_xyz light, t_xyz dot, t_xyz ray);
t_near	cone(t_con *con, t_cam cam, t_xyz cam1, t_xyz ray);
t_util	substitution_con1(t_con con, t_xyz cam, t_xyz ray, t_canv canv);
#endif
