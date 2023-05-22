/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 04:20:44 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:38:40 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	puterr(void)
{
	ft_putendl_fd("ft_atoi() error: null argument", 2);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	tmp;

	if (!str)
		return (puterr());
	sign = 1;
	tmp = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		tmp = (tmp * 10) + (*str - '0');
		str++;
		if (sign == 1 && tmp > 2147483647)
			return (-1);
		else if (sign == -1 && tmp > 2147483648)
			return (0);
	}
	return (tmp * sign);
}
