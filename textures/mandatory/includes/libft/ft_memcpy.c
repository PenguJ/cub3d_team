/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:41:09 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:26:52 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	void	*tmp;

	if (!dest && !src)
	{
		ft_putendl_fd("ft_memcpy() error: null argument", 2);
		return (NULL);
	}
	tmp = dest;
	while (num--)
		*((unsigned char *)tmp++) = *((unsigned char *)src++);
	return (dest);
}
