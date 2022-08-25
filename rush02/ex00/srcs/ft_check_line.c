/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:15:53 by hdupuy            #+#    #+#             */
/*   Updated: 2022/08/21 18:09:53 by hdupuy           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	ft_get_validy_key(char *line)
{
	int		index_start;
	int		index_end;
	int		key;

	index_start = 0;
	while (ft_is_isspace(line[index_start]))
		index_start++;
	if (line[index_start] != '+'
		&& !(line[index_start] >= '0' && line[index_start] <= '9'))
		return (0);
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
		key = 1;
	else
		key = 1;
	return (key);
}

int	ft_get_validy_value(char *line)
{
	int		index_start;
	int		index_end;
	int		line_len;

	index_start = 0;
	index_end = 0;
	line_len = ft_strlen(line);
	while (line[index_start] != ':' && index_start < line_len)
		index_start++;
	if (index_start == line_len)
		return (0);
	index_start++;
	while (line[index_start] == ' ')
		index_start++;
	index_end = index_start + 1;
	while (ft_is_printable(line[index_end]))
		index_end++;
	return (1);
}

int	ft_line_is_valid(char *line)
{
	return (ft_get_validy_key(line) && ft_get_validy_value(line));
}
