#include "minirt.h"

float	discriminant(float diameter, t_xyz ray, t_xyz cam_sph)
{
	float	a;
	float	b;
	float	c;

	a = pow(ray.x, 2) + pow(ray.y, 2) + pow(ray.z, 2);
	b = 2 * (ray.x * cam_sph.x + ray.y * cam_sph.y + ray.z * cam_sph.z);
	c = pow(cam_sph.x, 2) + pow(cam_sph.y, 2) +
	pow(cam_sph.z, 2) - pow(diameter / 2, 2);
	return (pow(b, 2) - 4 * a * c);
}

float	root1(t_xyz ray, t_xyz cam_sph, float discr)
{
	float	a;
	float	b;

	a = pow(ray.x, 2) + pow(ray.y, 2) + pow(ray.z, 2);
	b = 2 * (ray.x * cam_sph.x + ray.y * cam_sph.y + ray.z * cam_sph.z);
	return ((-b + discr) / (2 * a));
}

float	root2(t_xyz ray, t_xyz cam_sph, float discr)
{
	float	a;
	float	b;

	a = pow(ray.x, 2) + pow(ray.y, 2) + pow(ray.z, 2);
	b = 2 * (ray.x * cam_sph.x + ray.y * cam_sph.y + ray.z * cam_sph.z);
	return ((-b - discr) / (2 * a));
}

t_xyz	find_min(float t1, float t2, t_xyz cam, t_xyz ray)
{
	t_xyz		dot1;
	t_xyz		dot2;

	dot1.x = cam.x + t1 * ray.x;
	dot1.x = cam.y + t1 * ray.y;
	dot1.x = cam.z + t1 * ray.z;
	dot2.x = cam.x + t2 * ray.x;
	dot2.x = cam.y + t2 * ray.y;
	dot2.x = cam.z + t2 * ray.z;
	// if ((t1 < 1) ^ (t2 < 1))
	// 	return (t1 < 1 ? dot2 : dot1);
	return (vect_len(cam, dot1) < vect_len(cam, dot2) ? dot1 : dot2);
}

t_near	intersect_sph(t_sph sph, t_xyz cam, t_xyz ray)
{
	t_near		intersect;
	t_xyz		cam_sph;
	float		discr;
	float		t1;
	float		t2;

	cam_sph.x = sph.xyz.x - cam.x;
	cam_sph.y = sph.xyz.y - cam.y;
	cam_sph.z = sph.xyz.z - cam.z;
	ft_bzero(&intersect, sizeof(t_near));
	discr = discriminant(sph.diameter, ray, cam_sph);
	if (discr < 0)
		return (intersect);
	t1 = root1(ray, cam_sph, discr);
	t2 = root2(ray, cam_sph, discr);
	intersect.xyz = find_min(t1, t2, cam, ray);
	intersect.rgb = sph.rgb;
	intersect.flag = 1;
	return (intersect);
}
