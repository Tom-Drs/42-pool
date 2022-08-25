/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:02:25 by bboisson          #+#    #+#             */
/*   Updated: 2022/08/21 22:47:25 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <stdlib.h>

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

void	ft_sort_dict(t_dict **dict)
{
	int		i;
	int		j;
	t_dict	*save;

	i = 0;
	while (dict[i])
	{
		j = i + 1;
		while (dict[j])
		{
			if (ft_strcmp(dict[i]->key, dict[j]->key) > 0)
			{
				save = dict[i];
				dict[i] = dict[j];
				dict[j] = save;
			}
			j++;
		}
		i++;
	}
}

void	ft_free_dict(t_dict **dict)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		free(dict[i]->key);
		free(dict[i]->value);
		free(dict[i]);
		i++;
	}
	free(dict);
}

t_dict	**ft_free_parsing(char **split, char *read)
{
	int	index;

	index = 0;
	while (split[index] != NULL)
		free(split[index++]);
	free(split);
	free(read);
	return (NULL);
}
