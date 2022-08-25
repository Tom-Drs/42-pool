/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comeback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:57:31 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/14 23:07:10 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_get_number_remove(int index_line)
{
	int	number_remove;
	int	count;

	number_remove = 4;
	count = 0;
	while (count < index_line)
	{
		if (count % 2 == 1 && index_line % 2 == 0)
			number_remove--;
		if (count % 2 == 0 && index_line % 2 == 1)
			number_remove--;
		count++;
	}
	return (number_remove);
}

void	ft_remove_row(char *str, int index_line, int number_remove)
{
	int	index_str;

	if (index_line != 0)
		index_str = (index_line / 2) * 4 + 3;
	else
		index_str = 3;
	while (number_remove > 0)
	{
		str[index_str] = '0';
		number_remove--;
		index_str--;
	}
}

void	ft_remove_column(char *str, int index_line, int number_remove)
{
	int	index_str;

	index_str = (index_line / 2) + 3 * 4;
	while (number_remove > 0)
	{
		str[index_str] = '0';
		number_remove--;
		index_str -= 4;
	}
}

void	ft_remove_line(char *str, int index_line, int number_remove)
{
	if (index_line % 2 == 0)
		ft_remove_row(str, index_line, number_remove);
	else
		ft_remove_column(str, index_line, number_remove);
}

int	ft_comeback(char *str)
{
	int		index;
	char	*line;
	int		index_line;

	index = 0;
	index_line = 0;
	while (index < 8)
	{
		index_line = 0;
		line = ft_get_line(str, index);
		if (line == NULL)
			return (-1);
		while (line[index_line] != '\0' && line[index_line] != '0')
			index_line++;
		free(line);
		if (index_line != 4)
		{
			ft_remove_line(str, index - 1, ft_get_number_remove(index - 1));
			return (1);
		}
		index++;
	}
	return (1);
}
