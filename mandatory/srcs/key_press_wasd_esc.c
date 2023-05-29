/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_wasd_esc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:14:22 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 20:18:17 by jeojeon          ###   ########.fr       */
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
