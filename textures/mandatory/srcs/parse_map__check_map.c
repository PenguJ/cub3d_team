/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map__check_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:15 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/21 22:27:25 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_valid_elem_except_space(char c)
{
	if (c == ' ')
		return (false);
	else if (!is_valid_elem(c))
		return (false);
	return (true);
}

static bool	is_valid_location(char **const map, int x, int y)
{
	if (map[y][x] == '0')
	{
		if (map[y + 1] == NULL || \
			x == 0 || y == 0 || \
			!is_valid_elem_except_space(map[y][x - 1]) || \
			!is_valid_elem_except_space(map[y][x + 1]) || \
			!is_valid_elem_except_space(map[y - 1][x]) || \
			!is_valid_elem_except_space(map[y + 1][x]))
			return (false);
	}
	return (true);
}

void	check_map_validation(t_info *const in, size_t x, size_t y, bool is_dir)
{
	while (in->game.map.pars[y])
	{
		x = 0;
		while (in->game.map.pars[y][x])
		{
			if (!is_valid_elem(in->game.map.pars[y][x]) || \
				(is_dir && is_direction(in->game.map.pars[y][x])))
				exit_process("invalid *.cub form!(15)", EXIT_FAILURE, in, 0);
			else if (is_direction(in->game.map.pars[y][x]))
				is_dir = true;
			else if (!is_valid_location(in->game.map.pars, x, y))
				exit_process("invalid *.cub form!(16)", EXIT_FAILURE, in, 0);
			++x;
		}
		++y;
	}
}
