/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:25:10 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/21 22:03:13 by bboisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <stdlib.h>

int	ft_is_printable(int c)
{
	if (c < ' ' || c > 126)
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

int	ft_is_isspace(char c)
{
	return (c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

char	*ft_strdup_index(char *str, int index_start, int index_stop)
{
	char	*strdup;
	int		index;

	index = 0;
	strdup = malloc(sizeof(char) * (index_stop - index_start + 1));
	if (strdup == NULL)
		return (NULL);
	while (index_start < index_stop)
		strdup[index++] = str[index_start++];
	strdup[index] = '\0';
	return (strdup);
}
