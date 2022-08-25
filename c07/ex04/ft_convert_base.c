/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:45:50 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/17 21:10:04 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_is_valid_base(char *base);
int	ft_strlen(char *str);

int	ft_get_size(long long nbr, int base_len)
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

char	*ft_itoa_base(long long nb, char *base, int base_len)
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	base_ten_convert;
	char		*result;
	int			base_to_len;

	if (!ft_is_valid_base(base_from) || !ft_is_valid_base(base_to))
		return (NULL);
	base_ten_convert = ft_atoi_base(nbr, base_from);
	base_to_len = ft_strlen(base_to);
	result = ft_itoa_base(base_ten_convert, base_to, base_to_len);
	return (result);
}
