/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 02:29:08 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/25 03:01:39 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*link;

	link = *begin_list;
	if (link == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		while (link->next != NULL)
			link = link->next;
		link->next = ft_create_elem(data);
	}
}
