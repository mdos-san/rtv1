/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 04:36:01 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/24 02:30:34 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int		key_press(int keycode, t_env *env)
{
	(keycode == 0) ? (env->ev_mvx = -1) : 0;
	(keycode == 2) ? (env->ev_mvx = 1) : 0;
	(keycode == 119 || keycode == 13) ? (env->ev_mvy = 1) : 0;
	(keycode == 115 || keycode == 1) ? (env->ev_mvy = -1) : 0;
	(keycode == 65362 || keycode == 126) ? (env->ev_rotx = 1) : 0;
	(keycode == 65364 || keycode == 125) ? (env->ev_rotx = -1) : 0;
	(keycode == 113 || keycode == 12) ? (env->ev_roty = 1) : 0;
	(keycode == 101 || keycode == 14) ? (env->ev_roty = -1) : 0;
	(keycode == 65361 || keycode == 123) ? (env->ev_rotz = -1) : 0;
	(keycode == 65363 || keycode == 124) ? (env->ev_rotz = 1) : 0;
	return (1);
}

int		key_hook(int keycode, t_env *env)
{
	ft_putnbrl(keycode);
	(keycode == 53 || keycode == 65307)
	? rt_v1_exit(&env, "Program exited :3") : 0;
	(keycode == 0) ? (env->ev_mvx = 0) : 0;
	(keycode == 2) ? (env->ev_mvx = 0) : 0;
	(keycode == 119 || keycode == 13) ? (env->ev_mvy = 0) : 0;
	(keycode == 115 || keycode == 1) ? (env->ev_mvy = 0) : 0;
	(keycode == 113 || keycode == 12) ? (env->ev_roty = 0) : 0;
	(keycode == 101 || keycode == 14) ? (env->ev_roty = 0) : 0;
	(keycode == 65361 || keycode == 123) ? (env->ev_rotz = 0) : 0;
	(keycode == 65363 || keycode == 124) ? (env->ev_rotz = 0) : 0;
	(keycode == 65362 || keycode == 126) ? (env->ev_rotx = 0) : 0;
	(keycode == 65364 || keycode == 125) ? (env->ev_rotx = 0) : 0;
	env->draw = 1;
	return (1);
}

int		expose_hook(t_env *env)
{
	render_loop(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
	return (1);
}

int		loop_hook(t_env *env)
{
	(env->ev_mvx == 1) ? cam_mv_x(env, 1) : 0;
	(env->ev_mvx == -1) ? cam_mv_x(env, -1) : 0;
	(env->ev_mvy == 1) ? cam_mv_y(env, 1) : 0;
	(env->ev_mvy == -1) ? cam_mv_y(env, -1) : 0;
	(env->ev_rotx == 1) ? cam_rot_x(env, 1): 0;
	(env->ev_rotx == -1) ? cam_rot_x(env, -1): 0;
	(env->ev_roty == 1) ? cam_rot_y(env, 1): 0;
	(env->ev_roty == -1) ? cam_rot_y(env, -1): 0;
	(env->ev_rotz == -1) ? cam_rot_z(env, -1): 0;
	(env->ev_rotz == 1) ? cam_rot_z(env, 1): 0;
	if (env->draw != 0)
	{
		expose_hook(env);
		env->draw = 0;
	}
	return (1);
}

void		rt_mlx_init(t_env *env)
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
	mlx_hook(env->win, KP, KPM, key_press, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
}
