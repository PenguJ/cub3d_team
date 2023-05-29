/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:26 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 16:19:05 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	destroy_all_mlx(t_info *const info)
{
	if (info->objects.north_wall.ptr)
		mlx_destroy_image(info->sys.mlx_ptr, info->objects.north_wall.ptr);
	if (info->objects.south_wall.ptr)
		mlx_destroy_image(info->sys.mlx_ptr, info->objects.south_wall.ptr);
	if (info->objects.east_wall.ptr)
		mlx_destroy_image(info->sys.mlx_ptr, info->objects.east_wall.ptr);
	if (info->objects.west_wall.ptr)
		mlx_destroy_image(info->sys.mlx_ptr, info->objects.west_wall.ptr);
	if (info->objects.minimap_wall.ptr)
		mlx_destroy_image(info->sys.mlx_ptr, info->objects.minimap_wall.ptr);
	if (info->objects.minimap_point.ptr)
		mlx_destroy_image(info->sys.mlx_ptr, info->objects.minimap_point.ptr);
	if (info->screen.img)
		mlx_destroy_image(info->sys.mlx_ptr, info->screen.img);
	if (info->sys.mlx_ptr)
		mlx_destroy_window(info->sys.mlx_ptr, info->sys.win_ptr);
}

static void	release_all_info_data(t_info *const info)
{
	destroy_all_mlx(info);
	ft_delsplit(info->game.map.pars);
	free(info->objects.north_wall.file);
	free(info->objects.south_wall.file);
	free(info->objects.east_wall.file);
	free(info->objects.west_wall.file);
}

void	exit_process(char *msg, int exit_code, t_info *const info, int fd)
{
	if (fd)
		close(fd);
	if (info)
		release_all_info_data(info);
	if (msg)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(msg, STDERR_FILENO);
	}
	free(info);
	exit(exit_code);
}
