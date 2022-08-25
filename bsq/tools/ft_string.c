/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:19:33 by vfries            #+#    #+#             */
/*   Updated: 2022/08/24 17:21:45 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_is_printable(int c)
{
	if (c < 32 || c > 126)
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

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
