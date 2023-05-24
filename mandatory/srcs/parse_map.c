/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:17 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/24 15:43:32 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_direction(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	is_valid_elem(char c)
{
	if (c == '1' || c == '0' || c == ' ' || is_direction(c))
		return (true);
	return (false);
}

static void	init_info_width_and_height(t_info *const info)
{
	size_t *const	wid = &(info->game.map.width);
	size_t *const	hei = &(info->game.map.height);

	while (info->game.map.pars[*hei])
	{
		if (ft_strlen(info->game.map.pars[*hei]) > *wid)
			*wid = ft_strlen(info->game.map.pars[*hei]);
		++(*hei);
	}
}

static void	init_info_pov_and_pos(t_info *const info, size_t x, size_t y)
{
	while (y < info->game.map.height)
	{
		x = 0;
		while (x < info->game.map.width)
		{
			if (is_direction(info->game.map.pars[y][x]))
			{
				info->game.first_person.pos.x = x + 0.5;
				info->game.first_person.pos.y = y + 0.5;
				// if (info->game.map.pars[y][x] == 'E')
				// 	info->game.first_person.pov = 0;
				// else if (info->game.map.pars[y][x] == 'N')
				// 	info->game.first_person.pov = 90;
				// else if (info->game.map.pars[y][x] == 'W')
				// 	info->game.first_person.pov = 180;
				// else if (info->game.map.pars[y][x] == 'S')
				// 	info->game.first_person.pov = 270;
				return ;
			}
			++x;
		}
		++y;
	}
}

void	parse_map(t_info *const info, int fd, char *buf)
{
	get_map(info, fd, buf);
	close(fd);
	init_info_width_and_height(info);
	check_map_validation(info, 0, 0, false);
	init_info_pov_and_pos(info, 0, 0);
}
