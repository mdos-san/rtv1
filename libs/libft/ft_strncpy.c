/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:51:18 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/03 12:31:39 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0' && i < n)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (i < n)
	{
		while (*(dst + i) != '\0' && i < n)
		{
			*(dst + i) = '\0';
			i++;
		}
	}
	return (dst);
}
