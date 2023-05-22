/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:46:20 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 16:49:40 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_allocerr(void)
{
	ft_putendl_fd("error: allocate (malloc, calloc, ft_strjoin, etc ...)", 2);
	return (NULL);
}
