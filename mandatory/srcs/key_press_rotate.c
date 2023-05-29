/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:19:34 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 20:20:25 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	press_left_arrow(t_info *const info)
{
	info->game.fp.pov.cnt--;
	if (info->game.fp.pov.cnt == -1)
		info->game.fp.pov.cnt = 71;
	info->game.fp.pov.dv_x = \
		(info->game.fp.pov.initial_dv_x * \
			cos(ANGLE_5 * info->game.fp.pov.cnt)) \
		- \
		(info->game.fp.pov.initial_dv_y * \
			sin(ANGLE_5 * info->game.fp.pov.cnt));
	info->game.fp.pov.dv_y = \
		(info->game.fp.pov.initial_dv_x * \
			sin(ANGLE_5 * info->game.fp.pov.cnt)) \
		+ \
		(info->game.fp.pov.initial_dv_y * \
			cos(ANGLE_5 * info->game.fp.pov.cnt));
	info->game.fp.fov.plain_x = \
		info->game.fp.pov.dv_y * FOV_HALF_SCALAR;
	info->game.fp.fov.plain_y = \
		info->game.fp.pov.dv_x * -1 * FOV_HALF_SCALAR;
	draw_screen_img(info);
	mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		info->screen.img, 0, 0);
	put_minimap(info);
}

void	press_right_arrow(t_info *const info)
{
	info->game.fp.pov.cnt++;
	if (info->game.fp.pov.cnt == 72)
		info->game.fp.pov.cnt = 0;
	info->game.fp.pov.dv_x = \
		(info->game.fp.pov.initial_dv_x * \
			cos(ANGLE_5 * info->game.fp.pov.cnt)) \
		- \
		(info->game.fp.pov.initial_dv_y * \
			sin(ANGLE_5 * info->game.fp.pov.cnt));
	info->game.fp.pov.dv_y = \
		(info->game.fp.pov.initial_dv_x * \
			sin(ANGLE_5 * info->game.fp.pov.cnt)) \
		+ \
		(info->game.fp.pov.initial_dv_y * \
			cos(ANGLE_5 * info->game.fp.pov.cnt));
	info->game.fp.fov.plain_x = \
		info->game.fp.pov.dv_y * FOV_HALF_SCALAR;
	info->game.fp.fov.plain_y = \
		info->game.fp.pov.dv_x * -1 * FOV_HALF_SCALAR;
	draw_screen_img(info);
	mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		info->screen.img, 0, 0);
	put_minimap(info);
}
