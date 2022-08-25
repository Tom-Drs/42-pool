/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:40:35 by hdupuy            #+#    #+#             */
/*   Updated: 2022/08/21 21:29:30 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (i < 42)
		free(tab[i++]);
	free(tab);
}

int	ft_comp_init_keys(char **ref, t_dict **dict)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (ref[i])
	{
		k = 0;
		while (ref[i][k] == dict[j]->key[k] && ref[i][k] && dict[j]->key[k])
			k++;
		if (!ref[i][k] && !dict[j]->key[k])
		{
			j = 0;
			i++;
		}
		else
			j++;
		if (!dict[j])
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
	}
	return (1);
}

int	ft_check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_table_init(t_dict **dict)
{
	char	**ref;
	int		check;

	ref = malloc(sizeof(*ref) * (42));
	if (ref == NULL)
		return (0);
	ft_init_nine(ref);
	ft_init_ten(ref);
	ft_init_cent(ref);
	ft_init_hundred(ref);
	ft_init_others(ref);
	ref[41] = NULL;
	check = ft_comp_init_keys(ref, dict);
	ft_free(ref);
	return (check);
}
