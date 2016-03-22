/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 07:42:27 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/20 19:56:37 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static void	init_pnt(t_env *env, t_pnt *cur)
{
	*cur = env->cam.o;
	pnt_translate(cur, env->cam.vy, CDTP);
	pnt_translate(cur, env->cam.vx, -(P_WID / 2));
	pnt_translate(cur, env->cam.vz, P_HEI / 2);
}

static void	init_ray(t_env *env, t_pnt cur)
{
	env->ray.o = env->cam.o;
	env->ray.v.x = cur.x - env->ray.o.x;
	env->ray.v.y = cur.y - env->ray.o.y;
	env->ray.v.z = cur.z - env->ray.o.z;
	env->ray.dist = -1;
}

static void	img_clear(t_img *img, t_color col)
{
	int	y;
	int	x;

	y = 0;
	while (y < img->hei)
	{
		x = 0;
		while (x < img->wid)
		{
			img_pixel_put(img, x, y, col);
			++x;
		}
		++y;
	}

}

void		render_loop(t_env *env)
{
	t_pnt	cur;
	double	w_coef;
	double	h_coef;
	int		x;
	int		y;

	w_coef = (double)P_WID / (double)WID;
	h_coef = (double)P_HEI / (double)HEI;
	init_pnt(env, &cur);
	y = -1;
	img_clear(&env->img, color_get(0, 0, 0, 0));
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
		{
			env->dist = -1;
			init_ray(env, cur);
			check_colision(env);
			(env->dist != -1) ? img_pixel_put(&env->img, x, y, env->col) : 0;
			pnt_translate(&cur, env->cam.vx, w_coef);
			if (cam_moving(env))
			{
				++x;
				pnt_translate(&cur, env->cam.vx, w_coef);
			}
		}
		if (cam_moving(env))
		{
			++y;
			pnt_translate(&cur, env->cam.vz, -h_coef);
		}
		pnt_translate(&cur, env->cam.vx, -w_coef * WID);
		pnt_translate(&cur, env->cam.vz, -h_coef);
	}
}
