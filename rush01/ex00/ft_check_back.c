/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:25:47 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/14 23:26:43 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_is_finish(struct s_grid grid, int pos)
{
	if (pos == 8)
	{
		ft_put(grid.tab);
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

int	ft_check(char *tab, char *new, int pos)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (pos % 2 == 0)
		{
			if (tab[(pos / 2) * 4 + i] != '0'\
					&& new[i] != tab[(pos / 2) * 4 + i])
				return (0);
		}
		if (pos % 2 == 1)
		{
			if (tab[pos / 2 + 4 * i] != '0'\
					&& new[i] != tab[pos / 2 + 4 * i])
				return (0);
		}
		i++;
	}
	return (1);
}
