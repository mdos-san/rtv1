/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:59:41 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/21 17:35:42 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static int	light_sph(t_env *env)
{
	(void)env;
	return (1);
}

void		get_light(t_env *env)
{
	(env->cur->type == SPH) ? light_sph(env) : 0;
}