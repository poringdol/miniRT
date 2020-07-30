/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 07:22:33 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/30 07:22:36 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define LIGHT 1000
# define SHINE 64

int		sepia(void);
int		directional_light(int color, t_near dot, t_lht_d *lht);
int		shadow_direct(t_scene g_scene, t_near dot, t_xyz ray);
void	minirt_shine(char *save);
void	render_shine(char *save);
int		brightness_bonus(t_near dot, t_lht *lht, t_lht_d *lht_d, t_xyz cam);
int		reflect_light(int color, t_near dot, t_xyz light, t_xyz cam);
/*
**t_near	cub(t_cub *cub, t_cam cam, t_xyz cam1, t_xyz ray);
**void	fill_cub(double buf[BUF_S], char *freeline, int l);
**t_near	nearest_pix_bonus(t_xyz cam, t_xyz cam1, t_xyz ray, t_near nearest);
*/

#endif
