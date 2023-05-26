/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:18:43 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/26 18:59:34 by geonlee          ###   ########.fr       */
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
	{
		info->game.fp.pos.x += info->game.fp.pov.dv_x * MOVE_SPEED;
		info->game.fp.pos.y += info->game.fp.pov.dv_y * MOVE_SPEED;
	}
	else if (key == key_s)
	{
		info->game.fp.pos.x -= info->game.fp.pov.dv_x * MOVE_SPEED;
		info->game.fp.pos.y -= info->game.fp.pov.dv_y * MOVE_SPEED;
	}
	else if (key == key_d)
	{
		info->game.fp.pos.x += info->game.fp.pov.dv_y * MOVE_SPEED;
		info->game.fp.pos.y -= info->game.fp.pov.dv_x * MOVE_SPEED;
	}
	else if (key == key_a)
	{
		info->game.fp.pos.x -= info->game.fp.pov.dv_y * MOVE_SPEED;
		info->game.fp.pos.y += info->game.fp.pov.dv_x * MOVE_SPEED;
	}
	else if (key == key_right)
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
	else if (key == key_left)
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
	draw_screen_img(info);
	mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		info->screen.img, 0, 0);
	return (0);
}



void	get_ray_dv(t_info *info, int i)
{
	info->game.fp.fov.camera_coor_oper = ((2.00000000 * (double)i) / (double)win_width) - 1;
	info->game.fp.fov.ray_dv_x = \
		info->game.fp.pov.dv_x \
		+ \
		info->game.fp.fov.plain_x * info->game.fp.fov.camera_coor_oper;
	info->game.fp.fov.ray_dv_y = \
		info->game.fp.pov.dv_y \
		+ \
		info->game.fp.fov.plain_y * info->game.fp.fov.camera_coor_oper;
	if (info->game.fp.fov.ray_dv_x != 0.00000000)
		info->game.fp.fov.delta_dist_x = fabs(1 / info->game.fp.fov.ray_dv_x);
	if (info->game.fp.fov.ray_dv_y != 0.00000000)
		info->game.fp.fov.delta_dist_y = fabs(1 / info->game.fp.fov.ray_dv_y);
}


void	get_side_delta_dist(t_info *info)
{
	if (info->game.fp.fov.ray_dv_x > 0.00000000)
	{
		info->game.fp.fov.step_x = 1;
		info->game.fp.fov.side_dist_x = info->game.fp.fov.delta_dist_x * \
		(ceil(info->game.fp.pos.x) - info->game.fp.pos.x);		
	}
	else
	{
		info->game.fp.fov.step_x = -1;
		info->game.fp.fov.side_dist_x = info->game.fp.fov.delta_dist_x * \
		(info->game.fp.pos.x - floor(info->game.fp.pos.x));
	}
	if (info->game.fp.fov.ray_dv_y > 0.00000000)
	{	
		info->game.fp.fov.step_y = 1;
		info->game.fp.fov.side_dist_y = info->game.fp.fov.delta_dist_y * \
			(ceil(info->game.fp.pos.y) - info->game.fp.pos.y);
	}
	else
	{
		info->game.fp.fov.step_y = -1;
		info->game.fp.fov.side_dist_y = info->game.fp.fov.delta_dist_y * \
		(info->game.fp.pos.y - floor(info->game.fp.pos.y));
	}
}

void	dda(t_info *info)  // 어차피 벽 방향 판별 추가해야 해서 함수 쪼개야함 
{
	int x;
	int y;

	x = (int)floor(info->game.fp.pos.x);
	y = (int)floor(info->game.fp.pos.y);

	info->game.fp.fov.side = 0;
	while (1)
	{
		if (info->game.fp.fov.side_dist_x < info->game.fp.fov.side_dist_y)
		{
			info->game.fp.fov.side_dist_x += info->game.fp.fov.delta_dist_x;
			x += info->game.fp.fov.step_x;
			info->game.fp.fov.side = 0;
		}
		else
		{
			info->game.fp.fov.side_dist_y += info->game.fp.fov.delta_dist_y;
			y += info->game.fp.fov.step_y;
			info->game.fp.fov.side = 1;
		}
		if (info->game.map.pars[y][x] == '1')
		{	
			if (info->game.fp.fov.side == 0)
				info->game.fp.fov.perp_wall_dist = (x - info->game.fp.pos.x + (1 - info->game.fp.fov.step_x) / 2) / info->game.fp.fov.ray_dv_x;
			else
				info->game.fp.fov.perp_wall_dist = (y - info->game.fp.pos.y + (1 - info->game.fp.fov.step_y) / 2) / info->game.fp.fov.ray_dv_y;
			info->game.fp.fov.line_height = (int)(win_width / info->game.fp.fov.perp_wall_dist);
			break;
		}
	}
}

void	draw_raycasted_pixel(t_info *info, int i)
{
	int	draw_start;
	int	draw_end;
	char	*dst;
	int cnt = 0;
	(void)dst;
	draw_start = (win_height - info->game.fp.fov.line_height) / 2;
	draw_end = (win_height + info->game.fp.fov.line_height) / 2 ;
	if (draw_start < 0)
	draw_start = 0;	  
	if (draw_end >= win_height)
	draw_end = win_height - 1;
	while (draw_start < draw_end)
	{
		dst = info->screen.addr + (draw_start * info->screen.line_length + i * \
					(info->screen.bits_per_pixel / 8));
		*(unsigned int *)dst = 0x00FFFFFF;
		draw_start++;
		cnt++;
	}
}


void	draw_wall_using_raycast(t_info *const info)
{
	int	i;

	i = 0;
	while (i < win_width)
	{
		get_ray_dv(info, i);
		get_side_delta_dist(info);
		dda(info);
		draw_raycasted_pixel(info, i);
		++i;
	}
}

void	draw_screen_img(t_info *const info)
{
	draw_black_background(info);
	draw_background(info);
	draw_wall_using_raycast(info);
}

static int	loop_hook(t_info *const info)
{
	mlx_hook(info->sys.win_ptr, event_destroy_notify, 0L, hook_click_x, info);
	mlx_hook(info->sys.win_ptr, event_key_press, 0L, hook_key_press, info);
	return (0);
}

void	game(t_info *const info)
{
	mlx_loop_hook(info->sys.mlx_ptr, &loop_hook, info);
	draw_screen_img(info);
	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		info->screen.img, 0, 0);
	mlx_loop(info->sys.mlx_ptr);
}
