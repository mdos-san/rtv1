/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 02:13:54 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 03:37:29 by mdos-san         ###   ########.fr       */
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
		(*obj)->x = 0;
		(*obj)->y = 0;
		(*obj)->z = 0;
		return (1);
	}
	else
		return (obj_add(&(*obj)->next));
}
