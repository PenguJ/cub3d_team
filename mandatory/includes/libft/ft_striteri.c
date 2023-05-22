/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:45:04 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 16:59:05 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		ft_putendl_fd("ft_striteri() error: null argument", 2);
		return ;
	}
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
