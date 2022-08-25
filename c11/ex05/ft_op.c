/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:54:15 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/23 03:59:32 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putstr(char *str);

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
	ft_putstr("\n");
}

void	ft_substraction(int a, int b)
{
	ft_putnbr(a - b);
	ft_putstr("\n");
}

void	ft_div(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
	ft_putstr("\n");
}

void	ft_mult(int a, int b)
{
	ft_putnbr(a * b);
	ft_putstr("\n");
}

void	ft_mod(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
	ft_putstr("\n");
}
