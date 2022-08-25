/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:01:15 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/24 17:19:58 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_parsing.h"

int	ft_free_bool(char *str)
{
	free(str);
	return (1);
}

int	ft_free_negative(char *str)
{
	free(str);
	return (-1);
}

char	*ft_free_char(char *str)
{
	free(str);
	return (NULL);
}

void	ft_free_map_data(t_map_data *map_data)
{
	int	index;

	index = 0;
	while (index < map_data->y)
		free((map_data->map)[index++]);
	free(map_data->map);
	free(map_data);
}
