/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:17 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/21 22:27:17 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_direction(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	is_valid_elem(char c)
{
	if (c == '1' || c == '0' || c == ' ' || is_direction(c))
		return (true);
	return (false);
}

static void	init_info_width_and_height(t_info *const info)
{
	size_t *const	wid = &(info->game.map.width);
	size_t *const	hei = &(info->game.map.height);

	while (info->game.map.pars[*hei])
	{
		if (ft_strlen(info->game.map.pars[*hei]) > *wid)
			*wid = ft_strlen(info->game.map.pars[*hei]);
		++(*hei);
	}
}

void	parse_map(t_info *const info, int fd, char *buf)
{
	get_map(info, fd, buf);
	close(fd);
	init_info_width_and_height(info);
	check_map_validation(info, 0, 0, false);
}
