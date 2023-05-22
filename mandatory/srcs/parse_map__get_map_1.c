/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map__get_map_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:10 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/21 22:27:20 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_joined_map(t_info *const info, int fd, char *buf, \
						char **out_map_line)
{
	char	*tmp;

	tmp = *out_map_line;
	*out_map_line = ft_strjoin(*out_map_line, buf);
	free(tmp);
	if (!(*out_map_line))
		exit_process("ft_calloc() error", EXIT_FAILURE, info, fd);
}

void	check_valid_eof(t_info *const info, int fd, bool *is, char **m)
{
	if (*is)
	{
		free(*m);
		exit_process("invalid *.cub form!(12)", EXIT_FAILURE, info, fd);
	}
}

t_state	check_continuable(bool *is, char c, char **map_line)
{
	if (*is == false && c == '\n')
	{
		*is = true;
		return (success);
	}
	free(*map_line);
	return (failure);
}

void	flag_booleans(char c, bool *is_overlap_nl, bool *is_emptyline_sp)
{
	if (c == ' ' && *is_overlap_nl)
	{
		*is_emptyline_sp = true;
		*is_overlap_nl = false;
	}
	else if (c != ' ')
	{
		*is_emptyline_sp = false;
		*is_overlap_nl = false;
	}
}
