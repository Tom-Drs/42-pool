/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:18:26 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/04 23:39:27 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	calculate(int *digit, int *nb, int *divisor)
{
	*digit = *nb / *divisor;
	*nb -= (*nb / *divisor) * *divisor;
	*divisor /= 10;
}

void	is_negative(int *nb)
{
	if (*nb < 0)
	{
		*nb = *nb * -1;
		ft_putchar('-');
	}
}	

void	ft_putnbr(int nb)
{
	int	start;
	int	divisor;
	int	digit;

	start = 0;
	divisor = 1000000000;
	digit = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	is_negative(&nb);
	while (divisor != 1)
	{
		calculate(&digit, &nb, &divisor);
		if (!start && digit != 0)
			start = 1;
		if (start)
			ft_putchar(digit + 48);
	}
	ft_putchar(nb + 48);
}
