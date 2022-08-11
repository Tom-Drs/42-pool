/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:12:14 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/08 18:22:57 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_length(char *str)
{
	char	*first_ptr;

	first_ptr = str;
	while (*str != '\0')
		str++;
	return (str - first_ptr);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	haystack_length;
	int	needle_length;
	int	index;
	int	index_temp;

	haystack_length = ft_str_length(str);
	needle_length = ft_str_length(to_find);
	index = 0;
	if (needle_length == 0)
		return (str);
	if (haystack_length == 0)
		return (NULL);
	while (index + needle_length <= haystack_length && str[index] != '\0')
	{
		index_temp = index;
		while (str[index_temp] == to_find[index_temp - index])
		{
			if (index_temp - index + 1 == needle_length)
				return (&str[index]);
			index_temp++;
		}
		index++;
	}
	return (NULL);
}
