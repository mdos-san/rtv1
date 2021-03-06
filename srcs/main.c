/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 06:54:40 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/20 20:08:33 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	main(int ac, char **av)
{
	t_env	*env;

	if (ac == 2)
	{
		if (!(env = rt_v1_init(av[1])))
			return (0);
		(parse(env) == 1) ? 0 : rt_v1_exit(&env, "Error in parsing :'( !");
		rt_v1_get_info(env);
		rt_mlx_init(env);
		render_loop(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
		mlx_loop(env->mlx);
		rt_v1_exit(&env, "Exiting, Good Bye <3 !");
	}
	rt_v1_exit(&env, "Error, check args :'( !");
	return (0);
}
