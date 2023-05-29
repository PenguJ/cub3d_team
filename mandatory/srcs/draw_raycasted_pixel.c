/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasted_pixel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:36:42 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 20:59:58 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	calculate_draw_points(t_info *info, int *start, int *end)
{
	*start = (win_height - info->game.fp.fov.line_height) / 2;
	*end = (win_height + info->game.fp.fov.line_height) / 2 ;
	if (*start < 0)
		*start = 0;
	if (*end >= win_height)
		*end = win_height - 1;
}

void	draw_north_raycasted_pixel(t_info *info, int i, int x)
{
	int		draw_start;
	int		draw_end;
	int		idx;
	int		y;
	char	*dst;

	idx = 0;
	calculate_draw_points(info, &draw_start, &draw_end);
	while (draw_start + idx < draw_end)
	{
		if (((win_height - info->game.fp.fov.line_height) \
			* 32. / info->game.fp.fov.line_height) < 0.)
			y = (int)((((64.) * idx) / info->game.fp.fov.line_height) \
			- ((win_height - info->game.fp.fov.line_height) * \
			32. / info->game.fp.fov.line_height));
		else
			y = (int)(64. * idx / (draw_end - draw_start));
		dst = info->screen.addr + ((draw_start + idx) * \
		info->screen.line_length + i * (info->screen.bits_per_pixel / 8));
		*(int *)dst = info->objects.north_wall.buf[(int)(y * \
		info->objects.north_wall.line_bytes / 4. + x)];
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

	idx = 0;
	calculate_draw_points(info, &draw_start, &draw_end);
	while (draw_start + idx < draw_end)
	{
		if (((win_height - info->game.fp.fov.line_height) \
			* 32. / info->game.fp.fov.line_height) < 0.)
			y = (int)((((64.) * idx) / info->game.fp.fov.line_height) \
			- ((win_height - info->game.fp.fov.line_height) * \
			32. / info->game.fp.fov.line_height));
		else
			y = (int)(64. * idx / (draw_end - draw_start));
		dst = info->screen.addr + ((draw_start + idx) * \
		info->screen.line_length + i * (info->screen.bits_per_pixel / 8));
		*(int *)dst = info->objects.south_wall.buf[(int)(y * \
		info->objects.south_wall.line_bytes / 4. + (63 - x))];
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

	idx = 0;
	calculate_draw_points(info, &draw_start, &draw_end);
	while (draw_start + idx < draw_end)
	{
		if (((win_height - info->game.fp.fov.line_height) \
			* 32. / info->game.fp.fov.line_height) < 0.)
			y = (int)((((64.) * idx) / info->game.fp.fov.line_height) \
			- ((win_height - info->game.fp.fov.line_height) * \
			32. / info->game.fp.fov.line_height));
		else
			y = (int)(64. * idx / (draw_end - draw_start));
		dst = info->screen.addr + ((draw_start + idx) * \
		info->screen.line_length + i * (info->screen.bits_per_pixel / 8));
		*(int *)dst = info->objects.west_wall.buf[(int)(y \
		* info->objects.west_wall.line_bytes / 4. + (63 - x))];
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

	idx = 0;
	calculate_draw_points(info, &draw_start, &draw_end);
	while (draw_start + idx < draw_end)
	{
		if (((win_height - info->game.fp.fov.line_height) \
			* 32. / info->game.fp.fov.line_height) < 0.)
			y = (int)((((64.) * idx) / info->game.fp.fov.line_height) \
			- ((win_height - info->game.fp.fov.line_height) * \
			32. / info->game.fp.fov.line_height));
		else
			y = (int)(64. * idx / (draw_end - draw_start));
		dst = info->screen.addr + ((draw_start + idx) * \
		info->screen.line_length + i * (info->screen.bits_per_pixel / 8));
		*(int *)dst = info->objects.east_wall.buf[(int)(y \
		* info->objects.east_wall.line_bytes / 4. + x)];
		idx++;
	}
}
