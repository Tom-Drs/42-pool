/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:28:02 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/04 23:36:06 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fill_array(int *array, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		array[index] = index;
		index++;
	}
	while (index < 9)
	{
		array[index++] = 42;
	}
}

void	ft_display_comb(int *array)
{
	int		index;
	char	digit;

	index = 0;
	while (index < 9)
	{
		if (array[index] != 42)
		{
			digit = array[index] + 48;
			write(1, &digit, 1);
		}
		index++;
	}
}

void	ft_update(int *array, int n)
{
	int	index;
	int	value;

	index = n - 1;
	value = 10;
	while (array[index] == value - 1)
	{
		value = array[index];
		index--;
	}
	array[index]++;
	index++;
	while (array[index] != 42 && index < 9)
	{
		array[index] = array[index - 1] + 1;
		index++;
	}	
}

void	ft_print_combn(int n)
{
	int	array[9];

	fill_array(array, n);
	while (!(array[0] == 10 - n))
	{
		ft_display_comb(array);
		write(1, ", ", 2);
		ft_update(array, n);
	}
	ft_display_comb(array);
}
