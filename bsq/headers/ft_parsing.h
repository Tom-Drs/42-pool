/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:17:44 by vfries            #+#    #+#             */
/*   Updated: 2022/08/24 18:17:46 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

typedef struct s_map_data {
	int		x;
	int		y;
	char	**map;
	char	empty_char;
	char	obstacle_char;
	char	filled_char;
}	t_map_data;

char		**ft_split(char *str, char *charset);
char		*ft_read_file(char *file_name);
t_map_data	*ft_parse(char *file_name, int type);
int			ft_free_bool(char *str);
void		ft_free_map_data(t_map_data *map_data);
char		*ft_free_char(char *str);
int			ft_free_negative(char *str);

int			ft_get_map_height(char **map);
int			ft_is_valid_header(char **map);
int			ft_is_valid_char(char **map);
char		*ft_get_char(char **map);
int			ft_is_valid_line(char **map);

int			ft_maplen(char *line, char *char_map);
int			ft_is_valid_map(char **map);

char		*get_str_from_file(void);

#endif
