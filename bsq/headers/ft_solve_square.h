/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_square.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 03:19:08 by vfries            #+#    #+#             */
/*   Updated: 2022/08/23 03:19:09 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLVE_SQUARE_H
# define FT_SOLVE_SQUARE_H

# include <unistd.h>
# include "ft_bool.h"
# include "ft_t_square.h"
# include "ft_parsing.h"

t_bool	ft_test_square(t_map_data *map, t_square *square);
t_bool	ft_get_biggest_square(t_map_data *map, t_square *square);
void	ft_add_square_to_map(t_map_data *map, t_square *square);
void	ft_print_map(t_map_data *map);
t_bool	ft_solve_square(t_map_data *map);

#endif
