/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:59:41 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/21 18:47:56 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static int	light_sph(t_env *env)
{
	t_vec	vn;
	t_vec	vl;
	t_pnt	pi;
	t_pnt	pc;
	double	angle;

	pi = env->ray.inter;
	pc = env->cur->o;
	vn = vec_get(pi.x - pc.x, pi.y - pc.y, pi.z - pc.z);
	vec_norm(&vn);
	while (env->light)
	{
		if (env->light->type == LUM)
		{
			pc = env->light->o;
			vl = vec_get(pc.x - pi.x, pc.y - pi.y, pc.z - pi.z);
			vec_norm(&vl);
			angle = vec_get_angle(vn, vl);
			angle = (90 - angle) / 360;
			env->col.r = (env->col.r * angle + env->light->col.r * angle >= 255) ? 255 : (env->col.r * angle + env->light->col.r * angle);
			env->col.g = (env->col.g * angle + env->light->col.g * angle >= 255) ? 255 : (env->col.g * angle + env->light->col.g * angle);
			env->col.b = (env->col.b * angle + env->light->col.b * angle >= 255) ? 255 : (env->col.b * angle + env->light->col.b * angle);
			if (angle < 0)
			{
				env->col.r = 0;
				env->col.g = 0;
				env->col.b = 0;
			}
		}
		env->light = env->light->next;
	}
	return (1);
}

void		get_light(t_env *env)
{
	env->ray.inter.x = env->ray.o.x + env->ray.v.x * env->ray.dist;
	env->ray.inter.y = env->ray.o.y + env->ray.v.y * env->ray.dist;
	env->ray.inter.z = env->ray.o.z + env->ray.v.z * env->ray.dist;
	(env->cur->type == SPH) ? light_sph(env) : 0;
}
