/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rot_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:04:23 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/23 23:04:25 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	cam_rot_x(t_env *env, int dir)
{
	t_vec	tmpy;

	tmpy = env->cam.vy;
	vec_add(&env->cam.vy, env->cam.vz, 0.05 * dir);
	vec_add(&env->cam.vz, tmpy, 0.05 * -dir);
	++env->draw;
}
