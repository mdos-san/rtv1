#include "rt_v1.h"

void	cam_rot_x(t_env *env, int dir)
{
	t_vec	tmpy;

	tmpy = env->cam.vy;
	vec_add(&env->cam.vy, env->cam.vz, 0.1 * dir);
	vec_add(&env->cam.vz, tmpy, 0.1 * -dir);
	++env->draw;
}
