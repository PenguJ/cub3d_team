/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:18:06 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 19:21:43 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_minimap(t_info *const info)
{
	const int	x_coordinate = (info->game.fp.pos.x - 0.5) * 10;
	const int	y_coordinate = (info->game.fp.pos.y - 0.5) * 10;
	size_t		x;
	size_t		y;

	y = 0;
	while (y < info->game.map.height)
	{
		x = 0;
		while (x < info->game.map.width)
		{
			if (info->game.map.pars[y][x] == '1')
				mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
					info->objects.minimap_wall.ptr, x * 10, y * 10);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		info->objects.minimap_point.ptr, x_coordinate, y_coordinate);
}
