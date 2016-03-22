#include "rt_v1.h"

int	cam_moving(t_env *env)
{
	if (env->ev_mvy == 0 &&
		env->ev_rotx == 0 &&
		env->ev_rotz == 0)
		return (0);
	return (1);
}
