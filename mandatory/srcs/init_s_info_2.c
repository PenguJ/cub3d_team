/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_info_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:54:34 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/27 13:56:49 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_info_map(t_info *const info)
{
	info->game.map.width = 0;
	info->game.map.height = 0;
	info->game.map.pars = NULL;
}

void	init_info_fp(t_info *const info)
{
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
	info->game.fp.fov.pos_dist_x = 0.0;
	info->game.fp.fov.pos_dist_y = 0.0;
	info->game.fp.fov.side_dist_x = 0.0;
	info->game.fp.fov.side_dist_y = 0.0;
	info->game.fp.fov.delta_dist_x = 0.0;
	info->game.fp.fov.delta_dist_y = 0.0;
	info->game.fp.fov.side = 0;
	info->game.fp.fov.step_x = 0;
	info->game.fp.fov.step_y = 0;
	info->game.fp.pos.x = 0.0;
	info->game.fp.pos.y = 0.0;
}
