/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:39:24 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/08 17:27:04 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(int c)
{
	if (c < ' ' || c > 126)
		return (0);
	return (1);
}

void	ft_print_hexa_convert(int c)
{
	write(1, "\\", 1);
	ft_putchar("0123456789abcdef"[c / 16]);
	ft_putchar("0123456789abcdef"[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (!(ft_is_printable(str[index])))
			ft_print_hexa_convert(str[index]);
		else
			ft_putchar(str[index]);
		index++;
	}
}
