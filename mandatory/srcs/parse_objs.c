/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:22 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/29 17:48:15 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	classify(t_info *const info, int fd, char *buf)
{
	if (buf[0] == 'N')
		get_texfile(info, fd, buf, id_north_wall);
	else if (buf[0] == 'S')
		get_texfile(info, fd, buf, id_south_wall);
	else if (buf[0] == 'W')
		get_texfile(info, fd, buf, id_west_wall);
	else if (buf[0] == 'E')
		get_texfile(info, fd, buf, id_east_wall);
	else if (buf[0] == 'F')
		get_rgb(info, fd, buf, id_floor);
	else if (buf[0] == 'C')
		get_rgb(info, fd, buf, id_ceiling);
	else if (buf[0] == '\n' || buf[0] == ' ')
		return ;
	else
		exit_process("invalid *.cub form!(9)", EXIT_FAILURE, info, fd);
}

static void	check_valid_xpm_file(t_info *const info, int fd)
{
	int	north_fd;
	int	south_fd;
	int	west_fd;
	int	east_fd;

	north_fd = open(info->objects.north_wall.file, O_RDONLY);
	south_fd = open(info->objects.south_wall.file, O_RDONLY);
	west_fd = open(info->objects.west_wall.file, O_RDONLY);
	east_fd = open(info->objects.east_wall.file, O_RDONLY);
	if (north_fd == -1 || south_fd == -1 || west_fd == -1 || east_fd == -1)
	{
		if (north_fd != -1)
			close(north_fd);
		if (south_fd != -1)
			close(south_fd);
		if (west_fd != -1)
			close(west_fd);
		if (east_fd != -1)
			close(east_fd);
		exit_process("open(texture) error", EXIT_FAILURE, info, fd);
	}
}

void	parse_objs(t_info *const info, int fd, char *buf)
{
	int	read_byte;

	while (!(info->objects.north_wall.file && info->objects.south_wall.file && \
			info->objects.west_wall.file && info->objects.east_wall.file && \
			info->objects.rgb_floor.is_init && \
			info->objects.rgb_ceiling.is_init))
	{
		read_byte = read(fd, buf, 1);
		if (read_byte != 1)
			exit_process("invalid *.cub form!(10)", EXIT_FAILURE, info, fd);
		else
			classify(info, fd, buf);
	}
	check_valid_xpm_file(info, fd);
}
