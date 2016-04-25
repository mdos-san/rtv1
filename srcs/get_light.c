/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:59:41 by mdos-san          #+#    #+#             */
/*   Updated: 2016/04/22 15:38:14 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int			get_shadow(t_env *env)
{
	t_ray	r;
	t_pnt	l;
	t_pnt	i;
	t_pnt	o;

	if (cam_moving(env) == 0)
	{
		l = env->light->o;
		o = env->ray.inter;
		r = env->ray;
		env->shadow = env->obj;
		env->ray.o = r.inter;
		env->ray.v = vec_get(env->light->o.x - r.inter.x, env->light->o.y - r.inter.y, env->light->o.z - r.inter.z);
		vec_norm(&env->ray.v);
		while (env->shadow)
		{
			if (env->shadow->type != PLA && env->shadow->type != LUM && env->shadow->id != env->cur->id
					&& env->ft_ptr[(int)env->shadow->type](env, *env->shadow) && env->ray.dist > 0)
			{
				i.x = env->ray.o.x + env->ray.v.x * env->ray.dist;
				i.y = env->ray.o.y + env->ray.v.y * env->ray.dist;
				i.z = env->ray.o.z + env->ray.v.z * env->ray.dist;
				if (sqrt(pow(o.x - l.x, 2) + pow(o.y - l.y, 2) + pow(o.z - l.z, 2)) > sqrt(pow(o.x - i.x, 2) + pow(o.y - i.y, 2) + pow(o.z - i.z, 2)))
				{
					env->ray = r;
					return (1);
				}
			}
			env->shadow = env->shadow->next;
		}
		env->ray = r;
	}
	return (0);
}

static int	light_pla(t_env *env)
{
	double	angle;
	t_vec	vn;
	t_vec	vl;
	t_pnt	pi;
	t_pnt	pc;

	vn = env->cur->v;
	pi = env->ray.inter;
	env->col = color_get(0, 0, 0, 0);
	vec_norm(&vn);
	while (env->light)
	{
		if (env->light->type == LUM)
		{
			pc = env->light->o;
			vl = vec_get(pc.x - pi.x, pc.y - pi.y, pc.z - pi.z);
			vec_norm(&vl);
			angle = vec_dot(vn, vl);
			if (angle > 0 && get_shadow(env) == 0)
			{
				env->col.r = (env->col.r + env->cur->col.r * env->light->col.r * angle >= 255) ? 255 : (env->col.r + env->cur->col.r * env->light->col.r * angle);
				env->col.g = (env->col.g + env->cur->col.g * env->light->col.g * angle >= 255) ? 255 : (env->col.g + env->cur->col.g * env->light->col.g * angle);
				env->col.b = (env->col.b + env->cur->col.b * env->light->col.b * angle >= 255) ? 255 : (env->col.b + env->cur->col.b * env->light->col.b * angle);
			}
		}
		env->light = env->light->next;
	}
	return (1);
}

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
	env->col = color_get(0, 0, 0, 0);
	while (env->light)
	{
		if (env->light->type == LUM)
		{
			pc = env->light->o;
			vl = vec_get(pc.x - pi.x, pc.y - pi.y, pc.z - pi.z);
			vec_norm(&vl);
			angle = vec_dot(vn, vl);
			if (angle > 0 && get_shadow(env) == 0)
			{
				env->col.r = (env->col.r + env->cur->col.r * env->light->col.r * angle >= 255) ? 255 : (env->col.r + env->cur->col.r * env->light->col.r * angle);
				env->col.g = (env->col.g + env->cur->col.g * env->light->col.g * angle >= 255) ? 255 : (env->col.g + env->cur->col.g * env->light->col.g * angle);
				env->col.b = (env->col.b + env->cur->col.b * env->light->col.b * angle >= 255) ? 255 : (env->col.b + env->cur->col.b * env->light->col.b * angle);
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
	(env->cur->type == PLA) ? light_pla(env) : 0;
}
