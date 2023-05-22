/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:21:57 by jeojeon           #+#    #+#             */
/*   Updated: 2022/07/16 11:39:13 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*bf_lst;

	if (!lst || !(*del))
		return ;
	while (*lst)
	{
		bf_lst = *lst;
		(*del)((*lst)-> dat);
		*lst = (*lst)-> next;
		free(bf_lst);
	}
}
