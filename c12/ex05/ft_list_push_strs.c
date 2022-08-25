/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 02:37:31 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/25 03:02:07 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data);

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*first_link;
	t_list	*new_link;
	int		index;

	index = 0;
	if (size <= 0)
		return (NULL);
	first_link = ft_create_elem(strs[index++]);
	while (index < size)
	{
		new_link = ft_create_elem(strs[index++]);
		new_link->next = first_link;
		first_link = new_link;
	}
	return (first_link);
}
