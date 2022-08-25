/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 05:39:09 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/23 05:39:49 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_parsing.h"

int	ft_file_get_size(char *file_name)
{
	char	*buf;
	int		fd;
	int		size;
	int		ret;
	int		ret_close;

	buf = malloc(sizeof(char) * (5000 + 1));
	if (buf == NULL)
		return (-1);
	size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_free_negative(buf));
	ret = read(fd, buf, 5000);
	while (ret)
	{
		buf[ret] = '\0';
		size += 5000;
		ret = read(fd, buf, 5000);
	}
	ret_close = close(fd);
	if (ret_close == -1)
		return (ft_free_negative(buf));
	free(buf);
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
		return (ft_free_char(buf));
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
