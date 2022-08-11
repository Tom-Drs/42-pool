/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:04:58 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/08 16:35:11 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_length(char *str)
{
	char	*first_ptr;

	first_ptr = str;
	while (*str != '\0')
		str++;
	return (str - first_ptr);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	int				src_length;

	src_length = ft_str_length(src);
	index = 0;
	if (size == 0)
		return (src_length);
	while (src[index] != '\0' && (size - 1) > 0)
	{
		dest[index] = src[index];
		index++;
		size--;
	}
	dest[index] = '\0';
	return (src_length);
}
