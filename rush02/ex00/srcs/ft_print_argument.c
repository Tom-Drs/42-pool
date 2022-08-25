/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:42:34 by bboisson          #+#    #+#             */
/*   Updated: 2022/08/21 20:55:47 by bboisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <unistd.h>

void	ft_handle_hundreds(char *arg, int size, t_dict **dict, int *i)
{
	if (arg[*i] >= '1')
	{
		ft_print(ft_search_unity(arg[*i], 1, dict), *i, arg, 1);
		if ((size - *i) >= 4)
			ft_print(ft_search_unity('1', 3, dict), *i, arg, 1);
		else
			ft_print(ft_search_unity('1', 3, dict), *i, arg, 0);
	}
	if (arg[*i + 1] == '0')
		*i += 1;
	*i += 1;
}

void	ft_handle_tens_combine(char *arg, int size, t_dict **dict, int *i)
{
	char	nbr[3];

	nbr[0] = arg[*i];
	nbr[1] = arg[*i + 1];
	nbr[2] = '\0';
	if (size - (*i + 1) >= 4)
	{
		ft_print(ft_search_number(nbr, dict), *i + 1, arg, 1);
		ft_print(ft_search_unity('1', size - *i - 1, dict), *i + 1, arg, 0);
	}
	else
		ft_print(ft_search_number(nbr, dict), *i + 1, arg, 0);
	*i += 2;
}

void	ft_handle_tens_normal(char *arg, int size, t_dict **dict, int *i)
{
	if (arg[*i] >= '2' && (size - *i) >= 4)
		ft_print(ft_search_unity(arg[*i], 2, dict), *i, arg, 1);
	else if (arg[*i] >= '2')
		ft_print(ft_search_unity(arg[*i], 2, dict), *i, arg, 0);
	*i += 1;
}

void	ft_handle_unities(char *arg, int size, t_dict **dict, int *i)
{
	if ((size - *i) >= 4 && (arg[*i] > '0' || (((*i >= 2)
					&& (arg[*i - 2] > '0' || arg[*i - 1] > '0'))
				|| ((*i >= 1) && arg[*i - 1] > '0'))))
	{
		if (arg[*i] >= '1')
			ft_print(ft_search_unity(arg[*i], 1, dict), *i, arg, 1);
		ft_print(ft_search_unity('1', size - *i, dict), *i, arg, 0);
	}
	else if (arg[*i] >= '1')
		ft_print(ft_search_unity(arg[*i], 1, dict), *i, arg, 0);
	*i += 1;
}

void	ft_print_argument(char *arg, int size, t_dict **dict)
{
	int	i;

	i = 0;
	if (ft_only_zero(arg, dict))
		return ;
	while ((arg[i] && ft_keep_printing(i, arg)) || (size == 1 && arg[i] == '0'))
	{
		if ((size - i) % 3 == 0)
			ft_handle_hundreds(arg, size, dict, &i);
		if ((size - i) % 3 == 2 && arg[i] == '1')
			ft_handle_tens_combine(arg, size, dict, &i);
		if ((size - i) % 3 == 2 && ((arg[i] >= '2' && arg[i] <= '9')
				|| arg[i] == '0'))
			ft_handle_tens_normal(arg, size, dict, &i);
		if ((size - i) % 3 == 1)
			ft_handle_unities(arg, size, dict, &i);
	}
	write(1, "\n", 1);
}
