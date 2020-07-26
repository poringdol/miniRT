#include "minirt.h"

int		shadow_pln(t_pln *pln, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	while (pln && !shadow)
	{
		intersect = intersect_pln(*pln, light, dot, ray);
		if (intersect.flag
			&& vect_len(vect_cord(light, intersect.xyz)) <
			(vect_len(vect_cord(light, dot)) - 0.01)
			&& scal_product(vect_cord(light, dot),
							vect_cord(light, intersect.xyz)) - 0.01 > 0)
			shadow++;
		pln = pln->next;
	}
	return (shadow);
}

int		shadow_sph(t_sph *sph, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	while (sph && !shadow)
	{
		intersect = intersect_sph(*sph, dot, ray);
		if (intersect.flag && 
		scal_product(vect_cord(dot, intersect.xyz), 
					vect_cord(light, intersect.xyz)) < 0)
			shadow++;
		sph = sph->next;
	}
	return (shadow);
}

int		shadow_tri(t_tri *tri, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	while (tri && !shadow)
	{
		intersect = intersect_pln(tri->pln, light, dot, ray);
		if (intersect.flag2 &&
			check_side(intersect.xyz, tri->top1, tri->top2, tri->top3) &&
			check_side(intersect.xyz, tri->top2, tri->top3, tri->top1) &&
			check_side(intersect.xyz, tri->top3, tri->top1, tri->top2) &&
			scal_product(vect_cord(intersect.xyz, dot),
						vect_cord(intersect.xyz, light)) < 0)
			shadow++;
		tri = tri->next;
	}
	return (shadow);
}

int		shadow_sqr(t_sqr *sqr, t_xyz light, t_xyz dot, t_xyz ray)
{
	t_near	intersect;
	int		shadow;

	shadow = 0;
	while (sqr && !shadow)
	{
		intersect = intersect_pln(sqr->pln, light, dot, ray);
		if (intersect.flag2 &&
			((check_side(intersect.xyz, sqr->top1, sqr->top2, sqr->top3) &&
			check_side(intersect.xyz, sqr->top2, sqr->top3, sqr->top1) &&
			check_side(intersect.xyz, sqr->top3, sqr->top1, sqr->top2)) ||
			(check_side(intersect.xyz, sqr->top1, sqr->top3, sqr->top4) &&
			check_side(intersect.xyz, sqr->top3, sqr->top4, sqr->top1) &&
			check_side(intersect.xyz, sqr->top4, sqr->top1, sqr->top3))) &&
			scal_product(vect_cord(intersect.xyz, dot),
						vect_cord(intersect.xyz, light)) < 0)
			shadow++;
		sqr = sqr->next;
	}
	return (shadow);
}