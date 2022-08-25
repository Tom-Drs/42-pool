/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:03:36 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/23 04:55:56 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	int		index;
	int		min_index;
	char	*temp;

	index = 1;
	while (tab[index] != NULL)
	{
		temp = tab[index];
		min_index = index - 1;
		while (min_index >= 0 && ft_strcmp(temp, tab[min_index]) < 0)
		{
			tab[min_index + 1] = tab[min_index];
			min_index--;
		}
		tab[min_index + 1] = temp;
		index++;
	}
}
