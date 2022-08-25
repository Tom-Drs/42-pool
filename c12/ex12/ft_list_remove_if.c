/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:22:44 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/25 19:17:59 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if_first(t_list **begin_list,
		void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current_link;
	t_list	*temp;

	current_link = *begin_list;
	while (current_link != NULL && !(*cmp)(current_link->data, data_ref))
	{
		temp = current_link;
		current_link = current_link->next;
		free_fct(temp->data);
		free(temp);
	}
	*begin_list = current_link;
}

void	ft_list_remove_if(t_list **begin_list,
		void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*previous_link;
	t_list	*current_link;
	t_list	*temp;

	ft_list_remove_if_first(begin_list, data_ref, cmp, free_fct);
	previous_link = *begin_list;
	current_link = (*begin_list)->next;
	while (current_link != NULL)
	{
		if (!(*cmp)(current_link->data, data_ref))
		{
			temp = current_link;
			previous_link->next = current_link->next;
			current_link = previous_link->next;
			free_fct(temp->data);
			free(temp);
		}
		else
		{
			previous_link = current_link;
			current_link = current_link->next;
		}
	}
}
