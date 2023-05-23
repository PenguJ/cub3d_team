/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map__get_map_0.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:14 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/23 18:29:41 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_valid_num_space(t_info *const info, int fd, char *buf)
{
	int	read_byte;
	int	ret;

	ret = 0;
	while (true)
	{
		read_byte = read(fd, buf, 1);
		if (read_byte != 1 || \
			(buf[0] != ' ' && buf[0] != '\n' && buf[0] != '1'))
			exit_process("invalid *.cub form!(11)", EXIT_FAILURE, info, fd);
		else if (buf[0] == '1')
			return (ret);
		else if (buf[0] == '\n')
			ret = 0;
		else if (buf[0] == ' ')
			++ret;
	}
}

static char	*init_map_line(t_info *const in, int fd, int const nsp)
{
	char	*ret;

	if (nsp)
	{
		ret = (char *)ft_calloc(nsp + 1, sizeof(char));
		if (!ret)
			exit_process("ft_calloc() error", EXIT_FAILURE, in, fd);
		ft_memset(ret, ' ', nsp);
	}
	else
	{
		ret = ft_strdup("");
		if (!ret)
			exit_process("ft_calloc() error", EXIT_FAILURE, in, fd);
	}
	return (ret);
}

static void	get_one_line_map(t_info *const info, int fd, \
							char *buf, char **map_line)
{
	int		read_byte;
	bool	is_overlap_nl;
	bool	is_emptyline_space;

	is_overlap_nl = false;
	is_emptyline_space = false;
	while (true)
	{
		get_joined_map(info, fd, buf, map_line);
		read_byte = read(fd, buf, 1);
		if (read_byte == 0)
		{
			check_valid_eof(info, fd, &is_emptyline_space, map_line);
			break ;
		}
		else if (!is_valid_elem(buf[0]))
		{
			if (check_continuable(&is_overlap_nl, buf[0], map_line) == failure)
				exit_process("invalid *.cub form!(13)", EXIT_FAILURE, info, fd);
			else
				continue ;
		}
		else
			flag_booleans(buf[0], &is_overlap_nl, &is_emptyline_space);
	}
}

void	get_map(t_info *const info, int fd, char *buf)
{
	int const	num_space = get_valid_num_space(info, fd, buf);
	char		*map_line;

	map_line = init_map_line(info, fd, num_space);
	get_one_line_map(info, fd, buf, &map_line);
	info->game.map.pars = ft_rectangle_split(map_line, '\n');
	free(map_line);
	if (!(info->game.map.pars))
		exit_process("invalid *.cub form!(14)", EXIT_FAILURE, info, fd);
}
