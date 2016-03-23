/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_mv_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 20:55:46 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/23 20:56:12 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	cam_mv_y(t_env *env, int dir)
{
	env->cam.o.x += env->cam.vy.x * dir;
	env->cam.o.y += env->cam.vy.y * dir;
	env->cam.o.z += env->cam.vy.z * dir;
	env->draw = 1;
}
