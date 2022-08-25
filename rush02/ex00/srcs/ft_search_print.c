/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:10:15 by bboisson          #+#    #+#             */
/*   Updated: 2022/08/21 16:35:06 by bboisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <unistd.h>

void	ft_print(char *str, int index, char *arg, int type)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	if (type == 1 || ft_keep_printing(index + 1, arg))
		write(1, " ", 1);
}

char	*ft_search_unity(char c, int size_arg, t_dict **dict)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		if (dict[i]->key[0] == c && dict[i]->size == size_arg)
			return (dict[i]->value);
		i++;
	}
	return ("");
}

int	ft_keep_printing(int i, char *arg)
{
	while (arg[i])
	{
		if (arg[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_search_number(char *ten, t_dict **dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i])
	{
		j = 0;
		while (dict[i]->key[j] && dict[i]->key[j] == ten[j])
		{
			j++;
			if (!dict[i]->key[j] && !ten[j])
				return (dict[i]->value);
		}
		i++;
	}
	return ("");
}

int	ft_only_zero(char *arg, t_dict **dict)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != '0')
			return (0);
		i++;
	}
	ft_print(ft_search_unity('0', 1, dict), 1, arg, 0);
	write(1, "\n", 1);
	return (1);
}
