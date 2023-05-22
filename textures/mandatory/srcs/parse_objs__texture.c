/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs__texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:19 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/21 22:27:08 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_direct_file(t_info *const info, t_obj_id id, char ***out_file)
{
	if (id == id_north_wall)
		*out_file = &(info->objects.north_wall.file);
	if (id == id_south_wall)
		*out_file = &(info->objects.south_wall.file);
	if (id == id_east_wall)
		*out_file = &(info->objects.east_wall.file);
	if (id == id_west_wall)
		*out_file = &(info->objects.west_wall.file);
}

void	get_texfile(t_info *const info, int fd, char *buf, enum e_obj_id id)
{
	int		read_byte;
	char	*tmp;
	char	**file;

	get_direct_file(info, id, &file);
	read_byte = read(fd, buf, 1);
	if (read_byte != 1 || *file || \
		((id == id_north_wall || id == id_south_wall) && (buf[0] != 'O')) || \
		(id == id_west_wall && buf[0] != 'E') || \
		(id == id_east_wall && buf[0] != 'A') || \
		skip_space(fd, buf) < 1)
		exit_process("invalid *.cub form!(1)", EXIT_FAILURE, info, fd);
	while (true)
	{
		tmp = *file;
		*file = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		read_byte = read(fd, buf, 1);
		if (read_byte != 1 || *file == NULL)
			exit_process("invalid *.cub form!(2)", EXIT_FAILURE, info, fd);
		else if (buf[0] == '\n')
			return ;
	}
}
