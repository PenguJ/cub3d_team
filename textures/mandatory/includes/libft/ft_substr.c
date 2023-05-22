/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:18:00 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 16:54:23 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	if (!s)
	{
		ft_putendl_fd("ft_substr() error: null argument", 2);
		return (NULL);
	}
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	tmp = ft_calloc(len + 1, sizeof(char));
	if (!tmp)
		return (ft_allocerr());
	ft_strlcpy(tmp, s + start, len + 1);
	return (tmp);
}
