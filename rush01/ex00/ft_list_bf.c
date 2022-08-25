/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salesnof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:48:57 by salesnof          #+#    #+#             */
/*   Updated: 2022/08/14 16:10:34 by salesnof         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_four_one(int nb, char *tab)
{
	if (nb == 1)
		ft_fill_tab(tab, "1234");
	return (tab);
}

char	*ft_three_two(int nb, char *tab)
{
	if (nb == 1)
		ft_fill_tab(tab, "1243");
	else if (nb == 2)
		ft_fill_tab(tab, "1342");
	else if (nb == 3)
		ft_fill_tab(tab, "2341");
	return (tab);
}

char	*ft_three_one(int nb, char *tab)
{
	if (nb == 1)
		ft_fill_tab(tab, "1324");
	else if (nb == 2)
		ft_fill_tab(tab, "2314");
	else if (nb == 3)
		ft_fill_tab(tab, "2134");
	return (tab);
}

char	*ft_two_three(int nb, char *tab)
{
	if (nb == 1)
		ft_fill_tab(tab, "3421");
	else if (nb == 2)
		ft_fill_tab(tab, "2431");
	else if (nb == 3)
		ft_fill_tab(tab, "1432");
	return (tab);
}

char	*ft_two_two(int nb, char *tab)
{
	if (nb == 1)
		ft_fill_tab(tab, "2143");
	else if (nb == 2)
		ft_fill_tab(tab, "3142");
	else if (nb == 3)
		ft_fill_tab(tab, "3241");
	else if (nb == 4)
		ft_fill_tab(tab, "3412");
	else if (nb == 5)
		ft_fill_tab(tab, "2413");
	else if (nb == 6)
		ft_fill_tab(tab, "1423");
	return (tab);
}
