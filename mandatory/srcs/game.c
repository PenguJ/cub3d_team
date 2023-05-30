/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:18:43 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 15: by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	hook_click_x(t_info *const info)
{
	exit_process(NULL, EXIT_SUCCESS, info, 0);
	return (0);
}

void	press_key_w(t_info *const info)
{
	if (info->game.map.pars \
	[(int)floor(info->game.fp.pos.y + info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x + info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	!= '1' && \
	info->game.map.pars \
	[(int)floor(info->game.fp.pos.y + info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x + info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	!= ' ' && \
	info->game.map.pars \
	[(int)floor(info->game.fp.pos.y + info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x + info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	!= '\0')
	{
		info->game.fp.pos.x += info->game.fp.pov.dv_x * MOVE_SPEED;
		info->game.fp.pos.y += info->game.fp.pov.dv_y * MOVE_SPEED;
		draw_screen_img(info);
		mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
		mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
			info->screen.img, 0, 0);
		put_minimap(info);
	}
}

void	press_key_s(t_info *const info)
{
	if (info->game.map.pars \
	[(int)floor(info->game.fp.pos.y - info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x - info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	!= '1' && \
	info->game.map.pars \
	[(int)floor(info->game.fp.pos.y - info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x - info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	!= ' ' && \
	info->game.map.pars \
	[(int)floor(info->game.fp.pos.y - info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x - info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	!= '\0')
	{
		info->game.fp.pos.x -= info->game.fp.pov.dv_x * MOVE_SPEED;
		info->game.fp.pos.y -= info->game.fp.pov.dv_y * MOVE_SPEED;
		draw_screen_img(info);
		mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
		mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
			info->screen.img, 0, 0);
		put_minimap(info);
	}
}

void	press_key_d(t_info *const info)
{
	if (info->game.map.pars \
	[(int)floor(info->game.fp.pos.y + info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x - info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	!= '1' && \
	info->game.map.pars \
	[(int)floor(info->game.fp.pos.y + info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x - info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	!= ' ' && \
	info->game.map.pars \
	[(int)floor(info->game.fp.pos.y + info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x - info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	!= '\0')
	{
		info->game.fp.pos.x -= info->game.fp.pov.dv_y * MOVE_SPEED;
		info->game.fp.pos.y += info->game.fp.pov.dv_x * MOVE_SPEED;
		draw_screen_img(info);
		mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
		mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
			info->screen.img, 0, 0);
		put_minimap(info);
	}
}

void	press_key_a(t_info *const info)
{
	if (info->game.map.pars \
	[(int)floor(info->game.fp.pos.y - info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x + info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	!= '1' && \
	info->game.map.pars \
	[(int)floor(info->game.fp.pos.y - info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x + info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	!= ' ' && \
	info->game.map.pars \
	[(int)floor(info->game.fp.pos.y - info->game.fp.pov.dv_x * MOVE_SPEED * 2)] \
	[(int)floor(info->game.fp.pos.x + info->game.fp.pov.dv_y * MOVE_SPEED * 2)] \
	!= '\0')
	{
		info->game.fp.pos.x += info->game.fp.pov.dv_y * MOVE_SPEED;
		info->game.fp.pos.y -= info->game.fp.pov.dv_x * MOVE_SPEED;
		draw_screen_img(info);
		mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
		mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
			info->screen.img, 0, 0);
		put_minimap(info);
	}
}

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

int	hook_key_press(int key, t_info *const info)
{
	if (key == key_w)
		press_key_w(info);
	else if (key == key_s)
		press_key_s(info);
	else if (key == key_d)
		press_key_d(info);
	else if (key == key_a)
		press_key_a(info);
	else if (key == key_left)
		press_left_arrow(info);
	else if (key == key_right)
		press_right_arrow(info);
	else if (key == key_esc)
		exit_process(NULL, EXIT_SUCCESS, info, 0);
	else
		return (0);
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
	info->game.fp.fov.ray_dist = sqrt((info->game.fp.fov.ray_dv_x*info->game.fp.fov.ray_dv_x)+(info->game.fp.fov.ray_dv_y*info->game.fp.fov.ray_dv_y));
	if (info->game.fp.fov.ray_dv_x != 0.00000000)
		info->game.fp.fov.delta_dist_x = sqrt(1 + (info->game.fp.fov.ray_dv_y * info->game.fp.fov.ray_dv_y) / (info->game.fp.fov.ray_dv_x * info->game.fp.fov.ray_dv_x));
		info->game.fp.fov.delta_dist_x = fabs(1 / info->game.fp.fov.ray_dv_x);
	if (info->game.fp.fov.ray_dv_y != 0.00000000)
		info->game.fp.fov.delta_dist_y = sqrt(1 + (info->game.fp.fov.ray_dv_x * info->game.fp.fov.ray_dv_x) / (info->game.fp.fov.ray_dv_y * info->game.fp.fov.ray_dv_y));
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
	while (true)
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
			{
				info->game.fp.fov.perp_wall_dist = (x - info->game.fp.pos.x + (1 - info->game.fp.fov.step_x) / 2) / info->game.fp.fov.ray_dv_x;
				info->game.fp.fov.wall_x = info->game.fp.pos.y + (info->game.fp.fov.perp_wall_dist * info->game.fp.fov.ray_dv_y);
			}
			else
			{
				info->game.fp.fov.perp_wall_dist = (y - info->game.fp.pos.y + (1 - info->game.fp.fov.step_y) / 2) / info->game.fp.fov.ray_dv_y;
				info->game.fp.fov.wall_x = info->game.fp.pos.x + (info->game.fp.fov.perp_wall_dist * info->game.fp.fov.ray_dv_x);
			}
			info->game.fp.fov.line_height = (int)(win_width / info->game.fp.fov.perp_wall_dist);
			break;
		}
	}
}

int		color_gradiate(int i, int depth, int flag)
{
	int r;
	int g;
	int b;
	int result;

	b = i % 256;
	g = (i % (65536)) / 256;
	r = (i % (16777216)) / (65536);
    depth = abs((int)((win_height - depth) / (double)win_height * 255 * 0.95)) ;
	if (r > 0)
		r = (int)fmax(0.000, (double)(r - depth));
	if (g > 0)
		g = (int)fmax(0.000, (double)(g - depth));
	if (b > 0)
		b = (int)fmax(0.000, (double)(b - depth));
	if (flag == 1)
	{
		r>>=1;
		g>>=1;
		b>>=1;
	}
	result = r * 65536 + g * 256 + b;
    return (result);
}

void	draw_north_raycasted_pixel(t_info *info, int i, int x)
{
	int		draw_start;
	int		draw_end;
	int		idx;
	int		y;
	char	*dst;

	draw_start = (win_height - info->game.fp.fov.line_height) / 2;
	draw_end = (win_height + info->game.fp.fov.line_height) / 2 ;
	idx = 0;
	if (draw_start < 0)
	{
		draw_start = 0;	  
	}
	if (draw_end >= win_height)
		draw_end = win_height - 1;
	while (draw_start + idx < draw_end)
	{
		if (((win_height - info->game.fp.fov.line_height) * (double)32 / info->game.fp.fov.line_height) < 0.000000)
			y = (int)((((64.00000000) * idx) / info->game.fp.fov.line_height) - \
			((win_height - info->game.fp.fov.line_height) * (double)32 / info->game.fp.fov.line_height));
		else
			y = (int)(64.00000000 * idx / (draw_end - draw_start));
		dst = info->screen.addr + ((draw_start + idx) * info->screen.line_length + i * \
					(info->screen.bits_per_pixel / 8));
		*(int *)dst = color_gradiate(info->objects.north_wall.buf[(int)(y * info->objects.north_wall.line_bytes / 4.00000000 + x)], draw_end - draw_start, 0);
		idx++;
	}
}

void	draw_south_raycasted_pixel(t_info *info, int i, int x)
{
	int		draw_start;
	int		draw_end;
	int		idx;
	int		y;
	char	*dst;

	draw_start = (win_height - info->game.fp.fov.line_height) / 2;
	draw_end = (win_height + info->game.fp.fov.line_height) / 2 ;
	idx = 0;
	if (draw_start < 0)
	{
		draw_start = 0;	  
	}
	if (draw_end >= win_height)
		draw_end = win_height - 1;
	while (draw_start + idx < draw_end)
	{
		if (((win_height - info->game.fp.fov.line_height) * (double)32 / info->game.fp.fov.line_height) < 0.000000)
			y = (int)((((64.00000000) * idx) / info->game.fp.fov.line_height) - \
			((win_height - info->game.fp.fov.line_height) * (double)32 / info->game.fp.fov.line_height));
		else
			y = (int)(64.00000000 * idx / (draw_end - draw_start));
		dst = info->screen.addr + ((draw_start + idx) * info->screen.line_length + i * \
					(info->screen.bits_per_pixel / 8));
		*(int *)dst = color_gradiate(info->objects.south_wall.buf[(int)(y * info->objects.south_wall.line_bytes / 4.00000000 + (63 - x))], draw_end - draw_start, 0);
		// *(unsigned int *)dst = 0x00FFFFFF;
		idx++;
	}
}

void	draw_west_raycasted_pixel(t_info *info, int i, int x)
{
	int		draw_start;
	int		draw_end;
	int		idx;
	int		y;
	char	*dst;

	draw_start = (win_height - info->game.fp.fov.line_height) / 2;
	draw_end = (win_height + info->game.fp.fov.line_height) / 2 ;
	idx = 0;
	if (draw_start < 0)
	{
		draw_start = 0;	  
	}
	if (draw_end >= win_height)
		draw_end = win_height - 1;
	while (draw_start + idx < draw_end)
	{
		if (((win_height - info->game.fp.fov.line_height) * (double)32 / info->game.fp.fov.line_height) < 0.000000)
			y = (int)((((64.00000000) * idx) / info->game.fp.fov.line_height) - \
			((win_height - info->game.fp.fov.line_height) * (double)32 / info->game.fp.fov.line_height));
		else
			y = (int)(64.00000000 * idx / (draw_end - draw_start));
		dst = info->screen.addr + ((draw_start + idx) * info->screen.line_length + i * \
					(info->screen.bits_per_pixel / 8));
		*(int *)dst = color_gradiate(info->objects.west_wall.buf[(int)(y * info->objects.west_wall.line_bytes / 4.00000000 + (63 - x))], draw_end - draw_start, 1);
		// *(unsigned int *)dst = 0x00FFFFFF;
		idx++;
	}
}

void	draw_east_raycasted_pixel(t_info *info, int i, int x)
{
	int		draw_start;
	int		draw_end;
	int		idx;
	int		y;
	char	*dst;

	draw_start = (win_height - info->game.fp.fov.line_height) / 2;
	draw_end = (win_height + info->game.fp.fov.line_height) / 2 ;
	idx = 0;
	if (draw_start < 0)
	{
		draw_start = 0;	  
	}
	if (draw_end >= win_height)
		draw_end = win_height - 1;
	while (draw_start + idx < draw_end)
	{
		if (((win_height - info->game.fp.fov.line_height) * (double)32 / info->game.fp.fov.line_height) < 0.000000)
			y = (int)((((64.00000000) * idx) / info->game.fp.fov.line_height) - \
			((win_height - info->game.fp.fov.line_height) * (double)32 / info->game.fp.fov.line_height));
		else
			y = (int)(64.00000000 * idx / (draw_end - draw_start));
		dst = info->screen.addr + ((draw_start + idx) * info->screen.line_length + i * \
					(info->screen.bits_per_pixel / 8));
		*(int *)dst = color_gradiate(info->objects.east_wall.buf[(int)(y * info->objects.east_wall.line_bytes / 4.00000000 + x)], draw_end - draw_start, 1);
		// *(unsigned int *)dst = 0x00FFFFFF;
		idx++;
	}
}


void	set_wall(t_info *info, int i)
{
	int x;

	x = (int)((info->game.fp.fov.wall_x - floor(info->game.fp.fov.wall_x)) * 64.000000);
	if (info->game.fp.fov.side== 1 && \
	info->game.fp.fov.step_y == -1)
		draw_north_raycasted_pixel(info, i, x); //north
	else if (info->game.fp.fov.side == 1)
		draw_south_raycasted_pixel(info, i, x); //south
	else if (info->game.fp.fov.step_x == 1)
		draw_east_raycasted_pixel(info, i, x); //east
	else
		draw_west_raycasted_pixel(info, i, x); //west
}


void	draw_wall_using_raycast(t_info *const info)
{
	int	i;

	i = win_width - 1;
	while (i >= 0)
	{
		get_ray_dv(info, i);
		get_side_delta_dist(info);
		dda(info);
		set_wall(info, win_width - i - 1);
		--i;
	}
}

void	draw_screen_img(t_info *const info)
{
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
	draw_screen_img(info);
	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		info->screen.img, 0, 0);
	put_minimap(info);
	mlx_loop_hook(info->sys.mlx_ptr, &loop_hook, info);
	mlx_loop(info->sys.mlx_ptr);
}
