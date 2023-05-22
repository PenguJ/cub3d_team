/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:19:56 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:14:00 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;

	if (!s1 || !set)
	{
		ft_putendl_fd("ft_strtrim() error: null argument", 2);
		return (NULL);
	}
	end = (char *)s1 + (ft_strlen(s1) - 1);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (end > s1 && ft_strchr(set, *end))
		end--;
	if (!s1)
	{
		ft_putendl_fd("ft_strtrim() error: $s1 become nullptr", 2);
		return (NULL);
	}
	return (ft_substr(s1, 0, end - s1 + 1));
}
