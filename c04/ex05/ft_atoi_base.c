/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:39:58 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/09 23:28:19 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_remove_isspace_nbr(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	return (str);
}

int	ft_strlen(char *str)
{
	char	*first_ptr;

	first_ptr = str;
	while (*str != '\0')
		str++;
	return (str - first_ptr);
}

int	ft_is_valid_base(char *base)
{
	int	index;
	int	index_temp;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-'
			|| (base[index] >= 9 && base[index] <= 13) || base[index] == ' ')
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

int	ft_char_is_in_base(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	index;
	int	result;
	int	sign;
	int	base_len;

	index = 0;
	result = 0;
	sign = 1;
	base_len = ft_strlen(base);
	str = ft_remove_isspace_nbr(str);
	if (!(ft_is_valid_base(base)))
		return (0);
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (ft_char_is_in_base(str[index], base) != -1)
	{
		result = result * base_len + ft_char_is_in_base(str[index], base);
		index++;
	}
	return (result * sign);
}
