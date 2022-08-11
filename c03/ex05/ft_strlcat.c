/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:41:07 by tdameros          #+#    #+#             */
/*   Updated: 2022/08/08 21:59:44 by tdameros         ###   ########lyon.fr   */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_length;
	unsigned int	dest_length;
	unsigned int	dest_index;
	unsigned int	src_index;

	src_length = ft_str_length(src);
	dest_length = ft_str_length(dest);
	dest_index = 0;
	src_index = 0;
	if (dest_length + 1 > size)
		return (src_length + size);
	while (dest[dest_index] != '\0')
		dest_index++;
	while (src[src_index] != '\0' && dest_index < size - 1)
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	dest[dest_index] = '\0';
	return (dest_length + src_length);
}
