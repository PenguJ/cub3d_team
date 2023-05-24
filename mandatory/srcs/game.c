/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:18:43 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/25 01:22:12 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	hook_click_x(t_info *const info)
{
	exit_process(NULL, EXIT_SUCCESS, info, 0);
	return (0);
}

static int	hook_key_press(int key, t_info *const info)
{
	if (key == key_w)
		info->game.fp.pos.y -= 0.1;
	else if (key == key_s)
		info->game.fp.pos.y += 0.1;
	else if (key == key_a)
		info->game.fp.pos.x -= 0.1;
	else if (key == key_d)
		info->game.fp.pos.x += 0.1;
	else if (key == key_left)
	{
		info->game.fp.pov.dv_x = \
			(info->game.fp.pov.dv_x * cos(-1 * ANGLE_5)) \
			- \
			(info->game.fp.pov.dv_y * sin(-1 * ANGLE_5));
		info->game.fp.pov.dv_y = \
			(info->game.fp.pov.dv_x * sin(-1 * ANGLE_5)) \
			+ \
			(info->game.fp.pov.dv_y * cos(-1 * ANGLE_5));
	}
	else if (key == key_right)
	{
		info->game.fp.pov.dv_x = \
			(info->game.fp.pov.dv_x * cos(ANGLE_5)) \
			- \
			(info->game.fp.pov.dv_y * sin(ANGLE_5));
		info->game.fp.pov.dv_y = \
			(info->game.fp.pov.dv_x * sin(ANGLE_5)) \
			+ \
			(info->game.fp.pov.dv_y * cos(ANGLE_5));
	}
	else if (key == key_esc)
		exit_process(NULL, EXIT_SUCCESS, info, 0);
printf("pos_x: %lf,   pos_y: %lf\n", info->game.fp.pos.x, \
							info->game.fp.pos.y);
printf("pov_x: %lf,   pov_y: %lf\n", info->game.fp.pov.dv_x, \
							info->game.fp.pov.dv_y);
	return (0);
}

static int	loop_hook(t_info *const info)
{
	mlx_hook(info->sys.win_ptr, event_destroy_notify, 0L, hook_click_x, info);
	mlx_hook(info->sys.win_ptr, event_key_press, 0L, hook_key_press, info);

	//testRaycasting & draw to screen image!
//	test(info);

	mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		info->screen.img, 0, 0);

//testingMinimapPrint
put_minimap(info);

	return (0);
}

void	game(t_info *const info)
{
	mlx_loop_hook(info->sys.mlx_ptr, &loop_hook, info);
	mlx_loop(info->sys.mlx_ptr);
}
