/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:25 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/27 13:57:01 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_info(t_info *const info)
{
	init_info_map(info);
	init_info_fp(info);
	init_info_rgb(info);
	init_info_ew_wall(info);
	init_info_ns_wall(info);
	init_info_mlx_and_screen(info);
	info->objects.minimap_wall.cols = 0;
	info->objects.minimap_wall.rows = 0;
	info->objects.minimap_wall.ptr = NULL;
	info->objects.minimap_point.cols = 0;
	info->objects.minimap_point.rows = 0;
	info->objects.minimap_point.ptr = NULL;
}
