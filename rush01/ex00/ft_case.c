/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salesnof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:07:17 by salesnof          #+#    #+#             */
/*   Updated: 2022/08/14 23:28:08 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_fill_tab(char *tab, char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		tab[index] = str[index];
		index++;
	}
}

char	*ft_case(int n_one, int n_two, int nb)
{
	char	*tab;

	tab = (char *)malloc(sizeof(char) * 5);
	ft_fill_tab(tab, "0000");
	if (n_one == 4 && n_two == 1)
		ft_four_one(nb, tab);
	else if (n_one == 3 && n_two == 2)
		ft_three_two(nb, tab);
	else if (n_one == 3 && n_two == 1)
		ft_three_one(nb, tab);
	else if (n_one == 2 && n_two == 3)
		ft_two_three(nb, tab);
	else if (n_one == 2 && n_two == 2)
		ft_two_two(nb, tab);
	else if (n_one == 2 && n_two == 1)
		ft_two_one(nb, tab);
	else if (n_one == 1 && n_two == 4)
		ft_one_four(nb, tab);
	else if (n_one == 1 && n_two == 3)
		ft_one_three(nb, tab);
	else if (n_one == 1 && n_two == 2)
		ft_one_two(nb, tab);
	return (tab);
}

char	*ft_tab_init(char *tab)
{
	int	i;

	i = 0;
	tab = (char *)malloc(sizeof(char) * 17);
	if (tab == NULL)
		return (NULL);
	while (i < 16)
	{
		tab[i] = '0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
