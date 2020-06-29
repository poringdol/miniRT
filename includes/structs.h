#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

typedef struct		s_xyz
{
	double			x;
	double			y;
	double			z;
}					t_xyz;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_canv
{
	double			x;
	double			y;
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
	double			lht_bri;
	int				rgb;
	struct s_lht	*next;
}					t_lht;

typedef struct		s_pln
{
	t_xyz			xyz;
	t_xyz			orient;
	int				rgb;
	struct s_pln	*next;
}					t_pln;

typedef struct		s_sph
{
	t_xyz			xyz;
	double			diameter;
	int				rgb;
	struct s_sph	*next;
}					t_sph;

typedef struct		s_sqr
{
	t_xyz			xyz;
	t_xyz			orient;
	double			size;
	int				rgb;
	struct s_sqr	*next;
}					t_sqr;

typedef struct		s_cyl
{
	t_xyz			xyz;
	t_xyz			orient;
	double			diameter;
	double			height;
	int				rgb;
	struct s_cyl	*next;
}					t_cyl;

typedef struct		s_tri
{
	t_xyz			xyz1;
	t_xyz			xyz2;
	t_xyz			xyz3;
	int				rgb;
	struct s_tri	*next;
}					t_tri;

typedef struct		s_scene
{
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
}					t_scene;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				size_l;
	int				endian;
}					t_mlx;

typedef struct		s_near
{
	t_xyz			xyz;
	int				rgb;
	int				flag;
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

#endif
