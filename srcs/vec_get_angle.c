/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:54:43 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/21 18:27:13 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	vec_get_angle(t_vec v1, t_vec v2)
{
	double	n;
	double	d;
	double	angle;

	n = 0.5 * (
		pow(vec_lenght(vec_get(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z)), 2) -
		pow(vec_lenght(v1), 2) - pow(vec_lenght(v2), 2)); 
	d = vec_lenght(v1) * vec_lenght(v2);
	angle = acos(n / d) * 180.0 / M_PI;
	return (angle);
}
