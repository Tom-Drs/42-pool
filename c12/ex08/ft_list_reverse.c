/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:17:47 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/25 19:28:39 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current_link;
	t_list	*previous_link;
	t_list	*next_link;

	current_link = *begin_list;
	previous_link = NULL;
	while (current_link != NULL)
	{
		next_link = current_link->next;
		current_link->next = previous_link;
		previous_link = current_link;
		current_link = next_link;
	}
	*begin_list = previous_link;
}
