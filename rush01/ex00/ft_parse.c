/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:16:51 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/14 23:08:09 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_is_valid(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (index % 2 == 0 && !(str[index] >= '0' && str[index] <= '9'))
			return (0);
		else if (index % 2 == 1 && str[index] != ' ')
			return (0);
		index++;
	}
	if (index != 31)
	{
		return (0);
	}
	return (1);
}

int	*ft_parse(char *str)
{
	int	*tab;
	int	index_str;
	int	index_tab;

	index_str = 0;
	index_tab = 0;
	if (!ft_is_valid(str))
	{
		tab = NULL;
		return (tab);
	}	
	tab = malloc(sizeof(int) * 16);
	if (tab == NULL)
		return (NULL);
	while (str[index_str] != '\0')
	{
		if (index_str % 2 == 0)
		{
			tab[index_tab] = str[index_str] - '0';
			index_tab++;
		}
		index_str++;
	}	
	return (tab);
}
