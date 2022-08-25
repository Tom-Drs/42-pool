/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:05:08 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/14 23:06:05 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_get_row(char *str, int index)
{
	char	*row;
	int		index_row;
	int		index_str;

	row = malloc(sizeof(char) * 5);
	if (row == NULL)
		return (NULL);
	index_row = 0;
	if (index != 0)
		index_str = (index / 2) * 4;
	else
		index_str = 0;
	while (index_row < 4)
	{
		row[index_row] = str[index_str];
		index_str++;
		index_row++;
	}
	row[index_row] = '\0';
	return (row);
}		

char	*ft_get_column(char *str, int index)
{
	char	*column;
	int		index_column;
	int		index_str;

	column = malloc(sizeof(char) * 5);
	if (column == NULL)
		return (NULL);
	index_column = 0;
	index_str = (index / 2);
	while (index_column < 4)
	{
		column[index_column] = str[index_str];
		index_str += 4;
		index_column++;
	}
	column[index_column] = '\0';
	return (column);
}

char	*ft_get_line(char *str, int index)
{	
	char	*line;

	if (index % 2 == 0)
		line = ft_get_row(str, index);
	else
		line = ft_get_column(str, index);
	if (line == NULL)
		return (NULL);
	return (line);
}
