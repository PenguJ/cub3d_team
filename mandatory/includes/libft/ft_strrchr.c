/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 07:34:28 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:03:03 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;
	char	c1;

	if (!s)
	{
		ft_putendl_fd("ft_strrchr() error: null argument", 2);
		return (NULL);
	}
	c1 = c;
	str = (char *)s;
	len = ft_strlen(str);
	while (len && (str[len] != c1))
		len--;
	if (str[len] == c1)
		return (&str[len]);
	return (NULL);
}
