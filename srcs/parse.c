/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 01:00:11 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 01:14:40 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	parse(t_env *env)
{
	if (!(env->fd = open(env->file, O_RDONLY) > 0))	
		rt_v1_exit(&env, "Can't open the file :'( !");
	close(env->fd);
	return (1);
}
