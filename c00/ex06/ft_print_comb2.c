/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:40:46 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/04 12:08:01 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_number(char number)
{
	if (number < 10)
	{
		ft_putchar('0');
		ft_putchar(number + 48);
	}
	else
	{
		ft_putchar((number / 10) + 48);
		ft_putchar((number % 10) + 48);
	}
}

void	display_numbers(char number1, char number2)
{
	display_number(number1);
	ft_putchar(' ');
	display_number(number2);
}

void	ft_print_comb2(void)
{
	char	first_number;
	char	second_number;

	first_number = 0;
	second_number = 1;
	while (first_number <= 98)
	{
		while (second_number <= 99)
		{
			if (first_number == 98 && second_number == 99)
				display_numbers(first_number, second_number);
			else
			{
				display_numbers(first_number, second_number);
				ft_putchar(',');
				ft_putchar(' ');
			}
			if (second_number == 99)
			{
				first_number++;
				second_number = first_number;
			}	
			second_number++;
		}
	}
}
