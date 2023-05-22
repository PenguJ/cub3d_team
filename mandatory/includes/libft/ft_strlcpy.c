/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:44:20 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:40:29 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;

	if (!dst || !src)
	{
		ft_putendl_fd("ft_strlcpy() error: null argument", 2);
		return (0);
	}
	src_size = ft_strlen(src);
	if (!dstsize)
		return (src_size);
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = 0;
	return (src_size);
}
