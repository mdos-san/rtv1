/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 01:00:11 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/24 02:49:02 by mdos-san         ###   ########.fr       */
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

static void	get_name(t_env *env, const char *line)
{
	(ft_strncmp(line, "[sph]", 5) == 0) ? init_sph(env, line) : 0;
	(ft_strncmp(line, "[pla]", 5) == 0) ? init_pla(env, line) : 0;
	(ft_strncmp(line, "[cyl]", 5) == 0) ? (env->cur->type = CYL) : 0;
	(ft_strncmp(line, "[con]", 5) == 0) ? (env->cur->type = CON) : 0;
}

static int	read_cel(t_env *env, const char *line)
{
	env->i = 0;
	(get_next_cel(line, &env->i) == -1) ? rt_v1_exit(&env, ":( !") : 0;
	get_name(env, line + ++env->i - 1);
	return (1);
}

int			parse(t_env *env)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	if (!((env->fd = open(env->file, O_RDONLY)) > 0))
		rt_v1_exit(&env, "Can't open the file :'( !");
	while ((ret = get_next_line(env->fd, &line)) > 0)
	{
		if (line[0] != '#')
		{
			if (obj_add(&env->obj) == -1)
				rt_v1_exit(&env, "Failing sooooo sad :'/ !");
			env->cur = (env->cur != NULL) ? env->cur->next : env->obj;
			read_cel(env, line);
		}
		(line) ? free(line) : 0;
	}
	if (ret == -1)
		rt_v1_exit(&env, "Stop trying to open a dir noob <3!");
	close(env->fd);
	return (1);
}
