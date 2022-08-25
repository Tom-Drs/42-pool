/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:30:56 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/17 16:13:16 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_charset(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index] != '\0')
	{
		if (charset[index] == c)
			return (1);
		index++;
	}
	return (0);
}

int	ft_count_split(char *str, char *charset)
{
	int	start;
	int	index;
	int	count;

	start = 0;
	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (!start && !ft_is_in_charset(str[index], charset))
		{
			count++;
			start = 1;
		}
		if (start && ft_is_in_charset(str[index], charset))
			start = 0;
		index++;
	}
	return (count);
}

int	ft_next_charset(char *str, int index, char *charset)
{
	while (str[index] != '\0' && !ft_is_in_charset(str[index], charset))
		index++;
	return (index);
}

char	*ft_strdup(char *str, int index_start, int index_stop)
{
	char	*str_dup;
	int		index_dup;

	index_dup = 0;
	str_dup = malloc(sizeof(char *) * (index_stop - index_start + 1));
	if (str_dup == NULL)
		return (NULL);
	while (index_start < index_stop)
		str_dup[index_dup++] = str[index_start++];
	str_dup[index_dup] = '\0';
	return (str_dup);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	int		index_tab;
	int		index;
	int		index_next_charset;
	char	**tab;

	index = 0;
	index_tab = 0;
	size = ft_count_split(str, charset);
	tab = malloc(sizeof(char *) * (size + 1));
	if (tab == NULL)
		return (NULL);
	while (index_tab < size)
	{
		while (ft_is_in_charset(str[index], charset))
			index++;
		index_next_charset = ft_next_charset(str, index, charset);
		tab[index_tab++] = ft_strdup(str, index, index_next_charset);
		index = index_next_charset;
	}
	tab[index_tab] = 0;
	return (tab);
}
