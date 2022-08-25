/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:19:46 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/23 06:26:51 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	index;
	int	count_if;

	index = 0;
	count_if = 0;
	while (index < length)
		if (f(tab[index++]))
			count_if++;
	return (count_if);
}
