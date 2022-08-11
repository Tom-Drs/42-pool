/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:33:37 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/06 13:15:53 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	index;
	int	index_temp;
	int	temp;

	index = 1;
	if (size <= 1)
		return ;
	while (index != size)
	{
		index_temp = index;
		while (tab[index] < tab[index_temp - 1] && index_temp != 0)
			index_temp--;
		while (index_temp != index)
		{
			temp = tab[index_temp];
			tab[index_temp] = tab[index];
			tab[index] = temp;
			index_temp++;
		}
		index++;
	}
}
