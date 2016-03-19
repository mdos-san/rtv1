/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 07:01:17 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 02:07:50 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_V1_H
# define RT_V1_H

# include <unistd.h>
# include <fcntl.h> 
# include <mlx.h>

# include "libft.h"
# include "get_next_line.h"
# include "libcolor.h"

# define WID 800
# define HEI 600

# define SPH 0
# define PLA 1
# define CYL 2
# define CON 3

typedef struct		s_obj
{
	char			type;
	double			x;
	double			y;
	double			y;
	struct s_obj	*next;
}					t_obj

typedef struct		s_env
{
	char			*file;
	int				fd;
}					t_env;

t_env				*rt_v1_init(char *file);
void				rt_v1_exit(t_env **env, char *str);
void				rt_v1_get_info(t_env *env);
int					parse(t_env *env);

#endif
