/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:52:47 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/17 23:55:19 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

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
	int		index;
	int		len;
	char	*str_dup;

	index = 0;
	len = ft_strlen(src);
	str_dup = malloc(sizeof(char) * (len + 1));
	if (str_dup == NULL)
		return (NULL);
	while (src[index] != '\0')
	{
		str_dup[index] = src[index];
		index++;
	}
	str_dup[index] = '\0';
	return (str_dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					index;

	index = 0;
	tab = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	while (index < ac)
	{
		tab[index].str = av[index];
		tab[index].copy = ft_strdup(av[index]);
		tab[index].size = ft_strlen(av[index]);
		index++;
	}
	tab[index].str = 0;
	return (tab);
}
