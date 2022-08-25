/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:58:31 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/23 04:58:49 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp) (char *, char *))
{
	int		index;
	int		min_index;
	char	*temp;

	index = 1;
	while (tab[index] != NULL)
	{
		temp = tab[index];
		min_index = index - 1;
		while (min_index >= 0 && cmp(temp, tab[min_index]) < 0)
		{
			tab[min_index + 1] = tab[min_index];
			min_index--;
		}
		tab[min_index + 1] = temp;
		index++;
	}
}
