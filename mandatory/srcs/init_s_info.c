/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:25 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/25 23:48:02 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_info(t_info *const info)
{
	info->game.map.width = 0;
	info->game.map.height = 0;
	info->game.map.pars = NULL;


	info->game.fp.pov.initial_dv_x = 0.0;
	info->game.fp.pov.initial_dv_y = 0.0;
	info->game.fp.pov.dv_x = 0.0;
	info->game.fp.pov.dv_y = 0.0;
	info->game.fp.pov.cnt = 0;
	info->game.fp.fov.plain_x = 0.0;
	info->game.fp.fov.plain_y = 0.0;
	info->game.fp.fov.camera_coor_oper = 0.0;
	info->game.fp.fov.ray_dv_x = 0.0;
	info->game.fp.fov.ray_dv_y = 0.0;

	info->game.fp.pos.x = 0.0;
	info->game.fp.pos.y = 0.0;


	info->objects.rgb_floor.is_init = false;
	info->objects.rgb_floor.red = 0;
	info->objects.rgb_floor.green = 0;
	info->objects.rgb_floor.blue = 0;
	info->objects.rgb_floor.rgb = 0;

	info->objects.rgb_ceiling.is_init = false;
	info->objects.rgb_ceiling.red = 0;
	info->objects.rgb_ceiling.green = 0;
	info->objects.rgb_ceiling.blue = 0;
	info->objects.rgb_ceiling.rgb = 0;

	info->objects.north_wall.file = NULL;
	info->objects.north_wall.cols = 0;
	info->objects.north_wall.rows = 0;
	info->objects.north_wall.ptr = NULL;

	info->objects.south_wall.file = NULL;
	info->objects.south_wall.cols = 0;
	info->objects.south_wall.rows = 0;
	info->objects.south_wall.ptr = NULL;

	info->objects.east_wall.file = NULL;
	info->objects.east_wall.cols = 0;
	info->objects.east_wall.rows = 0;
	info->objects.east_wall.ptr = NULL;

	info->objects.west_wall.file = NULL;
	info->objects.west_wall.cols = 0;
	info->objects.west_wall.rows = 0;
	info->objects.west_wall.ptr = NULL;

	info->objects.minimap_wall.cols = 0;
	info->objects.minimap_wall.rows = 0;
	info->objects.minimap_wall.ptr = NULL;

	info->objects.minimap_point.cols = 0;
	info->objects.minimap_point.rows = 0;
	info->objects.minimap_point.ptr = NULL;



	info->screen.img = NULL;
	info->screen.addr = NULL;
	info->screen.bits_per_pixel = 0;
	info->screen.line_length = 0;
	info->screen.endian = 0;



	info->sys.mlx_ptr = NULL;
	info->sys.win_ptr = NULL;
}
