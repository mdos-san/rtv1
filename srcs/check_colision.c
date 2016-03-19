/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 08:31:40 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 10:07:19 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int		sphere_colision(t_env *env, t_obj sph)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(env->ray.v.x, 2) + pow(env->ray.v.y, 2) + pow(env->ray.v.z, 2);
	b = 2 * (env->ray.v.x * (env->ray.o.x - sph.x) +
			env->ray.v.y * (env->ray.o.y - sph.y) +
			env->ray.v.z * (env->ray.o.z - sph.z));
	c = (pow(env->ray.o.x - sph.x, 2) + pow(env->ray.o.y - sph.y, 2) +
					pow(env->ray.o.z - sph.z, 2)) - pow(RAYON, 2); 
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

void	check_colision(t_env *env)
{
	env->cur = env->obj;
	while (env->cur)
	{
		env->ft_ptr[(int)env->cur->type](env, *env->cur);
		env->cur = env->cur->next;
	}
}
