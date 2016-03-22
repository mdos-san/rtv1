#include "rt_v1.h"

void	cam_mv_y(t_env *env, int dir)
{
	env->cam.o.x += env->cam.vy.x * dir;
	env->cam.o.y += env->cam.vy.y * dir;
	env->cam.o.z += env->cam.vy.z * dir;
	env->draw = 1;
}
