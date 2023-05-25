/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:18:43 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/26 01:52:16 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	hook_click_x(t_info *const info)
{
	exit_process(NULL, EXIT_SUCCESS, info, 0);
	return (0);
}

int	hook_key_press(int key, t_info *const info)
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
	}
	else if (key == key_right)
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
	}
	else if (key == key_esc)
		exit_process(NULL, EXIT_SUCCESS, info, 0);
printf("pos_x: %lf,   pos_y: %lf\n", info->game.fp.pos.x, \
							info->game.fp.pos.y);
printf("pov_now_x: %lf,   pov_now_y: %lf\n", info->game.fp.pov.dv_x, \
							info->game.fp.pov.dv_y);
printf("plain_x: %lf,   plain_y: %lf\n", info->game.fp.fov.plain_x, \
							info->game.fp.fov.plain_y);
	return (0);
}



void	get_ray_dv(t_info *const info, int i)
{
	info->game.fp.fov.camera_coor_oper = ((2 * i) / win_width) - 1;
	info->game.fp.fov.ray_dv_x = \
		info->game.fp.pos.x \
		+ \
		info->game.fp.fov.plain_x * info->game.fp.fov.camera_coor_oper;
	info->game.fp.fov.ray_dv_y = \
		info->game.fp.pos.y \
		+ \
		info->game.fp.fov.plain_y * info->game.fp.fov.camera_coor_oper;
}

void	draw_wall_using_raycast(t_info *const info)
{
	int	i;

	i = 0;
	while (i < win_width)
	{
		get_ray_dv(info, i);
		//get_ray_hit_distance_and_side_using_dda();
		//get_height_of_wall()
			//get_vertical_distance_from_wall_to_pos();
		//draw_wall
		++i;
	}
}

void	draw_screen_img(t_info *const info)
{
	//paint_floor_and_ceiling(info);
	draw_wall_using_raycast(info);
}

static int	loop_hook(t_info *const info)
{
	mlx_hook(info->sys.win_ptr, event_destroy_notify, 0L, hook_click_x, info);
	mlx_hook(info->sys.win_ptr, event_key_press, 0L, hook_key_press, info);
	draw_screen_img(info);
	mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		info->screen.img, 0, 0);

//testingMinimapPrint
put_minimap(info);

	//paint_black_to_screen_img(info);
	return (0);
}

void	game(t_info *const info)
{
	mlx_loop_hook(info->sys.mlx_ptr, &loop_hook, info);
	mlx_loop(info->sys.mlx_ptr);
}
