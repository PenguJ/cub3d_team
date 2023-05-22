/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:44:49 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 16:56:51 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (!s)
	{
		ft_putendl_fd("ft_strmapi() error: null argument", 2);
		return (NULL);
	}
	tmp = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!tmp)
		return (ft_allocerr());
	while (s[i])
	{
		tmp[i] = (*f)(i, s[i]);
		i++;
	}
	return (tmp);
}
