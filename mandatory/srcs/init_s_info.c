/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:25 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/21 22:27:33 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_info(t_info *const info)
{
	info->game.map.width = 0;
	info->game.map.height = 0;
	info->game.map.pars = NULL;


	info->game.first_person.pov = 0.0;
	info->game.first_person.pos.x = 0.0;
	info->game.first_person.pos.y = 0.0;


	info->objects.rgb_floor.is_init = false;
	info->objects.rgb_floor.red = 0;
	info->objects.rgb_floor.green = 0;
	info->objects.rgb_floor.blue = 0;

	info->objects.rgb_ceiling.is_init = false;
	info->objects.rgb_ceiling.red = 0;
	info->objects.rgb_ceiling.green = 0;
	info->objects.rgb_ceiling.blue = 0;

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



	info->sys.mlx_ptr = NULL;
	info->sys.win_ptr = NULL;
}
