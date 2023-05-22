/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dque2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:42:14 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:32:56 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dque	*ft_dquepush_front(t_dque *dq, void *dat)
{
	t_dlist	*new;

	if (!dq)
	{
		ft_putendl_fd("ft_dquepush_front() error: null", 2);
		return (NULL);
	}
	new = (t_dlist *)ft_calloc(1, sizeof(t_dlist));
	if (!new)
		return (ft_allocerr());
	new -> dat = dat;
	new -> next = dq -> head;
	if (ft_dqueisempty(dq))
		dq -> tail = new;
	else
		dq -> head -> prev = new;
	new -> prev = NULL;
	dq -> head = new;
	return (dq);
}

t_dque	*ft_dquepush_back(t_dque *dq, void *dat)
{
	t_dlist	*new;

	if (!dq)
	{
		ft_putendl_fd("ft_dquepush_back() error: null", 2);
		return (NULL);
	}
	new = (t_dlist *)ft_calloc(1, sizeof(t_dlist));
	if (!new)
		return (ft_allocerr());
	new -> dat = dat;
	new -> prev = dq -> tail;
	if (ft_dqueisempty(dq))
		dq -> head = new;
	else
		dq -> tail -> next = new;
	new -> next = NULL;
	dq -> tail = new;
	return (dq);
}

void	*ft_dquepop_front(t_dque *dq)
{
	t_dlist	*tmp;
	void	*dat;

	if (!dq)
	{
		ft_putendl_fd("ft_dquepop_front() error: null", 2);
		return (NULL);
	}
	if (ft_dqueisempty(dq))
	{
		ft_putstr_fd("Error: ft_dquepop: deque empty\n", 2);
		return (NULL);
	}
	tmp = dq -> head;
	dat = tmp -> dat;
	dq -> head = dq -> head -> next;
	if (dq -> head == NULL)
		dq -> tail = NULL;
	else
		dq -> head -> prev = NULL;
	free(tmp);
	return (dat);
}

void	*ft_dquepop_back(t_dque *dq)
{
	t_dlist	*tmp;
	void	*dat;

	if (!dq)
	{
		ft_putendl_fd("ft_dquepop_back() error: null", 2);
		return (NULL);
	}
	if (ft_dqueisempty(dq))
	{
		ft_putstr_fd("Error: ft_dquepop: deque empty\n", 2);
		return (NULL);
	}
	tmp = dq -> tail;
	dat = tmp -> dat;
	dq -> tail = dq -> tail -> prev;
	if (dq -> tail == NULL)
		dq -> head = NULL;
	else
		dq -> tail -> next = NULL;
	free(tmp);
	return (dat);
}
