/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs__rgb2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:32:57 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 19:43:22 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	handle_out_str_callocate_err(t_info *const info, int fd, \
										char ***out_strs, size_t idx)
{
	if (idx != 0)
	{
		while (idx > 0)
		{
			free((*out_strs)[idx--]);
			if (idx == 0)
				break ;
		}
	}
	free(*out_strs);
	exit_process("ft_calloc() error", EXIT_FAILURE, info, fd);
}

void	callocate_color_strs(t_info *const info, int fd, char ***out_strs)
{
	size_t	idx;

	idx = 0;
	*out_strs = (char **)ft_calloc(4, sizeof(char *));
	if (!(*out_strs))
		exit_process("ft_calloc() error", EXIT_FAILURE, info, fd);
	(*out_strs)[3] = NULL;
	while (idx < 3)
	{
		(*out_strs)[idx] = (char *)ft_calloc(4, sizeof(char));
		if (!((*out_strs)[idx]))
			break ;
		++idx;
	}
	if (idx != 3)
		handle_out_str_callocate_err(info, fd, out_strs, idx);
}
