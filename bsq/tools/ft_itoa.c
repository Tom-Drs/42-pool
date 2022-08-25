/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:58:16 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/22 16:25:27 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_get_size(int nbr, int base_len)
{
	int	size;

	size = 0;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr < base_len)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_len;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(int nb, char *base, int base_len)
{
	int		size;
	int		sign;
	char	*result;

	size = ft_get_size(nb, base_len);
	if (nb < 0)
	{
		sign = -1;
		nb = -nb;
		size++;
	}
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	result[size] = '\0';
	while (nb / base_len != 0)
	{
		result[--size] = base[nb % base_len];
		nb /= base_len;
	}
	result[--size] = base[nb % base_len];
	if (sign == -1)
		result[--size] = '-';
	return (result);
}
