#include "rt_v1.h"

void	vec_add(t_vec *v1, t_vec v2, double coef)
{
	v1->x += v2.x * coef;
	v1->y += v2.y * coef;
	v1->z += v2.z * coef;
	vec_norm(v1);
}
