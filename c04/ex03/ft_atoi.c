/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:01:33 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/09 17:19:38 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_remove_isspace_nbr(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	return (str);
}

int	ft_atoi(char *str)
{
	int	index;
	int	result;
	int	sign;

	index = 0;
	result = 0;
	sign = 1;
	str = ft_remove_isspace_nbr(str);
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		if (result == 214748364 && str[index] == '8' && sign == -1)
			return (-2147483648);
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result * sign);
}
