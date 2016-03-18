/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:09:33 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/14 14:46:38 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"

static int	lengt_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i + 1);
}

static int	realloc_str(char ***line, char **st_str, char *tmp, int *len)
{
	if (**line)
		free(**line);
	**line = 0;
	**line = ft_strdup(*st_str);
	if (*st_str)
		free(*st_str);
	*st_str = 0;
	*st_str = ft_strnew(*len);
	ft_bzero(*st_str, *len);
	ft_strcat(*st_str, **line);
	if (**line)
		free(**line);
	**line = 0;
	ft_strcat(*st_str, tmp);
	ft_bzero(tmp, BUFF_SIZE);
	return (1);
}

static void	truncate_str(char ***line, char **st_str, char **tmp2)
{
	*tmp2 = ft_strchr(*st_str, '\n');
	**tmp2 = 0;
	if (**line)
		free(**line);
	**line = 0;
	**line = ft_strdup(*st_str);
	**tmp2 = '\n';
	*tmp2 = ft_strdup(*st_str + lengt_line(*st_str));
	if (*st_str)
		free(*st_str);
	*st_str = *tmp2;
}

static int	end_file(char ***line, char **st_str)
{
	if (**line)
		free(**line);
	**line = 0;
	**line = ft_strdup(*st_str);
	if (ft_strlen(**line) > 0)
	{
		if (*st_str)
			free(*st_str);
		*st_str = 0;
		return (1);
	}
	if (*st_str)
		free(*st_str);
	*st_str = 0;
	if (**line)
		free(**line);
	**line = 0;
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*st_str = 0;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			len;
	int			ret;

	len = ft_strlen(st_str);
	if (fd < 0 || line == 0)
		return (-1);
	while (!ft_strchr(st_str, '\n'))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
			return (end_file(&line, &st_str));
		len = len + ret;
		if (!realloc_str(&line, &st_str, buf, &len))
			return (-1);
	}
	truncate_str(&line, &st_str, &tmp);
	return (1);
}
