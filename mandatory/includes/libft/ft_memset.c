/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:23:24 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:25:51 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t num)
{
	void	*tmp;

	if (!str)
	{
		ft_putendl_fd("ft_memset() error: null argument", 2);
		return (NULL);
	}
	tmp = str;
	while (num--)
		*((unsigned char *)tmp++) = (unsigned char)c;
	return (str);
}
