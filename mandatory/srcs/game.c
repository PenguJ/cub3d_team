/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:22:26 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 20:49:14 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	hook_key_press(int key, t_info *const info)
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

static int	loop_hook(t_info *const info)
{
	mlx_hook(info->sys.win_ptr, event_destroy_notify, 0L, hook_click_x, info);
	mlx_hook(info->sys.win_ptr, event_key_press, 0L, hook_key_press, info);
	return (0);
}

void	draw_screen_img(t_info *const info)
{
	draw_background(info);
	draw_wall_using_raycast(info);
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
