/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salesnof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:07:02 by salesnof          #+#    #+#             */
/*   Updated: 2022/08/14 23:27:44 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

struct	s_grid
{
	int		*val;
	char	*tab;
};
void	ft_putchar(char c);
void	ft_fill_tab(char *tab, char *str);
char	*ft_case(int n_one, int n_two, int nb);
char	*ft_tab_init(char *tab);
char	*ft_four_one(int nb, char *tab);
char	*ft_three_two(int nb, char *tab);
char	*ft_three_one(int nb, char *tab);
char	*ft_two_three(int nb, char *tab);
char	*ft_two_two(int nb, char *tab);
char	*ft_two_one(int nb, char *tab);
char	*ft_one_four(int nb, char *tab);
char	*ft_one_three(int nb, char *tab);
char	*ft_one_two(int nb, char *tab);
int		ft_is_valid(char *str);
int		*ft_parse(char *str);
int		ft_check(char *tab, char *new, int pos);
void	ft_put_in_tab(char *tab, char *new, int pos);
int		ft_next_backtracking(struct s_grid grid, int pos, int comb, int val);
void	ft_put(char *tab);
int		ft_is_finish(struct s_grid grid, int pos);
int		ft_backtracking(struct s_grid grid, int pos, int comb, int val);
char	*ft_get_row(char *str, int index);
char	*ft_get_column(char *str, int index);
char	*ft_get_line(char *str, int index);
int		ft_get_number_remove(int index_line);
void	ft_remove_row(char *str, int index_line, int number_remove);
void	ft_remove_column(char *str, int index_line, int number_remove);
void	ft_remove_line(char *str, int index_line, int number_remove);
int		ft_comeback(char *str);

#endif
