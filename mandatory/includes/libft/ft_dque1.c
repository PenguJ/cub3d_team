/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dque1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:41:54 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:33:52 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dqueinit(t_dque *dq)
{
	if (!dq)
	{
		ft_putendl_fd("ft_dqueinit() error: null argument", 2);
		return ;
	}
	dq -> head = NULL;
	dq -> tail = NULL;
}

int	ft_dqueisempty(t_dque *dq)
{
	if (!dq)
	{
		ft_putendl_fd("ft_dqueisempty() error: null argument", 2);
		return (-1);
	}
	return (dq -> head == NULL);
}
