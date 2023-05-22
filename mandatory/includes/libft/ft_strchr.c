/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:21:24 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:02:15 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	c1;

	if (!s)
	{
		ft_putendl_fd("ft_strchr() error: null argument", 2);
		return (NULL);
	}
	c1 = c;
	str = (char *)s;
	while (*str && (*str != c1))
		str++;
	if (*str == c1)
		return (str);
	return (NULL);
}
