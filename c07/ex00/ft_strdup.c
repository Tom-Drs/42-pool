/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:45:28 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/17 15:10:39 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strdup(char *src)
{
	char	*str_dup;
	int		index;
	int		len;

	len = ft_strlen(src);
	str_dup = malloc(len + 1);
	if (str_dup == NULL)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		str_dup[index] = src[index];
		index++;
	}
	str_dup[index] = '\0';
	return (str_dup);
}
