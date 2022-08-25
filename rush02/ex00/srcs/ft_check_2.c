/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:03:24 by bboisson          #+#    #+#             */
/*   Updated: 2022/08/21 13:33:30 by bboisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_init_others(char **keys)
{
	int	i;
	int	j;
	int	nbr;
	int	size;

	i = 29;
	nbr = '1';
	size = 4;
	while (i < 41)
	{
		j = 0;
		keys[i] = malloc(sizeof(char) * (size) + 1);
		keys[i][j++] = nbr;
		while (j < size)
			keys[i][j++] = '0';
		keys[i][j] = '\0';
		size = (size + 3);
		i++;
	}
}

void	ft_init_hundred(char **keys)
{
	int	i;
	int	j;

	i = 28;
	keys[i] = malloc(sizeof(char) * 3 + 1);
	j = 0;
	keys[i][j++] = '1';
	while (j < 3)
		keys[i][j++] = '0';
	keys[i][j] = '\0';
}

void	ft_init_cent(char **keys)
{
	int	i;
	int	j;
	int	nbr;

	i = 20;
	nbr = '2';
	while (i < 28)
	{
		j = 0;
		keys[i] = malloc(sizeof(char) * 2 + 1);
		keys[i][j] = nbr;
		j++;
		keys[i][j] = '0';
		j++;
		keys[i][j] = '\0';
		nbr++;
		i++;
	}
}

void	ft_init_ten(char **keys)
{
	int	i;
	int	j;
	int	nbr;

	i = 10;
	nbr = '0';
	while (i < 20)
	{
		j = 0;
		keys[i] = malloc(sizeof(char) * 2 + 1);
		keys[i][j] = '1';
		j++;
		keys[i][j] = nbr;
		j++;
		keys[i][j] = '\0';
		nbr++;
		i++;
	}
}

void	ft_init_nine(char **keys)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	nbr = '0';
	while (i < 10)
	{
		j = 0;
		keys[i] = malloc(sizeof(char) * 1 + 1);
		keys[i][j] = nbr;
		j++;
		keys[i][j] = '\0';
		nbr++;
		i++;
	}
}
