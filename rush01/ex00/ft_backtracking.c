/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salesnof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:05:13 by salesnof          #+#    #+#             */
/*   Updated: 2022/08/14 23:30:27 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_put_in_tab(char *tab, char *new, int pos)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (pos % 2 == 0)
			tab[(pos / 2) * 4 + i] = new[i];
		if (pos % 2 == 1)
			tab[(pos / 2) + 4 * i] = new[i];
		i++;
	}
	free(new);
}

int	ft_next_backtracking(struct s_grid grid, int pos, int comb, int val)
{
	char	*new;

	if (pos % 2 == 0)
		new = ft_case(grid.val[pos / 2 + 8], grid.val[pos / 2 + 12], comb);
	if (pos % 2 == 1)
		new = ft_case(grid.val[pos / 2], grid.val[pos / 2 + 4], comb);
	ft_put_in_tab(grid.tab, new, pos);
	val = ft_backtracking(grid, pos + 1, 1, val);
	if (val == 1)
		return (val);
	if (val == -1)
		return (-1);
	if (ft_comeback(grid.tab) == -1)
		return (-1);
	if (val)
		return (val);
	return (val);
}

void	ft_put(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		write(1, &tab[i], 1);
		if (i % 4 != 3)
			ft_putchar(' ');
		if (i % 4 == 3 && i != 15)
			ft_putchar('\n');
		i++;
	}
}

int	ft_backtracking(struct s_grid grid, int pos, int comb, int val)
{
	int	view_1;
	int	view_2;

	view_1 = grid.val[((pos + 1) % 2) * 8 + pos / 2];
	view_2 = grid.val[((pos + 1) % 2) * 8 + 4 + pos / 2];
	if (val == -1)
		return (-1);
	if (val || (pos == 0 && ft_case(grid.val[8], grid.val[12], comb)[0] == '0'))
		return (val);
	if (ft_is_finish(grid, pos))
		return (1);
	if (pos == 0 || ft_check(grid.tab, ft_case(view_1, view_2, comb), pos))
	{
		val = ft_next_backtracking(grid, pos, comb, val);
		if (val == -1)
			return (-1);
	}
	else if (ft_case(view_1, view_2, comb)[0] == '0')
		return (val);
	if (val)
		return (val);
	val = ft_backtracking(grid, pos, comb + 1, val);
	return (val);
}
