/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 09:20:08 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/19 09:24:31 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	img_pixel_put(t_img *img, int x, int y, t_color col)
{
	if (0 < x && x < img->wid && 0 < y && y < img->hei)
		*(unsigned int*)(img->data + x * img->bpp + y * img->sl) =
			color_convert(col);
}
