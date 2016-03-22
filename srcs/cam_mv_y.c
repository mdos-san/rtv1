#include "rt_v1.h"

void	cam_mv_y(t_env *env, int dir)
{
	env->cam.o.x += env->cam.vy.x * 0.3 * dir;
	env->cam.o.y += env->cam.vy.y * 0.3 * dir;
	env->cam.o.z += env->cam.vy.z * 0.3 * dir;
	env->draw = 1;
}
