/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_square2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:54:27 by vfries            #+#    #+#             */
/*   Updated: 2022/08/22 22:54:28 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve_square.h"

t_bool	ft_test_square(t_map_data *map, t_square *square)
{
	int	y;
	int	x;
	int	max_y;
	int	max_x;

	max_y = square->y + square->size;
	max_x = square->x + square->size;
	if (max_y > map->y || max_x > map->x)
		return (FALSE);
	y = square->y;
	while (y < max_y)
	{
		x = square->x;
		while (x < max_x)
		{
			if (map->map[y][x] == map->obstacle_char)
			{
				square->x = x;
				return (FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

void	ft_find_square(t_map_data *map, t_square *square)
{
	t_bool	square_found;

	square_found = FALSE;
	while (map->y > map->y - square->size && square->y <= map->y - square->size)
	{
		square_found = FALSE;
		square->x = 0;
		while (map->x > map->x - square->size
			&& square->x <= map->x - square->size)
		{
			if (ft_test_square(map, square))
			{
				square->y_biggest = square->y;
				square->x_biggest = square->x;
				square->size++;
				square->y = 0;
				square_found = TRUE;
				break ;
			}
			square->x++;
		}
		if (square_found == FALSE)
			square->y++;
	}
}

void	ft_add_square_to_map(t_map_data *map, t_square *square)
{
	int	y;
	int	max_y;
	int	x;
	int	max_x;

	max_y = square->y_biggest + square->size - 1;
	max_x = square->x_biggest + square->size - 1;
	y = square->y_biggest;
	while (y < max_y)
	{
		x = square->x_biggest;
		while (x < max_x)
			map->map[y][x++] = map->filled_char;
		y++;
	}
}

void	ft_print_map(t_map_data *map)
{
	int	y;

	y = 0;
	while (y < map->y)
	{
		write(1, map->map[y++], map->x);
		write(1, "\n", 1);
	}
}

t_bool	ft_solve_square(t_map_data *map)
{
	t_square	square;

	square.y = 0;
	square.x = 0;
	square.size = 1;
	square.x_biggest = 0;
	square.y_biggest = 0;
	ft_find_square(map, &square);
	if (square.x_biggest == 0 && square.y_biggest == 0 && square.size == 0
		&& map->map[0][0] == map->obstacle_char)
		return (FALSE);
	ft_add_square_to_map(map, &square);
	ft_print_map(map);
	return (TRUE);
}
