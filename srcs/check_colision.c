/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 08:31:40 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/24 08:00:57 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int			sphere_colision(t_env *env, t_obj sph)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(env->ray.v.x, 2) + pow(env->ray.v.y, 2) + pow(env->ray.v.z, 2);
	b = 2 * (env->ray.v.x * (env->ray.o.x - sph.o.x) +
			env->ray.v.y * (env->ray.o.y - sph.o.y) +
			env->ray.v.z * (env->ray.o.z - sph.o.z));
	c = (pow(env->ray.o.x - sph.o.x, 2) + pow(env->ray.o.y - sph.o.y, 2) +
					pow(env->ray.o.z - sph.o.z, 2)) - pow(sph.size, 2);
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		env->ray.dist =
			((-b + sqrt(det)) / (2 * a) < (-b - sqrt(det)) / (2 * a)) ?
			(-b + sqrt(det)) / (2 * a) : (-b - sqrt(det)) / (2 * a);
		return (1);
	}
	else
		return (0);
}

int			plane_colision(t_env *env, t_obj pla)
{
	double	x;
	double	y;
	double	z;

	x = env->ray.o.x - pla.o.x;
	y = env->ray.o.y - pla.o.y;
	z = env->ray.o.z - pla.o.z;
	env->ray.dist = -((pla.v.x * x + pla.v.y * y + pla.v.z * z)
		/ (pla.v.x * env->ray.v.x + pla.v.y *
		env->ray.v.y + pla.v.z * env->ray.v.z));
	if (env->ray.dist > 0)
		return (1);
	else
		return (0);
}

/*
** x = o.x + v.x * t
** y = o.y + v.y * t
** z = o.z + v.z * t
** 
** 
** eq cyl basic
**
**	x^2 + y^2 = r^2
**
**	(o.x + v.x * t)^2 + (o.y + v.y * t)^2 - r^2 = 0
**	o.x^2 + 2 * v.x * t + v.x^2 * t^2 + o.y^2 + 2 * v.y * t + v.y^2 * t^2 - r^2 = 0
**  t^2 * (vx^2 + v.y^2) +
**
**
*/


int			cyl_colision(t_env *env, t_obj cyl)
{
	t_pnt	o;
	t_vec	v;
	double	r;
	double	det;
	double	a;
	double	b;
	double	c;

	o = env->ray.o;
	v = env->ray.v;
	r = 10;
	a = pow(v.x, 2) + pow(v.y, 2);
	b = 2 * o.x * v.x + 2 * o.y * v.y;
	c = o.x * o.x + o.y * o.y - r * r;
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		env->ray.dist =
			((-b + sqrt(det)) / (2 * a) > (-b - sqrt(det)) / (2 * a)) ?
			(-b + sqrt(det)) / (2 * a) : (-b - sqrt(det)) / (2 * a);
		return (1);
	}
	else
		return (0);
	(void)cyl;
}

static void	new_pnt(t_env *env)
{
	env->dist = env->ray.dist;
	env->col = env->cur->col;
	get_light(env);
}

void		check_colision(t_env *env)
{
	env->cur = env->obj;
	while (env->cur)
	{
		env->light = env->obj;
		if (env->cur->type != LUM)
			env->ft_ptr[(int)env->cur->type](env, *env->cur);
		((env->dist == -1 && env->ray.dist > 0) ||
			(0 < env->ray.dist && env->ray.dist < env->dist))
				? new_pnt(env) : 0;
		env->cur = env->cur->next;
	}
}
