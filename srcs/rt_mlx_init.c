/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 04:36:01 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 04:39:29 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	rt_mlx_init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		rt_v1_exit(&env, "Failling to start mlx :/");
	if (!(env->win = mlx_new_window(env->mlx, WID, HEI, "mdos-san's RTv1")))
		rt_v1_exit(&env, "Failling create a window :/");
	if (!(env->img.ptr = mlx_new_image(env->mlx, WID, HEI)))
		rt_v1_exit(&env, "Failling create an image :/");
	env->img.wid = WID;
	env->img.hei = HEI;
	if (!(env->img.data = mlx_get_data_addr(env->img.ptr,
			&env->img.bpp, &env->img.sl, &env->img.ed)))
		rt_v1_exit(&env, "Failling to get data :/");
	env->img.bpp /= 8;
}
