/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:37:38 by bboisson          #+#    #+#             */
/*   Updated: 2022/08/21 18:54:13 by bboisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <unistd.h>

int	ft_strlen_jump_zero(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] == '0')
		i++;
	while (str[i++])
		size++;
	return (size);
}

int	ft_dictionnary_limit(t_dict **dict, int arg_size, int max_size)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i])
	{
		if (dict[i]->size > max_size)
		{
			if ((dict[i]->size % 3) == 1 && dict[i]->key[0] == '1')
			{
				j = 1;
				while (dict[i]->key[j] == '0')
					j++;
				if (!dict[i]->key[j])
					max_size = dict[i]->size;
			}
		}
		i++;
	}
	if (arg_size > (max_size + 2))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}
