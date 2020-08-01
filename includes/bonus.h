/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 07:22:33 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/31 05:22:19 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define LIGHT 1000
# define SHINE 64

int		sepia(void);
int		directional_light(int color, t_near dot, t_lht_d *lht);
int		shadow_direct(t_scene g_scene, t_near dot, t_xyz ray);
void	minirt_bonus(char *save);
void	render_antialiasing(char *save);
int		brightness_bonus(t_near dot, t_lht *lht, t_lht_d *lht_d, t_xyz cam);
int		reflect_light(int color, t_near dot, t_xyz light, t_xyz cam);
void	color_table(void);
void	render_rainbow(char *save);
int		rainbow(t_near dot, t_lht *lht, t_lht_d *lht_d, t_xyz cam);
t_near	cub(t_cub *cub, t_cam cam, t_xyz cam1, t_xyz ray);
void	fill_cub(double buf[BUF_S], char *freeline, int l);
t_near	nearest_pix_bonus(t_xyz cam, t_xyz cam1, t_xyz ray, t_near nearest);
void	cub_triangle(t_sqr *sqr);
void	cub_planes(t_cub *cub);
void	cub_plane3(t_cub *cub);
void	cub_plane4(t_cub *cub);
void	cub_plane5(t_cub *cub);
void	cub_plane6(t_cub *cub);

#endif
