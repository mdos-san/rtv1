/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 23:34:34 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 07:26:29 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static void	init_cam(t_env *env)
{
	env->cam.x = 0;
	env->cam.y = -100;
	env->cam.z = 0;
	env->cam.vx.x = 1;
	env->cam.vx.y = 0;
	env->cam.vx.z = 0;
	env->cam.vy.x = 0;
	env->cam.vy.y = 1;
	env->cam.vy.z = 0;
	env->cam.vz.x = 0;
	env->cam.vz.y = 0;
	env->cam.vz.z = 1;
}

t_env		*rt_v1_init(char *file)
{
	t_env	*new;

	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	new->debug = 1;
	new->file = file;
	new->fd = 0;
	new->obj = NULL;
	new->cur = NULL;
	init_cam(new);
	return (new);
}
