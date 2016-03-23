/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_mv_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 20:55:53 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/23 20:56:12 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	cam_mv_x(t_env *env, int dir)
{
	env->cam.o.x += env->cam.vx.x * dir;
	env->cam.o.y += env->cam.vx.y * dir;
	env->cam.o.z += env->cam.vx.z * dir;
	env->draw = 1;
}
