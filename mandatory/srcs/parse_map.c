/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegeonha <leegeonha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:17 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/26 09:00:20 by leegeonha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

static void	init_pov_lit(t_info *const in, double dypx, double dx, double py)
{
	in->game.fp.pov.initial_dv_x = dx;
	in->game.fp.pov.initial_dv_y = dypx;
	in->game.fp.fov.plain_x = dypx * FOV_HALF_SCALAR;
	in->game.fp.fov.plain_y = py;
}

static void	init_pov(t_info *const info, char c)
{
	if (c == 'E')
	{
		init_pov_lit(info, 0, 1, -1 * FOV_HALF_SCALAR);
	}
	else if (c == 'N')
	{
		init_pov_lit(info, -1, 0, 0);
	}
	else if (c == 'W')
	{
		init_pov_lit(info, 0, -1, FOV_HALF_SCALAR);
	}
	else if (c == 'S')
	{
		init_pov_lit(info, 1, 0, 0);
	}
	info->game.fp.pov.dv_x = info->game.fp.pov.initial_dv_x;
	info->game.fp.pov.dv_y = info->game.fp.pov.initial_dv_y;
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
				info->game.fp.pos.x = x + 0.5;
				info->game.fp.pos.y = y + 0.5;
				init_pov(info, info->game.map.pars[y][x]);
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
