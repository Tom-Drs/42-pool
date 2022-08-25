/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:54:13 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/14 23:22:32 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	struct s_grid	grid;
	int				val;

	val = 0;
	if (argc != 2)
		return (ft_error());
	grid.val = ft_parse(argv[1]);
	grid.tab = NULL;
	if (grid.val != NULL)
	{
		grid.tab = ft_tab_init(grid.tab);
		if (grid.tab == NULL)
			return (ft_error());
		val = ft_backtracking(grid, 0, 1, val);
		if (val == 0 || val == -1)
			return (ft_error());
	}
	else
		return (ft_error());
	return (0);
}
