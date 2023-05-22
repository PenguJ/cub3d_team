/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:18:24 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:40:43 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	return_len;

	if (!dst || !src)
	{
		ft_putendl_fd("ft_strlcat() error: null argument", 2);
		return (0);
	}
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	return_len = dst_len + src_len;
	while (*src && dst_len + 1 < size)
		dst[dst_len++] = *src++;
	dst[dst_len] = 0;
	return (return_len);
}
