/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:17:09 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/21 14:55:41 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	idx;
	size_t	jdx;

	idx = 0;
	tmp = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (s1)
	{
		while (s1[idx])
		{
			tmp[idx] = s1[idx];
			++idx;
		}
	}
	jdx = idx;
	idx = 0;
	while (s2[idx])
	{
		tmp[idx + jdx] = s2[idx];
		++idx;
	}
	return (tmp);
}
