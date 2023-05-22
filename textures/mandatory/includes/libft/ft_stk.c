/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:00:03 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:18:06 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stkinit(t_stk *s)
{
	if (!s)
	{
		ft_putendl_fd("ft_stkinit() error: null argument", 2);
		return ;
	}
	s -> top = NULL;
}

int	ft_stkisempty(t_stk *s)
{
	if (!s)
	{
		ft_putendl_fd("ft_stkisempty() error: null argument", 2);
		return (-1);
	}
	return (s -> top == NULL);
}

t_stk	*ft_stkpush(t_stk *s, void *dat)
{
	t_list	*new;

	if (!s)
	{
		ft_putendl_fd("ft_stkpush() error: null", 2);
		return (NULL);
	}
	new = ft_lstnew(dat);
	if (!new)
		return (ft_allocerr());
	new -> next = s -> top;
	s -> top = new;
	return (s);
}

void	*ft_stkpop(t_stk *s)
{
	t_list	*tmp;
	void	*dat;

	if (!s)
	{
		ft_putendl_fd("ft_stkpop() error: null", 2);
		return (NULL);
	}
	if (ft_stkisempty(s))
	{
		ft_putstr_fd("Error: ft_stkpop: stack empty\n", 2);
		return (NULL);
	}
	tmp = s -> top;
	dat = tmp -> dat;
	s -> top = s -> top -> next;
	free(tmp);
	return (dat);
}
