/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 23:34:34 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 01:13:23 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_env	*rt_v1_init(char *file)
{
	t_env	*new;

	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	new->file = file;
	new->fd = 0;
	rt_v1_get_info(new);
	(parse(new) == 1) ? 0 : rt_v1_exit(&new, "Error in parsing :'( !");
	return (new);
}
