/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:15:08 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/21 21:30:42 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_file_get_size(char *file_name)
{
	char	buf[101];
	int		fd;
	int		size;
	int		ret;
	int		ret_close;

	size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = read(fd, buf, 100);
	while (ret)
	{
		buf[ret] = '\0';
		size += 100;
		ret = read(fd, buf, 100);
	}
	ret_close = close(fd);
	if (ret_close == -1)
		return (-1);
	return (size);
}

char	*ft_read_file(char *file_name)
{
	char	*buf;
	int		size;
	int		ret;
	int		fd;
	int		ret_close;

	size = ft_file_get_size(file_name);
	if (size == -1)
		return (NULL);
	buf = malloc(sizeof(char) * (size + 1));
	if (buf == NULL)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buf, size);
	buf[ret] = '\0';
	ret_close = close(fd);
	if (ret_close == -1)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
