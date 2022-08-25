/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:11:30 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/23 01:13:45 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*tab_map;
	int	index;

	index = 0;
	tab_map = malloc(sizeof(int) * length);
	while (index < length)
	{
		tab_map[index] = f(tab[index]);
		index++;
	}
	return (tab_map);
}
