/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_win_imgs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:58:31 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/26 15:54:51 by geonlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include "../includes/cub3d.h"

static void	create_texture_imgs_2(t_info *const info)
{
	info->objects.west_wall.ptr = \
		mlx_xpm_file_to_image(info->sys.mlx_ptr, \
							info->objects.west_wall.file, \
							&(info->objects.west_wall.rows), \
							&(info->objects.west_wall.cols));
	free(info->objects.west_wall.file);
	info->objects.west_wall.file = NULL;
	info->objects.east_wall.ptr = \
		mlx_xpm_file_to_image(info->sys.mlx_ptr, \
						info->objects.east_wall.file, \
						&(info->objects.east_wall.rows), \
						&(info->objects.east_wall.cols));
	free(info->objects.east_wall.file);
	info->objects.east_wall.file = NULL;
}

static void	create_texture_imgs_1(t_info *const info)
{
	info->objects.north_wall.ptr = \
		mlx_xpm_file_to_image(info->sys.mlx_ptr, \
							info->objects.north_wall.file, \
							&(info->objects.north_wall.rows), \
							&(info->objects.north_wall.cols));
	free(info->objects.north_wall.file);
	info->objects.north_wall.file = NULL;
	info->objects.south_wall.ptr = \
		mlx_xpm_file_to_image(info->sys.mlx_ptr, \
							info->objects.south_wall.file, \
							&(info->objects.south_wall.rows), \
							&(info->objects.south_wall.cols));
	free(info->objects.south_wall.file);
	info->objects.south_wall.file = NULL;
}

static void	create_minimap_imgs(t_info *const info)
{
	info->objects.minimap_wall.ptr = \
		mlx_xpm_file_to_image(info->sys.mlx_ptr, \
							"./textures/xpm_imgs/minimap_wall.xpm", \
							&(info->objects.minimap_wall.rows), \
							&(info->objects.minimap_wall.cols));
	info->objects.minimap_point.ptr = \
		mlx_xpm_file_to_image(info->sys.mlx_ptr, \
							"./textures/xpm_imgs/minimap_point.xpm", \
							&(info->objects.minimap_point.rows), \
							&(info->objects.minimap_point.cols));
}

static void	check_xpm_imgs_create_err(t_info *const info)
{
	if (!info->objects.north_wall.ptr || \
	!info->objects.south_wall.ptr || \
	!info->objects.west_wall.ptr || \
	!info->objects.east_wall.ptr || \
	!info->objects.minimap_wall.ptr || \
	!info->objects.minimap_point.ptr)
	{
		exit_process("mlx_xpm_file_to_image", EXIT_FAILURE, info, 0);
	}
}

void	create_mlx_win_imgs(t_info *const info)
{
	info->sys.mlx_ptr = mlx_init();
	if (!info->sys.mlx_ptr)
		exit_process("mlx_init() error!", EXIT_FAILURE, info, 0);
	info->sys.win_ptr = mlx_new_window(info->sys.mlx_ptr, \
		win_width, win_height, "cub3D");
	if (!info->sys.win_ptr)
		exit_process("mlx_new_window() error", EXIT_FAILURE, info, 0);
	create_texture_imgs_1(info);
	create_texture_imgs_2(info);
	create_minimap_imgs(info);
	check_xpm_imgs_create_err(info);
	create_screen_img(info);
}