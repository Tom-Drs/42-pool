/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 07:49:34 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/24 17:19:42 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_parsing.h"

int	ft_maplen(char *line, char *char_map)
{
	int	index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] != char_map[0] && line[index] != char_map[1]
			&& line[index] != char_map[2])
			return (-1);
		index++;
	}
	return (index);
}

int	ft_is_valid_map(char **map)
{
	int		width;
	int		index_line;
	char	*header_char;

	header_char = ft_get_char(map);
	if (header_char == NULL)
		return (0);
	index_line = 1;
	width = ft_maplen(map[1], header_char);
	if (width <= 0)
		return (!ft_free_bool(header_char));
	while (map[index_line] != NULL)
	{
		if (ft_maplen(map[index_line], header_char) != width)
			return (!ft_free_bool(header_char));
		index_line++;
	}
	return (ft_free_bool(header_char));
}
