/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:07:26 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/17 19:09:40 by tdameros         ###   ########lyon.fr   */
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

void	ft_strcat(char *dest, char *src)
{
	int	index_dest;
	int	index_src;

	index_dest = 0;
	index_src = 0;
	while (dest[index_dest] != '\0')
		index_dest++;
	while (src[index_src] != '\0')
	{
		dest[index_dest] = src[index_src];
		index_dest++;
		index_src++;
	}
	dest[index_dest] = '\0';
}

int	ft_get_total_len(int size, char **strs, char *sep)
{
	int		total_len;
	int		index;

	index = 0;
	total_len = ft_strlen(sep) * (size - 1);
	while (index < size)
	{		
		total_len += ft_strlen(strs[index]);
		index++;
	}
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*str;
	int		index;

	index = 0;
	if (size == 0)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	total_len = ft_get_total_len(size, strs, sep);
	str = malloc(sizeof(char) * (total_len + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	while (index < size)
	{
		ft_strcat(str, strs[index]);
		index++;
		if (index < size)
			ft_strcat(str, sep);
	}
	return (str);
}
