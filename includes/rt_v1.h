/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 07:01:17 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 00:54:51 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_V1_H
# define RT_V1_H

# include <mlx.h>

# include "libft.h"
# include "get_next_line.h"
# include "libcolor.h"

# define WID 800
# define HEI 600

# define SPHERE 0
# define PLAN 1
# define CYLINDER 2
# define CONE 3

typedef struct	s_env
{
	char	*file;
}				t_env;

t_env			*rt_v1_init(char *file);
void			rt_v1_exit(t_env **env);
void			rt_v1_get_info(t_env *env);

#endif
