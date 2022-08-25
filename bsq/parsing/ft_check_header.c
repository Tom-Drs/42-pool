/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 05:35:16 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/24 14:56:57 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_parsing.h"

int	ft_get_map_height(char **map)
{
	int	index;

	index = 0;
	while (map[index] != NULL)
		index++;
	return (index - 1);
}

char	*ft_get_char(char **map)
{
	int		size;
	int		height;
	char	*header_char;
	char	*header_height;

	header_char = malloc(sizeof(char) * 3);
	if (map[0] == NULL)
		return (NULL);
	size = ft_strlen(map[0]);
	header_height = ft_itoa_base(ft_get_map_height(map), "0123456789", 10);
	if (header_height == NULL)
		return (ft_free_char(header_height));
	height = ft_strlen(header_height);
	if (height + 2 < size)
	{
		header_char[0] = map[0][height++];
		header_char[1] = map[0][height++];
		header_char[2] = map[0][height];
		free(header_height);
		return (header_char);
	}
	else
		return (ft_free_char(header_height));
}

int	ft_is_valid_char(char **map)
{
	char	*header_char;
	char	empty;
	char	obstacle;
	char	filled;
	char	current;

	header_char = ft_get_char(map);
	if (header_char == NULL)
		return (0);
	if (ft_is_printable(header_char[0]))
		empty = header_char[0];
	else
		return (!ft_free_bool(header_char));
	current = header_char[1];
	if (ft_is_printable(current) && current != empty)
		obstacle = current;
	else
		return (!ft_free_bool(header_char));
	current = header_char[2];
	if (ft_is_printable(current)
		&& current != empty && current != obstacle)
		filled = current;
	else
		return (!ft_free_bool(header_char));
	return (ft_free_bool(header_char));
}

int	ft_is_valid_line(char **map)
{
	int		index;
	char	*height;

	index = 0;
	height = ft_itoa_base(ft_get_map_height(map), "0123456789", 10);
	if (map[0] == NULL || height == NULL)
		return (!ft_free_bool(height));
	while (height[index] != '\0')
	{
		if (map[0][index] != height[index])
			return (!ft_free_bool(height));
		index++;
	}
	free(height);
	return (index);
}

int	ft_is_valid_header(char **map)
{
	return (ft_is_valid_line(map) && ft_is_valid_char(map));
}
