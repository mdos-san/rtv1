/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 19:30:35 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/24 02:19:55 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	obj_destroy(t_obj **obj)
{
	t_obj	*tmp;

	if (*obj)
		tmp = (*obj)->next;
	while (*obj)
	{
		if (*obj)
		{
			free(*obj);
			*obj = tmp;
			if (tmp)
				tmp = tmp->next;
		}
	}
}
