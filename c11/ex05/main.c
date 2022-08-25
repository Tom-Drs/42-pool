/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:50:39 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/23 06:25:48 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_mod(int a, int b);
void	ft_mult(int a, int b);
void	ft_div(int a, int b);
void	ft_substraction(int a, int b);
void	ft_add(int a, int b);
int		ft_atoi(char *str);

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index++);
}

void	ft_tab_op(char *tab_op)
{
	tab_op[0] = '%';
	tab_op[1] = '*';
	tab_op[2] = '/';
	tab_op[3] = '-';
	tab_op[4] = '+';
}

int	main(int argc, char **argv)
{
	void	(*tab_func[5])(int, int);
	char	tab_op[5];
	int		index;

	tab_func[0] = &ft_mod;
	tab_func[1] = &ft_mult;
	tab_func[2] = &ft_div;
	tab_func[3] = &ft_substraction;
	tab_func[4] = &ft_add;
	ft_tab_op(tab_op);
	index = 0;
	if (argc != 4)
		return (1);
	while (index < 5)
	{
		if (tab_op[index] == *argv[2] && ft_strlen(argv[2]) == 1)
		{
			tab_func[index](ft_atoi(argv[1]), ft_atoi(argv[3]));
			return (0);
		}
		index++;
	}
	write(1, "0\n", 2);
}
