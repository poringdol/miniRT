/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:13:44 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 06:19:33 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_xyz
{
	double			x;
	double			y;
	double			z;
}					t_xyz;

typedef struct		s_res
{
	int				width;
	int				height;
}					t_res;

typedef struct		s_canv
{
	double			width;
	double			height;
	t_xyz			o;
	double			sin_a;
	double			cos_a;
	double			sin_b;
	double			cos_b;

}					t_canv;

typedef struct		s_amb
{
	double			lht_rat;
	int				rgb;
}					t_amb;

typedef struct		s_cam
{
	t_xyz			xyz;
	t_xyz			orient;
	int				fov;
	struct s_cam	*next;

}					t_cam;

typedef struct		s_lht
{
	t_xyz			xyz;
	double			bri;
	int				rgb;
	struct s_lht	*next;
}					t_lht;

typedef struct		s_lht_d
{
	t_xyz			direct;
	double			bri;
	int				rgb;
	struct s_lht_d	*next;
}					t_lht_d;

typedef struct		s_pln
{
	t_xyz			xyz;
	t_xyz			orient;
	int				rgb;
	t_xyz			normal;
	struct s_pln	*next;
}					t_pln;

typedef struct		s_sph
{
	t_xyz			o;
	double			diameter;
	int				rgb;
	struct s_sph	*next;
}					t_sph;

typedef struct		s_tri
{
	t_xyz			t1;
	t_xyz			t2;
	t_xyz			t3;
	t_pln			pln;
	int				rgb;
	struct s_tri	*next;
}					t_tri;

typedef struct		s_sqr
{
	double			side;
	t_pln			pln;
	t_xyz			t1;
	t_xyz			t2;
	t_xyz			t3;
	t_xyz			t4;
	t_tri			tri1;
	t_tri			tri2;
	struct s_sqr	*next;
}					t_sqr;

typedef struct		s_cyl
{
	t_xyz			o;
	t_xyz			o1;
	t_xyz			orient;
	double			diameter;
	double			height;
	int				rgb;
	struct s_cyl	*next;
}					t_cyl;

typedef struct		s_cub
{
	t_sqr			sqr[6];
	t_xyz			o;
	struct s_cub	*next;
}					t_cub;

typedef struct		s_pyr
{
	t_sqr			sqr;
	t_xyz			top;
	double			height;
	t_tri			tri[4];
	struct s_pyr	*next;
}					t_pyr;

typedef struct		s_con
{
	t_xyz			o;
	t_xyz			orient;
	double			height;
	int				rgb;
	struct s_con	*next;
}					t_con;

typedef struct		s_util
{
	double			ay;
	double			by;
	double			az;
	double			bz;
	double			n;
	double			m;
	double			k;
	double			l;
	double			i;
	double			j;
	double			discr;
	double			a;
	double			b;
	double			c;
}					t_util;

typedef struct		s_scene
{
	int				param;
	t_res			res;
	t_amb			amb;
	t_canv			canvas;
	t_cam			*cam;
	t_lht			*lht;
	t_pln			*pln;
	t_sph			*sph;
	t_sqr			*sqr;
	t_cyl			*cyl;
	t_tri			*tri;
	t_cub			*cub;
	t_pyr			*pyr;
	t_con			*con;
	t_lht_d			*lht_d;
}					t_scene;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pix_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx;

typedef struct		s_near
{
	t_xyz			xyz;
	t_xyz			normal;
	int				rgb;
	int				flag;
	int				flag2;
}					t_near;

typedef struct		s_subst
{
	double			a;
	double			b;
	double			c;
	double			ay;
	double			by;
	double			az;
	double			bz;
	double			discr;
}					t_subst;

typedef struct		s_rgb
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_rgb;

typedef struct		s_sc
{
	double			sin_a;
	double			cos_a;
	double			sin_b;
	double			cos_b;
}					t_sc;

#endif
