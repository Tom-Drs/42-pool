/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:04:04 by hdupuy            #+#    #+#             */
/*   Updated: 2022/08/21 21:15:41 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <unistd.h>

void	ft_run(char *dict_used, char *nbr)
{
	t_dict	**dict;

	if (!ft_check_int(nbr))
		return ;
	dict = ft_parse(dict_used, 0, 0);
	if (dict == NULL)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	if (!ft_check_table_init(dict))
	{
		ft_free_dict(dict);
		return ;
	}
	if (!ft_dictionnary_limit(dict, ft_strlen_jump_zero(nbr), 37))
	{
		ft_free_dict(dict);
		return ;
	}
	ft_sort_dict(dict);
	ft_print_argument(nbr, ft_strlen(nbr), dict);
	ft_free_dict(dict);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_run("numbers.dict", argv[1]);
	else if (argc == 3)
		ft_run(argv[1], argv[2]);
	else
		write(1, "Error\n", 6);
	return (0);
}
