/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:57:17 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:32:10 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str_size(int n)
{
	char	cnt;

	cnt = 0;
	if (n <= 0)
		cnt++;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	size_t	len;
	long	num;

	len = ft_str_size(n);
	tmp = (char *)ft_calloc(len + 1, sizeof(char));
	if (!tmp)
		return (ft_allocerr());
	num = n;
	if (n < 0)
		num *= -1;
	while (len--)
	{
		tmp[len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		*tmp = '-';
	return (tmp);
}
