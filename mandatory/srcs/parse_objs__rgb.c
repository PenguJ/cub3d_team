/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs__rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:21 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/21 22:27:14 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	callocate_color_strs(t_info *const info, int fd, char ***out_strs)
{
	size_t	idx;

	idx = 0;
	*out_strs = (char **)ft_calloc(4, sizeof(char *));
	if (!(*out_strs))
		exit_process("ft_calloc() error", EXIT_FAILURE, info, fd);
	(*out_strs)[3] = NULL;
	while (idx < 3)
	{
		(*out_strs)[idx] = (char *)ft_calloc(4, sizeof(char));
		if (!((*out_strs)[idx]))
			break ;
		++idx;
	}
	if (idx != 3)
	{
		if (idx != 0)
			while (idx >= 0)
				free((*out_strs)[idx--]);
		free(*out_strs);
		exit_process("ft_calloc() error", EXIT_FAILURE, info, fd);
	}
}

static t_state	get_color_strs(char ***out_strs, int idx, int fd, char *buf)
{
	int	read_byte;
	int	len;

	len = -1;
	while (++len < 3)
	{
		if (ft_isdigit(buf[0]))
			(*out_strs)[idx][len] = buf[0];
		else if (read_byte == 1 && \
				((idx != 2 && len > 0 && buf[0] == ',') || \
				(idx == 2 && len > 0 && (buf[0] == '\n' || buf[0] == ' '))))
			return (success);
		else
			return (failure);
		read_byte = read(fd, buf, 1);
	}
	return (success);
}

static void	get_rgb_strs(t_info *const info, int fd, \
						char *buf, char ***out_strs)
{
	int	idx;

	idx = -1;
	while (++idx < 3)
	{
		if (get_color_strs(out_strs, idx, fd, buf) == failure)
			exit_process("invalid *.cub form!(3)", EXIT_FAILURE, info, fd);
		else if (idx != 2 && buf[0] != ',')
			exit_process("invalid *.cub form!(4)", EXIT_FAILURE, info, fd);
		else if (idx != 2 && buf[0] == ',')
			read(fd, buf, 1);
		else if (idx == 2 && buf[0] != '\n')
		{
			if (buf[0] == ' ')
				skip_space(fd, buf);
			if (buf[0] != '\n')
				exit_process("invalid *.cub form!(5)", EXIT_FAILURE, info, fd);
		}
	}
}

static void	check_invalid_rgb_value(t_info *const info, int fd, t_obj_id id)
{
	if (id == id_floor)
	{
		if (info->objects.rgb_floor.red < 0 || \
			info->objects.rgb_floor.red > 255 || \
			info->objects.rgb_floor.green < 0 || \
			info->objects.rgb_floor.green > 255 || \
			info->objects.rgb_floor.blue < 0 || \
			info->objects.rgb_floor.blue > 255)
			exit_process("invalid *.cub form!(6)", EXIT_FAILURE, info, fd);
	}
	else if (id == id_ceiling)
	{
		if (info->objects.rgb_ceiling.red < 0 || \
			info->objects.rgb_ceiling.red > 255 || \
			info->objects.rgb_ceiling.green < 0 || \
			info->objects.rgb_ceiling.green > 255 || \
			info->objects.rgb_ceiling.blue < 0 || \
			info->objects.rgb_ceiling.blue > 255)
			exit_process("invalid *.cub form!(7)", EXIT_FAILURE, info, fd);
	}
}

void	get_rgb(t_info *const info, int fd, char *buf, t_obj_id id)
{
	char	**color_strs;

	if ((id == id_floor && info->objects.rgb_floor.is_init) || \
		(id == id_ceiling && info->objects.rgb_ceiling.is_init) || \
		skip_space(fd, buf) < 1)
		exit_process("invalid *.cub form!(8)", EXIT_FAILURE, info, fd);
	callocate_color_strs(info, fd, &color_strs);
	get_rgb_strs(info, fd, buf, &color_strs);
	if (id == id_floor)
	{
		info->objects.rgb_floor.red = ft_atoi(color_strs[0]);
		info->objects.rgb_floor.green = ft_atoi(color_strs[1]);
		info->objects.rgb_floor.blue = ft_atoi(color_strs[2]);
		info->objects.rgb_floor.is_init = true;
	}
	else if (id == id_ceiling)
	{
		info->objects.rgb_ceiling.red = ft_atoi(color_strs[0]);
		info->objects.rgb_ceiling.green = ft_atoi(color_strs[1]);
		info->objects.rgb_ceiling.blue = ft_atoi(color_strs[2]);
		info->objects.rgb_ceiling.is_init = true;
	}
	ft_delsplit(color_strs);
	check_invalid_rgb_value(info, fd, id);
}
