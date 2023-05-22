/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:22 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/21 22:27:06 by jeojeon          ###   ########.fr       */
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
}
