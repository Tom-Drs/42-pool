/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:23:07 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/23 01:37:06 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	ret;
	int	result;

	ret = 0;
	index = 0;
	result = 0;
	while (index < length - 1)
	{
		result = f(tab[index], tab[index + 1]);
		if (result > 0 && ret < 0)
			return (0);
		else if (result < 0 && ret > 0)
			return (0);
		if (ret == 0)
			ret = result;
		index++;
	}
	return (1);
}
