/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:20:32 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/04 18:21:02 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	left_index;
	int	right_index;
	int	temp;

	left_index = 0;
	right_index = size - 1;
	while (left_index < right_index)
	{
		temp = tab[left_index];
		tab[left_index] = tab[right_index];
		tab[right_index] = temp;
		left_index++;
		right_index--;
	}
}
