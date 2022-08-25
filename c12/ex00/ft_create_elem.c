/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 01:41:52 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/25 02:13:39 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*link;

	link = malloc(sizeof(t_list));
	if (link == NULL)
		return (NULL);
	link->data = data;
	link->next = NULL;
	return (link);
}
