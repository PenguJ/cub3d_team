/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:24 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/21 22:27:28 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	skip_space(int fd, char *buf)
{
	int	read_byte;
	int	cnt;

	cnt = 0;
	while (true)
	{
		read_byte = read(fd, buf, 1);
		if (read_byte != 1)
		{
			exit_process("invalid *.cub form(0)!", EXIT_FAILURE, NULL, fd);
		}
		else if (buf[0] == ' ')
		{
			++cnt;
		}
		else
		{
			return (cnt);
		}
	}
}

void	parse_info(t_info *const info, char *file_name)
{
	const size_t	buf_size = 2;
	int				fd;
	char			buf[2];

	ft_bzero(buf, buf_size);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_process("open() error", EXIT_FAILURE, NULL, 0);
	parse_objs(info, fd, buf);
	parse_map(info, fd, buf);
}
