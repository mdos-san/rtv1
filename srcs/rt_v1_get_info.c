/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1_get_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 00:43:27 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/20 16:58:39 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static void	get_color_info(t_obj *obj)
{
	ft_putstr("R = ");
	ft_putnbrl(obj->col.r);
	ft_putstr("G = ");
	ft_putnbrl(obj->col.g);
	ft_putstr("B = ");
	ft_putnbrl(obj->col.b);
}

static void	chain_info(t_env *env)
{
	env->cur = env->obj;
	while (env->cur)
	{
		ft_putendl("\n**********\n");
		ft_putstr("Object type: ");
		(env->cur->type == SPH) ? ft_putendl("Sphere") : 0;
		(env->cur->type == PLA) ? ft_putendl("Plane") : 0;
		(env->cur->type == CYL) ? ft_putendl("Cylinder") : 0;
		(env->cur->type == CON) ? ft_putendl("Cone") : 0;
		ft_putstr("X = ");
		ft_putnbrl(env->cur->x);
		ft_putstr("Y = ");
		ft_putnbrl(env->cur->y);
		ft_putstr("Z = ");
		ft_putnbrl(env->cur->z);
		get_color_info(env->cur);
		env->cur = env->cur->next;
	}
}

void		rt_v1_get_info(t_env *env)
{
	ft_putstr("Name of the file: ");
	ft_putendl(env->file);
	chain_info(env);
}
