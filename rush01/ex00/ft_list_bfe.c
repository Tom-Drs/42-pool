/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bfe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salesnof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:08:59 by salesnof          #+#    #+#             */
/*   Updated: 2022/08/14 16:10:55 by salesnof         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_two_one(int nb, char *tab)
{
	if (nb == 1)
		ft_fill_tab(tab, "3214");
	else if (nb == 2)
		ft_fill_tab(tab, "3124");
	return (tab);
}

char	*ft_one_four(int nb, char *tab)
{
	if (nb == 1)
		ft_fill_tab(tab, "4321");
	return (tab);
}

char	*ft_one_three(int nb, char *tab)
{
	if (nb == 1)
		ft_fill_tab(tab, "4231");
	else if (nb == 2)
		ft_fill_tab(tab, "4132");
	else if (nb == 3)
		ft_fill_tab(tab, "4312");
	return (tab);
}

char	*ft_one_two(int nb, char *tab)
{
	if (nb == 1)
		ft_fill_tab(tab, "4123");
	else if (nb == 2)
		ft_fill_tab(tab, "4213");
	return (tab);
}
