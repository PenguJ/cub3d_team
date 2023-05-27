/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_info_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:57:05 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/27 13:57:21 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_info_rgb(t_info *const info)
{
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
}

void	init_info_ns_wall(t_info *const info)
{
	info->objects.north_wall.file = NULL;
	info->objects.north_wall.cols = 0;
	info->objects.north_wall.rows = 0;
	info->objects.north_wall.ptr = NULL;
	info->objects.north_wall.buf = NULL;
	info->objects.north_wall.pixel_bits = 0;
	info->objects.north_wall.line_bytes = 0;
	info->objects.north_wall.endian = 0;
	info->objects.south_wall.file = NULL;
	info->objects.south_wall.cols = 0;
	info->objects.south_wall.rows = 0;
	info->objects.south_wall.ptr = NULL;
	info->objects.south_wall.buf = NULL;
	info->objects.south_wall.pixel_bits = 0;
	info->objects.south_wall.line_bytes = 0;
	info->objects.south_wall.endian = 0;
}

void	init_info_ew_wall(t_info *const info)
{
	info->objects.east_wall.file = NULL;
	info->objects.east_wall.cols = 0;
	info->objects.east_wall.rows = 0;
	info->objects.east_wall.ptr = NULL;
	info->objects.east_wall.buf = NULL;
	info->objects.east_wall.pixel_bits = 0;
	info->objects.east_wall.line_bytes = 0;
	info->objects.east_wall.endian = 0;
	info->objects.west_wall.file = NULL;
	info->objects.west_wall.cols = 0;
	info->objects.west_wall.rows = 0;
	info->objects.west_wall.ptr = NULL;
	info->objects.west_wall.buf = NULL;
	info->objects.west_wall.pixel_bits = 0;
	info->objects.west_wall.line_bytes = 0;
	info->objects.west_wall.endian = 0;
}

void	init_info_mlx_and_screen(t_info *const info)
{
	info->sys.mlx_ptr = NULL;
	info->sys.win_ptr = NULL;
	info->screen.img = NULL;
	info->screen.addr = NULL;
	info->screen.bits_per_pixel = 0;
	info->screen.line_length = 0;
	info->screen.endian = 0;
}
