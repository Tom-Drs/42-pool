/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 03:03:00 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/21 22:52:21 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

typedef struct s_dict
{
	int		size;
	char	*key;
	char	*value;
}	t_dict;
char	**ft_split(char *str, char *charset);
char	*ft_read_file(char *file_name);
int		ft_strlen(char *str);
char	*ft_strdup_index(char *str, int index_start, int index_stop);
int		ft_is_printable(int c);
t_dict	**ft_parse(char *file_name, int index_tab, int index_lines);
void	ft_print(char *str, int index, char *arg, int type);
char	*ft_search_unity(char c, int size_arg, t_dict **dict);
char	*ft_search_number(char *ten, t_dict **dict);
int		ft_keep_printing(int i, char *arg);
void	ft_print_argument(char *arg, int size, t_dict **dict);
int		ft_only_zero(char *arg, t_dict **dict);
void	ft_init_others(char **keys);
void	ft_init_hundred(char **keys);
void	ft_init_cent(char **keys);
void	ft_init_ten(char **keys);
void	ft_init_nine(char **keys);
int		ft_check_rules(char *nbr, int size_r);
int		ft_check_int(char *str);
int		ft_check_table_init(t_dict **dict);
int		ft_dictionnary_limit(t_dict **dict, int arg_size, int max_size);
int		ft_is_isspace(char c);
int		ft_line_is_valid(char *line);
int		ft_strlen_jump_zero(char *str);
void	ft_sort_dict(t_dict **dict);
void	ft_free_dict(t_dict **dict);
t_dict	**ft_free_parsing(char **split, char *read);
#endif
