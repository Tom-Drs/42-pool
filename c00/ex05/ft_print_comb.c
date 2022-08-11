/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:51:48 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/04 12:05:03 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_number(char hundred, char ten, char unit)
{
	ft_putchar(hundred + 48);
	ft_putchar(ten + 48);
	ft_putchar(unit + 48);
}

void	change_digits(char *hundred, char *ten, char *unit)
{	
	*ten += 1;
	if (*ten == 9)
	{
		*hundred = *hundred + 1;
		*ten = *hundred + 1;
		*unit = *ten + 1;
	}
	else
		*unit = *ten + 1;
}

void	ft_print_comb(void)
{
	char	unit;
	char	ten;
	char	hundred;	

	unit = 2;
	ten = 1;
	hundred = 0;
	while (!(unit == 9 && ten == 8 && hundred == 7))
	{
		display_number(hundred, ten, unit);
		write(1, ", ", 2);
		if (unit == 9)
			change_digits(&hundred, &ten, &unit);
		else
			unit++;
	}
	display_number(hundred, ten, unit);
}
