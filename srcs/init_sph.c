/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:38:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/20 19:18:37 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static int	get_next_cel(const char *line, int *index)
{
	while (line[*index] != '[' && line[*index] != '\0')
		++*index;
	*index = (line[*index] == '\0') ? -1 : *index;
	return (*index);
}

void		init_sph(t_env *env, const char *line)
{
	env->cur->type = SPH;
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->o.x = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->o.y = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->o.z = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->size = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->col.r = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->col.g = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->col.b = ft_atoi(line + ++env->i);
}
