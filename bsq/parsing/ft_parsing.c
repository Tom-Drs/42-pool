/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:22:38 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/24 17:00:43 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_parsing.h"
#include "ft_string.h"

char	**ft_create_map(char **map, int y)
{
	char	**map_filter;
	int		index_line;

	index_line = 1;
	map_filter = malloc(sizeof(char *) * y);
	if (map_filter == NULL)
		return (NULL);
	while (map[index_line] != NULL)
	{
		map_filter[index_line - 1] = map[index_line];
		index_line++;
	}
	return (map_filter);
}

t_map_data	*ft_generate_map_data(char **map)
{
	t_map_data	*result;
	char		*header_char;

	if (!ft_is_valid_header(map))
		return (NULL);
	if (!ft_is_valid_map(map))
		return (NULL);
	result = malloc(sizeof(t_map_data));
	if (result == NULL)
		return (NULL);
	header_char = ft_get_char(map);
	if (header_char == NULL)
		return (NULL);
	result->x = ft_maplen(map[1], header_char);
	result->y = ft_get_map_height(map);
	result->empty_char = header_char[0];
	result->obstacle_char = header_char[1];
	result->filled_char = header_char[2];
	result->map = ft_create_map(map, result->y);
	free(header_char);
	if (result->map == NULL)
		return (NULL);
	return (result);
}

t_map_data	*ft_parse(char *file_name, int type)
{
	char			*data;
	char			**map;
	t_map_data		*result;

	if (type == 1)
		data = ft_read_file(file_name);
	else
		data = get_str_from_file();
	if (data == NULL)
		return (NULL);
	map = ft_split(data, "\n");
	if (map == NULL)
	{
		free(data);
		return (NULL);
	}
	result = ft_generate_map_data(map);
	free(data);
	free(map[0]);
	free(map);
	return (result);
}
