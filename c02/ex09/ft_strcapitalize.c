/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:55:13 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/06 19:28:07 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_char_is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_char_is_alpha_or_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (ft_char_is_lower(c) || ft_char_is_upper(c));
}

char	*ft_strcapitalize(char	*str)
{
	int	index;

	index = 0;
	if (ft_char_is_lower(str[index]))
		str[index] -= 32;
	while (str[index] != '\0')
	{
		index++;
		if (ft_char_is_alpha_or_num(str[index - 1]))
		{
			if (ft_char_is_upper(str[index]))
				str[index] += 32;
		}
		else if (ft_char_is_lower(str[index]))
			str[index] -= 32;
	}
	return (str);
}
