#include "rt_v1.h"

void	cam_rot_y(t_env *env, int dir)
{
	t_vec	tmpx;

	tmpx = env->cam.vx;
	vec_add(&env->cam.vx, env->cam.vz, 0.05 * dir);
	vec_add(&env->cam.vz, tmpx, 0.05 * -dir);
	++env->draw;
}
