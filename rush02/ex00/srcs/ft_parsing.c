/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 00:00:18 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/21 22:46:12 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_get_value(char *line)
{
	int		index_start;
	int		index_end;
	int		line_len;
	char	*value;

	index_start = 0;
	index_end = 0;
	line_len = ft_strlen(line);
	while (line[index_start] != ':' && index_start < line_len)
		index_start++;
	if (index_start == line_len)
		return (NULL);
	index_start++;
	while (line[index_start] == ' ')
		index_start++;
	index_end = index_start + 1;
	while (ft_is_printable(line[index_end]))
		index_end++;
	value = ft_strdup_index(line, index_start, index_end);
	return (value);
}

char	*ft_get_key(char *line)
{
	int		index_start;
	int		index_end;
	char	*key;

	index_start = 0;
	while (ft_is_isspace(line[index_start]))
		index_start++;
	if (line[index_start] != '+'
		&& !(line[index_start] >= '0' && line[index_start] <= '9'))
		return (NULL);
	if (line[0] == '+')
		index_start++;
	while (line[index_start] == '0')
		index_start++;
	if (line[index_start] >= '1' && line[index_start] <= '9')
		index_end = index_start + 1;
	else
		index_end = index_start;
	while (line[index_end] >= '0' && line[index_end] <= '9')
		index_end++;
	if (index_start == index_end)
		key = ft_strdup_index(line, index_start - 1, index_start);
	else
		key = ft_strdup_index(line, index_start, index_end);
	return (key);
}

t_dict	*ft_parse_line(char *line)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (dict == NULL)
		return (NULL);
	dict->value = ft_get_value(line);
	dict->key = ft_get_key(line);
	dict->size = ft_strlen(dict->key);
	return (dict);
}

int	ft_count_valid_lines(char **lines)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (lines[index] != NULL)
	{
		count += ft_line_is_valid(lines[index]);
		index++;
	}
	return (count);
}

t_dict	**ft_parse(char *file_name, int index_tab, int index_lines)
{
	t_dict	**tab;
	char	*data;
	char	**lines;

	data = ft_read_file(file_name);
	if (data == NULL)
		return (NULL);
	lines = ft_split(data, "\n");
	if (lines == NULL)
		return (NULL);
	if (ft_count_valid_lines(lines) == 0)
		return (ft_free_parsing(lines, data));
	tab = malloc(sizeof(t_dict) * (ft_count_valid_lines(lines) + 1));
	if (tab == NULL)
		return (NULL);
	while (lines[index_lines] != NULL)
	{
		if (ft_line_is_valid(lines[index_lines]))
			tab[index_tab++] = ft_parse_line(lines[index_lines]);
		index_lines++;
	}
	ft_free_parsing(lines, data);
	tab[index_tab] = NULL;
	return (tab);
}
