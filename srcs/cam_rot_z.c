/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rot_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:04:36 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/23 23:04:38 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	cam_rot_z(t_env *env, int dir)
{
	t_vec	tmpy;

	tmpy = env->cam.vy;
	vec_add(&env->cam.vy, env->cam.vx, 0.05 * dir);
	vec_add(&env->cam.vx, tmpy, 0.05 * -dir);
	++env->draw;
}
