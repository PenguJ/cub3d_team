/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TESTCODE_delete!!!.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:18:06 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/24 21:39:08 by jeojeon          ###   ########.fr       */
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










//MLX_TESTCODE	(order: {EVENT(hook) -> LOGIC} -> UPDATE -> {CLEAR -> PRINT})
//0xFF6464
// void	draw_ray(t_info *const info)
// {
// 	double posX = info->game.fp.pos.x;
// 	double posY = info->game.fp.pos.y;
// 	double dirX = info->game.
// }

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

void	raycasting(t_info *const info)
{
	double posX = 22, posY = 12;
	

}










int	hook_click_x(t_info *const info)
{
	exit_process(NULL, EXIT_SUCCESS, info, 0);
	return (0);
}

int	key_press(int key, t_info *const info)
{
	if (key == key_w)
		info->game.fp.pos.y -= 0.1;
	else if (key == key_s)
		info->game.fp.pos.y += 0.1;
	else if (key == key_a)
		info->game.fp.pos.x -= 0.1;
	else if (key == key_d)
		info->game.fp.pos.x += 0.1;
	else if (key == key_left)
	{
		info->game.fp.pov.dv_x = \
			(info->game.fp.pov.dv_x * cos(-1 * ANGLE_5)) \
			- \
			(info->game.fp.pov.dv_y * sin(-1 * ANGLE_5));
		info->game.fp.pov.dv_y = \
			(info->game.fp.pov.dv_x * sin(-1 * ANGLE_5)) \
			+ \
			(info->game.fp.pov.dv_y * cos(-1 * ANGLE_5));
	}
	else if (key == key_right)
	{
		info->game.fp.pov.dv_x = \
			(info->game.fp.pov.dv_x * cos(ANGLE_5)) \
			- \
			(info->game.fp.pov.dv_y * sin(ANGLE_5));
		info->game.fp.pov.dv_y = \
			(info->game.fp.pov.dv_x * sin(ANGLE_5)) \
			+ \
			(info->game.fp.pov.dv_y * cos(ANGLE_5));
	}
	else if (key == key_esc)
		exit_process(NULL, EXIT_SUCCESS, info, 0);
printf("pos_x: %lf,   pos_y: %lf\n", info->game.fp.pos.x, \
							info->game.fp.pos.y);
printf("pov_x: %lf,   pov_y: %lf\n", info->game.fp.pov.dv_x, \
							info->game.fp.pov.dv_y);
	return (0);
}






int	loop_hook(t_info *const info)
{
	mlx_hook(info->sys.win_ptr, event_destroy_notify, 0L, hook_click_x, info);
	//key_release는 필요 없을지도..? (동시키 입력이면 필요할 수 있음)
	mlx_hook(info->sys.win_ptr, event_key_press, 0L, &key_press, info);

	mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
//	put_test_image(info);
	put_minimap(info);
	raycasting(info);
	return (0);
}









void	mlxTest(t_info *const info)
{
	//create_new_mlx_window
	info->sys.mlx_ptr = mlx_init();
	if (!info->sys.mlx_ptr)
	{
		exit_process("mlx_init() error!", EXIT_FAILURE, info, 0);
	}
	info->sys.win_ptr = mlx_new_window(info->sys.mlx_ptr, \
		win_width, win_height, "TESTCODE");
	if (!info->sys.win_ptr)
	{
		exit_process("mlx_new_window() error!", EXIT_FAILURE, info, 0);
	}

	//create_imgs
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
	if (!info->objects.north_wall.ptr || \
		!info->objects.south_wall.ptr || \
		!info->objects.west_wall.ptr || \
		!info->objects.east_wall.ptr)
	{
		if (!info->objects.north_wall.ptr)
			ft_putendl_fd("north_wall_err", STDERR_FILENO);
		if (!info->objects.south_wall.ptr)
			ft_putendl_fd("south_wall_err", STDERR_FILENO);
		if (!info->objects.west_wall.ptr)
			ft_putendl_fd("west_wall_err", STDERR_FILENO);
		if (!info->objects.east_wall.ptr)
			ft_putendl_fd("east_wall_err", STDERR_FILENO);
		exit_process("mlx_xpm_file_to_image() error!", EXIT_FAILURE, info, 0);
	}
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
	if (!info->objects.minimap_wall.ptr || \
		!info->objects.minimap_point.ptr)
	{
		if (!info->objects.minimap_wall.ptr)
			ft_putendl_fd("minimap_wall_err", STDERR_FILENO);
		if (!info->objects.minimap_point.ptr)
			ft_putendl_fd("minimap_point_err", STDERR_FILENO);
		exit_process("mlx_xpm_file_to_image() error!", EXIT_FAILURE, info, 0);
	}

	//mlx_loop_hook() :: do looping for no input(UPDATE)
		//in 'mlx_loop_hook()'`s param function, can do some action by hooking(mlx_hook())
		//must be cleared each loop frame! and re-input updated imgs!
			//input imgs are maked by some mlx`s img functions.
				//mlx_new_image()
				//mlx_get_data_addr()
				//mlx_put_image_to_window() : put imgs to real window.
				//mlx_xpm_file_to_image() : it is for just parsing.
	mlx_loop_hook(info->sys.mlx_ptr, &loop_hook, info);

	//infininy looping
	mlx_loop(info->sys.mlx_ptr);
}































