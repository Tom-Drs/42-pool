/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:31:44 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/11 11:45:36 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_valid_base(char *base)
{
	int	index;
	int	index_temp;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		index_temp = 0;
		while (index_temp < index)
		{
			if (base[index] == base[index_temp])
				return (0);
			index_temp++;
		}
		index++;
	}
	return (index >= 2);
}

int	ft_strlen(char *str)
{
	char	*first_ptr;

	first_ptr = str;
	while (*str != '\0')
		str++;
	return (str - first_ptr);
}

void	ft_putnbr_base2(long nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base2(-nbr, base);
	}
	else if (nbr < base_len)
		ft_putchar(base[nbr % base_len]);
	else
	{
		ft_putnbr_base2(nbr / base_len, base);
		ft_putchar(base[nbr % base_len]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	nbr_temp;

	nbr_temp = nbr;
	base_len = ft_strlen(base);
	if (!(ft_is_valid_base(base)))
		return ;
	ft_putnbr_base2(nbr, base);
}
