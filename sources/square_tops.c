#include <math.h>
#include "minirt.h"

static t_xyz	top1(double sin_a, double cos_a,\
					double sin_b, double cos_b, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x + sqr.side / 2 * sin_a - sqr.side / 2 * sin_b * cos_a;
	res.y = sqr.pln.xyz.y - sqr.side / 2 * cos_a - sqr.side / 2 * sin_b * sin_a;
	res.z = sqr.pln.xyz.z + sqr.side / 2 * cos_b;
	return (res);
}

static t_xyz	top2(double sin_a, double cos_a,\
					double sin_b, double cos_b, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x - sqr.side / 2 * sin_a - sqr.side / 2 * sin_b * cos_a;
	res.y = sqr.pln.xyz.y + sqr.side / 2 * cos_a - sqr.side / 2 * sin_b * sin_a;
	res.z = sqr.pln.xyz.z + sqr.side / 2 * cos_b;
	return (res);
}

static t_xyz	top3(double sin_a, double cos_a,\
					double sin_b, double cos_b, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x - sqr.side / 2 * sin_a + sqr.side / 2 * sin_b * cos_a;
	res.y = sqr.pln.xyz.y + sqr.side / 2 * cos_a + sqr.side / 2 * sin_b * sin_a;
	res.z = sqr.pln.xyz.z - sqr.side / 2 * cos_b;
	return (res);}

static t_xyz	top4(double sin_a, double cos_a,\
					double sin_b, double cos_b, t_sqr sqr)
{
	t_xyz	res;

	res.x = sqr.pln.xyz.x + sqr.side / 2 * sin_a + sqr.side / 2 * sin_b * cos_a;
	res.y = sqr.pln.xyz.y - sqr.side / 2 * cos_a + sqr.side / 2 * sin_b * sin_a;
	res.z = sqr.pln.xyz.z - sqr.side / 2 * cos_b;
	return (res);
}

void			square_tops(t_sqr *sqr, t_xyz cam)
{
	double	sin_a;
	double	cos_a;
	double	sin_b;
	double	cos_b;

	while (sqr)
	{
		sin_b = sqr->pln.orient.z;
		cos_b = sqrt(fabs(1 - pow(sin_b, 2)));
		cos_a = (cos_b != 0) ? sqr->pln.orient.x / cos_b : 0;
		sin_a = sqrt(fabs(1 - pow(cos_a, 2)));;
		sqr->top1 = top1(sin_a, cos_a, sin_b, cos_b, *sqr);
		sqr->top2 = top2(sin_a, cos_a, sin_b, cos_b, *sqr);
		sqr->top3 = top3(sin_a, cos_a, sin_b, cos_b, *sqr);
		sqr->top4 = top4(sin_a, cos_a, sin_b, cos_b, *sqr);
		sqr->tri1.top1 = sqr->top1;
		sqr->tri1.top2 = sqr->top2;
		sqr->tri1.top3 = sqr->top3;
		sqr->tri2.top1 = sqr->top3;
		sqr->tri2.top2 = sqr->top4;
		sqr->tri2.top3 = sqr->top1;
		sqr->pln.normal = f_normal(sqr->pln.orient, sqr->pln.xyz, cam);
		sqr = sqr->next;
	}
}