#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

typedef struct		s_xyz
{
	float			x;
	float			y;
	float			z;
}					t_xyz;

typedef struct		s_res
{
	short			x;
	short			y;
}					t_res;

typedef struct		s_amb
{
	float			lht_rat;
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
	float			lht_bri;
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
	float			diameter;
	int				rgb;
	struct s_sph	*next;
}					t_sph;

typedef struct		s_sqr
{
	t_xyz			xyz;
	t_xyz			orient;
	float			size;
	int				rgb;
	struct s_sqr	*next;
}					t_sqr;

typedef struct		s_cyl
{
	t_xyz			xyz;
	t_xyz			orient;
	float			diameter;
	float			height;
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
	t_res			*res;
	t_amb			*amb;
	t_cam			*cam;
	t_lht			*lht;
	t_pln			*pln;
	t_sph			*sph;
	t_sqr			*sqr;
	t_cyl			*cyl;
	t_tri			*tri;
}					t_scene;

#endif
