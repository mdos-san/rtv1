/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 07:42:27 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 08:05:52 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	render_loop(t_env *env)
{
	t_pnt	cur;
	double	w_coef;
	double	h_coef;
	int		x;
	int		y;

	cur = env->cam.o;
	w_coef = P_WID /WID;
	h_coef = P_HEI / HEI;
	pnt_translate(&cur, env->cam.vy, 10);
	pnt_translate(&cur, env->cam.vx, -(P_WID / 2));
	pnt_translate(&cur, env->cam.vz, P_HEI / 2);
	y = 0;
	while (y < HEI)
	{
		x = 0;
		while (x < WID)
		{
			pnt_translate(&cur, env->cam.vx, w_coef);
			++x;
		}
		pnt_translate(&cur, env->cam.vx, -w_coef * WID);
		pnt_translate(&cur, env->cam.vz, -h_coef);
		++y;
	}
	ft_putendl("Rendering done, enjoy ! <3");
}
