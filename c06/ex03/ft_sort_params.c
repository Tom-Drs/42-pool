/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:06:29 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/16 22:50:58 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_print_params(int argc, char **argv)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		ft_putstr(argv[index]);
		ft_putchar('\n');
		index++;
	}
}

int	main(int argc, char *argv[])
{
	int		index;
	int		min_index;
	char	*temp;

	index = 2;
	if (argc == 1)
		return (0);
	while (index < argc)
	{
		min_index = index;
		while (ft_strcmp(argv[index], argv[min_index - 1]) < 0
			&& min_index > 1)
			min_index--;
		while (min_index < index)
		{
			temp = argv[min_index];
			argv[min_index] = argv[index];
			argv[index] = temp;
			min_index++;
		}
		index++;
	}
	ft_print_params(argc, argv);
}
