/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pla.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:58:37 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/20 18:09:30 by mdos-san         ###   ########.fr       */
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

void	init_pla(t_env *env, const char *line)
{
	env->cur->type = PLA;
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->o.x = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->o.y = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->o.z = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->v.x = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->v.y = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->v.z = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->col.r = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->col.g = ft_atoi(line + ++env->i);
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	env->cur->col.b = ft_atoi(line + ++env->i);
	env->cur->d = -(env->cur->o.x * env->cur->v.x +
					env->cur->o.y * env->cur->v.y +
					env->cur->o.z * env->cur->v.z);
}
