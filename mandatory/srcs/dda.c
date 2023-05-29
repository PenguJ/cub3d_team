/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:40:47 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 20:55:09 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	update_ray_data(t_info *const info, int x, int y)
{
	if (info->game.fp.fov.side == 0)
	{
		info->game.fp.fov.perp_wall_dist = \
			(x - info->game.fp.pos.x + \
			(1 - info->game.fp.fov.step_x) / 2) / info->game.fp.fov.ray_dv_x;
		info->game.fp.fov.wall_x = \
			info->game.fp.pos.y + \
			(info->game.fp.fov.perp_wall_dist * info->game.fp.fov.ray_dv_y);
	}
	else
	{
		info->game.fp.fov.perp_wall_dist = \
			(y - info->game.fp.pos.y + \
			(1 - info->game.fp.fov.step_y) / 2) / info->game.fp.fov.ray_dv_y;
		info->game.fp.fov.wall_x = \
			info->game.fp.pos.x + \
			(info->game.fp.fov.perp_wall_dist * info->game.fp.fov.ray_dv_x);
	}
	info->game.fp.fov.line_height = \
		(int)(win_width / info->game.fp.fov.perp_wall_dist);
}

void	dda(t_info *info, int x, int y)
{
	x = (int)floor(info->game.fp.pos.x);
	y = (int)floor(info->game.fp.pos.y);
	info->game.fp.fov.side = 0;
	while (true)
	{
		if (info->game.fp.fov.side_dist_x < info->game.fp.fov.side_dist_y)
		{
			info->game.fp.fov.side_dist_x += info->game.fp.fov.delta_dist_x;
			x += info->game.fp.fov.step_x;
			info->game.fp.fov.side = 0;
		}
		else
		{
			info->game.fp.fov.side_dist_y += info->game.fp.fov.delta_dist_y;
			y += info->game.fp.fov.step_y;
			info->game.fp.fov.side = 1;
		}
		if (info->game.map.pars[y][x] == '1')
		{
			update_ray_data(info, x, y);
			break ;
		}
	}
}
