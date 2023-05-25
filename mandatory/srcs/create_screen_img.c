/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegeonha <leegeonha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:42:54 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/26 07:59:46 by leegeonha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_black_background(t_info *const info)
{
	char	*dst;
	int		x;
	int		y;

	y = 0;
	while (y < win_height)
	{
		x = 0;
		while (x < win_width)
		{
			dst = info->screen.addr + (y * info->screen.line_length + x * \
				(info->screen.bits_per_pixel / 8));
			*(unsigned int *)dst = 0x00000000;
			++x;
		}
		++y;
	}
}

void	draw_background(t_info *const info)
{
	char	*dst;
	int		x;
	int		y;

	y = 0;
	while (y < win_height)
	{
		x = 0;
		while (x < win_width)
		{
			dst = info->screen.addr + (y * info->screen.line_length + x * \
				(info->screen.bits_per_pixel / 8));
			if (y < 360)
				*(unsigned int *)dst = info->objects.rgb_ceiling.rgb + \
					(256 * 256 * 256 * ((y * 255) / (win_height / 2)));
			else
				*(unsigned int *)dst = info->objects.rgb_floor.rgb + \
					(256 * 256 * 256 * (((win_height - y) * 255) / (win_height / 2)));
			++x;
		}
		++y;
	}
}

void	create_screen_img(t_info *const info)
{
	info->screen.img = mlx_new_image(info->sys.mlx_ptr, win_width, win_height);
	if (!info->screen.img)
		exit_process("mlx_new_imgae() error", EXIT_FAILURE, info, 0);
	info->screen.addr = mlx_get_data_addr(info->screen.img, \
						&info->screen.bits_per_pixel, \
						&info->screen.line_length, \
						&info->screen.endian);
	if (!info->screen.addr)
		exit_process("mlx_get_data_addr() error", EXIT_FAILURE, info, 0);
	draw_background(info);
	// draw_ray(info); 
}
