/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:56:23 by vfries            #+#    #+#             */
/*   Updated: 2022/08/24 17:56:24 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

unsigned int	str_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*str_dup(char *src)
{
	char			*cpy;
	unsigned int	i;

	cpy = malloc(sizeof(char) * (str_len(src) + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*str_cat(char *dest, char *src)
{
	char			*temp;
	unsigned int	i;
	unsigned int	b;

	temp = str_dup(dest);
	if (temp == NULL)
		return (NULL);
	free(dest);
	dest = malloc(sizeof(char) * (str_len(temp) + str_len(src) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		dest[i] = temp[i];
		i++;
	}
	free(temp);
	b = 0;
	while (src[b])
		dest[i++] = src[b++];
	dest[i] = 0;
	return (dest);
}

char	*init_everything(char *str2, int *read_output)
{
	char	*str1;

	str1 = malloc(sizeof(char) * 100000);
	if (str1 == NULL)
		return (NULL);
	*read_output = read(0, str1, 100000 - 1);
	str1[*read_output] = 0;
	str2[0] = 0;
	return (str1);
}

char	*get_str_from_file(void)
{
	int		read_output;
	char	*final_str;
	char	temp_str[100000];

	final_str = init_everything(temp_str, &read_output);
	if (final_str == NULL)
		return (NULL);
	while (read_output)
	{
		final_str = str_cat(final_str, temp_str);
		if (final_str == NULL)
			return (NULL);
		read_output = read(0, temp_str, 100000 - 1);
		temp_str[read_output] = 0;
	}
	final_str = str_cat(final_str, temp_str);
	if (final_str == NULL)
		return (NULL);
	return (final_str);
}
