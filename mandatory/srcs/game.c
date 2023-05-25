/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:18:43 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/25 17:54:10 by geonlee          ###   ########.fr       */
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
		info->game.fp.pov.radian--;
		if (info->game.fp.pov.radian == -1)
			info->game.fp.pov.radian = 71;
		info->game.fp.pov.dv_now_x = \
			(info->game.fp.pov.dv_x * cos(ANGLE_5 * info->game.fp.pov.radian)) \
			- \
			(info->game.fp.pov.dv_y * sin(ANGLE_5 * info->game.fp.pov.radian));
		info->game.fp.pov.dv_now_y = \
			(info->game.fp.pov.dv_x * sin(ANGLE_5 * info->game.fp.pov.radian)) \
			+ \
			(info->game.fp.pov.dv_y * cos(ANGLE_5 * info->game.fp.pov.radian));
		info->game.fp.pov.plain_x = info->game.fp.pov.dv_now_y;
		info->game.fp.pov.plain_y = info->game.fp.pov.dv_now_x * -1;
	}
	else if (key == key_right)
	{
		info->game.fp.pov.radian++;
		if (info->game.fp.pov.radian == 72)
			info->game.fp.pov.radian = 0;
		info->game.fp.pov.dv_now_x = \
			(info->game.fp.pov.dv_x * cos(ANGLE_5 * info->game.fp.pov.radian)) \
			- \
			(info->game.fp.pov.dv_y * sin(ANGLE_5 * info->game.fp.pov.radian));
		info->game.fp.pov.dv_now_y = \
			(info->game.fp.pov.dv_x * sin(ANGLE_5 * info->game.fp.pov.radian)) \
			+ \
			(info->game.fp.pov.dv_y * cos(ANGLE_5 * info->game.fp.pov.radian));
		info->game.fp.pov.plain_x = info->game.fp.pov.dv_now_y;
		info->game.fp.pov.plain_y = info->game.fp.pov.dv_now_x * -1;
	}
	else if (key == key_esc)
		exit_process(NULL, EXIT_SUCCESS, info, 0);
printf("pos_x: %lf,   pos_y: %lf\n", info->game.fp.pos.x, \
							info->game.fp.pos.y);
printf("pov_now_x: %lf,   pov_now_y: %lf\n", info->game.fp.pov.dv_now_x, \
							info->game.fp.pov.dv_now_y);
printf("plain_x: %lf,   plain_y: %lf\n", info->game.fp.pov.plain_x, \
							info->game.fp.pov.plain_y);
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
