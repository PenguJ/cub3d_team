/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:23:58 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:30:57 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*base;
	t_list	*new;

	if (!lst || !(*f))
		return (NULL);
	base = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst -> dat));
		if (!new)
		{
			ft_lstclear(&base, (*del));
			return (ft_allocerr());
		}
		ft_lstadd_back(&base, new);
		lst = lst -> next;
	}
	return (base);
}
