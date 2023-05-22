/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:53:01 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:26:28 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	void	*tmp;

	if (!dest && !src)
	{
		ft_putendl_fd("ft_memmove() error: null argument", 2);
		return (NULL);
	}
	tmp = dest;
	if (dest > src)
		while (num--)
			*((unsigned char *)tmp + num) = *((unsigned char *)src + num);
	else
		while (num--)
			*((unsigned char *)tmp++) = *((unsigned char *)src++);
	return (dest);
}
