/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 07:48:59 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 07:50:15 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	pnt_translate(t_pnt	*pnt, t_vec vec, double coef)
{
	pnt->x += vec.x * coef;
	pnt->y += vec.y * coef;
	pnt->z += vec.z * coef;
}
