/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:18:14 by vfries            #+#    #+#             */
/*   Updated: 2022/08/24 18:39:25 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve_square.h"
#include "ft_string.h"
#include "ft_parsing.h"

//TODO include header with t_map_data

int	ft_run_stdin(t_map_data *map)
{
	map = ft_parse("", 0);
	if (map == NULL)
	{
		ft_putstr("map error\n");
		return (1);
	}
	ft_solve_square(map);
	ft_free_map_data(map);
	return (0);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_map_data	*map;

	map = NULL;
	if (argc < 2)
		return (ft_run_stdin(map));
	i = 1;
	while (i < argc)
	{
		map = ft_parse(argv[i], 1);
		if (map == NULL)
		{
			ft_putstr("map error\n");
			return (1);
		}
		ft_solve_square(map);
		ft_free_map_data(map);
		i++;
	}
}
