/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:23:51 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:40:56 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	unsigned char	*sub_s1;
	unsigned char	*sub_s2;

	if (!s1 || !s2)
	{
		ft_putendl_fd("ft_strncmp() error: null argument", 2);
		return (0);
	}
	sub_s1 = (unsigned char *)s1;
	sub_s2 = (unsigned char *)s2;
	while (*sub_s1 && *sub_s2 && *sub_s1 == *sub_s2 && num)
	{
		sub_s1++;
		sub_s2++;
		num--;
	}
	if (!num)
		return (0);
	return (*sub_s1 - *sub_s2);
}
