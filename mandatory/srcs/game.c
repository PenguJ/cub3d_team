/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegeonha <leegeonha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:18:43 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/26 09:36:59 by leegeonha        ###   ########.fr       */
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
	draw_black_background(info);
	draw_screen_img(info);
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
	// printf("^^^^%f %f \n",info->game.fp.fov.ray_dv_x,info->game.fp.fov.ray_dv_y);
}


void	get_side_delta_dist(t_info *info)
{
	if (info->game.fp.fov.ray_dv_x != 0.00000000)
		info->game.fp.fov.delta_dist_x = fabs(1 / info->game.fp.fov.ray_dv_x);
	if (info->game.fp.fov.ray_dv_y != 0.00000000)
		info->game.fp.fov.delta_dist_y = fabs(1 / info->game.fp.fov.ray_dv_y);

	if (info->game.fp.fov.ray_dv_x > 0.00000000)
		info->game.fp.fov.side_dist_x = info->game.fp.fov.delta_dist_x * \
		(ceil(info->game.fp.pos.x) - info->game.fp.pos.x);
	else if (info->game.fp.fov.ray_dv_x < 0.00000000)
		info->game.fp.fov.side_dist_x = info->game.fp.fov.delta_dist_x * \
		(info->game.fp.pos.x - floor(info->game.fp.pos.x));

	if (info->game.fp.fov.ray_dv_y > 0.00000000)
	info->game.fp.fov.side_dist_y = info->game.fp.fov.delta_dist_y * \
		(ceil(info->game.fp.pos.y) - info->game.fp.pos.y);
	else if (info->game.fp.fov.ray_dv_y < 0.00000000)
		info->game.fp.fov.side_dist_y = info->game.fp.fov.delta_dist_y * \
		(info->game.fp.pos.y - floor(info->game.fp.pos.y));
}

void	dda(t_info *info)  // 어차피 벽 방향 판별 추가해야 해서 함수 쪼개야함 
{
	int x;
	int y;

	x = (int)floor(info->game.fp.pos.x);
	y = (int)floor(info->game.fp.pos.y);
	while (1)
	{
		if (info->game.fp.fov.ray_dv_x != 0.00000000 && \
		info->game.fp.fov.side_dist_x < info->game.fp.fov.side_dist_y)
		{
			 info->game.fp.fov.side_dist_x += info->game.fp.fov.delta_dist_x;
			if (info->game.fp.fov.ray_dv_x > 0) // x 배열범위 이상일 경우 고려 할 필요 없을듯? 벽을 항상 만나기 때문
				x++;
			else
				x--;
		}
		else if (info->game.fp.fov.ray_dv_y != 0.00000000 && \
			info->game.fp.fov.side_dist_x >= info->game.fp.fov.side_dist_y)
		{
			info->game.fp.fov.side_dist_y += info->game.fp.fov.delta_dist_y;
			if (info->game.fp.fov.ray_dv_y > 0) // y 배열범위 이상일 경우 고려 할 필요 없을듯? 벽을 항상 만나기 때문
				y++;
			else
				y--;
		}
		if (info->game.map.pars[y][x] == '1')
		{
			if (info->game.fp.fov.side_dist_x < info->game.fp.fov.side_dist_y)
				info->game.fp.fov.perp_wall_dist = info->game.fp.fov.side_dist_x; // 아직 어안 상태 
			else
				info->game.fp.fov.perp_wall_dist = info->game.fp.fov.side_dist_y;
			printf("%f %f %f %f %f \n ",info->game.fp.fov.ray_dv_x,info->game.fp.fov.ray_dv_y,info->game.fp.fov.plain_x,info->game.fp.fov.plain_y,info->game.fp.fov.perp_wall_dist);
			info->game.fp.fov.line_height = (int)(win_width / info->game.fp.fov.perp_wall_dist);
			break; // 벽이 있으므로 항상 break 되는것이 보증 될듯.
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
	// printf("i : %d , cnt : %d \n",i,cnt);
}

void	get_ray_hit_distance_and_side_using_dda(t_info *info)
{	
	get_side_delta_dist(info);
	dda(info);
	printf("AAAA %d\n",info->game.fp.fov.line_height);
}

void	draw_wall_using_raycast(t_info *const info)
{
	int	i;

	i = 0;
	while (i < win_width)
	{
		get_ray_dv(info, i);
		get_ray_hit_distance_and_side_using_dda(info);
		draw_raycasted_pixel(info, i);
		//get_height_of_wall()
			//get_vertical_distance_from_wall_to_pos();
		//draw_wall
		++i;
	}
}

void	draw_screen_img(t_info *const info)
{
	//paint_floor_and_ceiling(info);
	draw_background(info);
	draw_wall_using_raycast(info);
}

static int	loop_hook(t_info *const info)
{
	mlx_hook(info->sys.win_ptr, event_destroy_notify, 0L, hook_click_x, info);
	mlx_hook(info->sys.win_ptr, event_key_press, 0L, hook_key_press, info);

	// mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);

//testingMinimapPrint
// put_minimap(info);

	//paint_black_to_screen_img(info);
	return (0);
}

void	game(t_info *const info)
{
	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		info->screen.img, 0, 0);
	draw_screen_img(info);
	mlx_loop_hook(info->sys.mlx_ptr, &loop_hook, info);
	mlx_loop(info->sys.mlx_ptr);
}
