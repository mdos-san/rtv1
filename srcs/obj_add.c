/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 02:13:54 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/24 07:40:38 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	obj_add(t_obj **obj)
{
	if (*obj == NULL)
	{
		if (!(*obj = (t_obj*)malloc(sizeof(t_obj))))
			return (0);
		(*obj)->next = NULL;
		(*obj)->type = -1;
		(*obj)->o.x = 0;
		(*obj)->o.y = 0;
		(*obj)->o.z = 0;
		(*obj)->col = color_get(255, 255, 255, 0);
		return (1);
	}
	else
		return (obj_add(&(*obj)->next));
}
