/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TESTCODE_delete!!!.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:18:06 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/24 23:31:48 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//TESTCODE
void	check_leaks(void)
{
	printf("\n\n\n");
	system("leaks cub3D");
	printf("\n\n\n");
}

void	printInfo(t_info *const info)
{
	printf("no is: \"%s\"\n", info->objects.north_wall.file);
	printf("so is: \"%s\"\n", info->objects.south_wall.file);
	printf("we is: \"%s\"\n", info->objects.west_wall.file);
	printf("ea is: \"%s\"\n", info->objects.east_wall.file);
	printf("rgb_floor: [%d, %d, %d] = %d\n", info->objects.rgb_floor.red, \
										info->objects.rgb_floor.green, \
										info->objects.rgb_floor.blue, \
										info->objects.rgb_floor.rgb);
	printf("rgb_ceiling: [%d, %d, %d] = %d\n", info->objects.rgb_ceiling.red, \
										info->objects.rgb_ceiling.green, \
										info->objects.rgb_ceiling.blue, \
										info->objects.rgb_ceiling.rgb);
	printf("width: %zu,  height: %zu\n", info->game.map.width, \
										info->game.map.height);
	printf("pos_x: %lf,   pos_y: %lf\n", info->game.fp.pov.dv_x, \
										info->game.fp.pov.dv_y);
	printf("pos_x: %lf,   pos_y: %lf\n", info->game.fp.pos.x, \
										info->game.fp.pos.y);
	for (size_t idx = 0; info->game.map.pars[idx]; ++idx)
		printf("|%s|\n", info->game.map.pars[idx]);
	printf("\n\n\ntmpTEST\n\n");
	
	size_t x = 0;
	size_t y = 0;

	for (; y < info->game.map.height; ++y)
	{
		x = 0;
		printf("|");
		for(; x < info->game.map.width; ++x)
		{
			if (info->game.map.pars[y][x] == '1')
				printf("1");
			else if (info->game.map.pars[y][x] == '0')
				printf("0");
			else if (info->game.map.pars[y][x] == ' ')
				printf("`");
			else if (info->game.map.pars[y][x] == '\0')
				printf(" ");
			else
				printf("@");

		}
		printf("|\n");
	}
}

void	put_minimap(t_info *const info)
{
	const int	x_coordinate = (info->game.fp.pos.x - 0.5) * 10;
	const int	y_coordinate = (info->game.fp.pos.y - 0.5) * 10;
	size_t		x;
	size_t		y;

	y = 0;
	while (y < info->game.map.height)
	{
		x = 0;
		while (x < info->game.map.width)
		{
			if (info->game.map.pars[y][x] == '1')
				mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
					info->objects.minimap_wall.ptr, x * 10, y * 10);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		info->objects.minimap_point.ptr, x_coordinate, y_coordinate);
}
