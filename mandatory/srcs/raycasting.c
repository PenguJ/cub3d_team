/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:15:23 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 21:05:37 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_side_delta_dist(t_info *info)
{
	if (info->game.fp.fov.ray_dv_x > 0.00000000)
	{
		info->game.fp.fov.step_x = 1;
		info->game.fp.fov.side_dist_x = info->game.fp.fov.delta_dist_x * \
		(ceil(info->game.fp.pos.x) - info->game.fp.pos.x);
	}
	else
	{
		info->game.fp.fov.step_x = -1;
		info->game.fp.fov.side_dist_x = info->game.fp.fov.delta_dist_x * \
		(info->game.fp.pos.x - floor(info->game.fp.pos.x));
	}
	if (info->game.fp.fov.ray_dv_y > 0.00000000)
	{	
		info->game.fp.fov.step_y = 1;
		info->game.fp.fov.side_dist_y = info->game.fp.fov.delta_dist_y * \
			(ceil(info->game.fp.pos.y) - info->game.fp.pos.y);
	}
	else
	{
		info->game.fp.fov.step_y = -1;
		info->game.fp.fov.side_dist_y = info->game.fp.fov.delta_dist_y * \
		(info->game.fp.pos.y - floor(info->game.fp.pos.y));
	}
}

static void	get_ray_dv(t_info *info, int i)
{
	info->game.fp.fov.camera_coor_oper = \
		((2. * (double)i) / (double)win_width) - 1;
	info->game.fp.fov.ray_dv_x = \
		info->game.fp.pov.dv_x + \
		info->game.fp.fov.plain_x * info->game.fp.fov.camera_coor_oper;
	info->game.fp.fov.ray_dv_y = \
		info->game.fp.pov.dv_y + \
		info->game.fp.fov.plain_y * info->game.fp.fov.camera_coor_oper;
	if (info->game.fp.fov.ray_dv_x != 0.)
		info->game.fp.fov.delta_dist_x = \
			sqrt(1 + \
			(info->game.fp.fov.ray_dv_y * info->game.fp.fov.ray_dv_y) / \
			(info->game.fp.fov.ray_dv_x * info->game.fp.fov.ray_dv_x));
	info->game.fp.fov.delta_dist_x = fabs(1 / info->game.fp.fov.ray_dv_x);
	if (info->game.fp.fov.ray_dv_y != 0.)
		info->game.fp.fov.delta_dist_y = \
			sqrt(1 + \
			(info->game.fp.fov.ray_dv_x * info->game.fp.fov.ray_dv_x) / \
			(info->game.fp.fov.ray_dv_y * info->game.fp.fov.ray_dv_y));
	info->game.fp.fov.delta_dist_y = fabs(1 / info->game.fp.fov.ray_dv_y);
}

static void	set_wall(t_info *info, int i)
{
	int	x;

	x = (int)((info->game.fp.fov.wall_x - \
		floor(info->game.fp.fov.wall_x)) * 64.000000);
	if (info->game.fp.fov.side == 1 && \
	info->game.fp.fov.step_y == -1)
		draw_north_raycasted_pixel(info, i, x);
	else if (info->game.fp.fov.side == 1)
		draw_south_raycasted_pixel(info, i, x);
	else if (info->game.fp.fov.step_x == 1)
		draw_east_raycasted_pixel(info, i, x);
	else
		draw_west_raycasted_pixel(info, i, x);
}

void	draw_wall_using_raycast(t_info *const info)
{
	int	i;

	i = win_width - 1;
	while (i >= 0)
	{
		get_ray_dv(info, i);
		get_side_delta_dist(info);
		dda(info, 0, 0);
		set_wall(info, win_width - i - 1);
		--i;
	}
}
