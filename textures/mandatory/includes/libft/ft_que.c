/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_que.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:47:40 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:34:18 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_queinit(t_que *q)
{
	if (!q)
	{
		ft_putendl_fd("ft_queinit() error: null argument", 2);
		return ;
	}
	q -> head = NULL;
	q -> tail = NULL;
}

int	ft_queisempty(t_que *q)
{
	if (!q)
	{
		ft_putendl_fd("ft_queisempty() error: null argument", 2);
		return (-1);
	}
	return (q -> head == NULL);
}

t_que	*ft_quepush(t_que *q, void *dat)
{
	t_list	*new;

	if (!q)
	{
		ft_putendl_fd("ft_quepush() error: null", 2);
		return (NULL);
	}
	new = ft_lstnew(dat);
	if (!new)
		return (ft_allocerr());
	if (ft_queisempty(q))
	{
		q -> head = new;
		q -> tail = new;
	}
	else
	{
		q -> tail -> next = new;
		q -> tail = new;
	}
	return (q);
}

void	*ft_quepop(t_que *q)
{
	t_list	*tmp;
	void	*dat;

	if (!q)
	{
		ft_putendl_fd("ft_quepop() error: null", 2);
		return (NULL);
	}
	if (ft_queisempty(q))
	{
		ft_putstr_fd("Error: ft_quepop: queue empty\n", 2);
		return (NULL);
	}
	tmp = q -> head;
	dat = tmp -> dat;
	q -> head = tmp -> next;
	if (q -> head == NULL)
		q ->tail = NULL;
	free(tmp);
	return (dat);
}
