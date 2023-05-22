/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TESTCODE_delete!!!.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:18:06 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/22 19:58:59 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



//geonlee
void map_rectangle(t_info *info, int x, int y) // put img 로 대체가능
{
	int i;
	int j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			mlx_pixel_put(info->sys.mlx_ptr, info->sys.win_ptr, (x * 10) + i , (y * 10) + j, 0x00FFFFFF);
			i++;
		}
		j++;
	}
}


void map_circle(t_info *info, int x, int y) // put img 로 대체가능
{
	int i;
	int j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (j == 0 || j == 9)
			{
				if (i == 4 || i == 5)
					mlx_pixel_put(info->sys.mlx_ptr, info->sys.win_ptr, (x * 10) + i , (y * 10) + j, 0x00FF0000);
			}
			else if (j == 1 || j == 8)
			{
				if (i >= 2 && i <= 7)
					mlx_pixel_put(info->sys.mlx_ptr, info->sys.win_ptr, (x * 10) + i , (y * 10) + j, 0x00FF0000);
			}
			else if (j == 2 || j == 3 || j == 6 || j == 7)
			{
				if (i != 0 && i != 9)
					mlx_pixel_put(info->sys.mlx_ptr, info->sys.win_ptr, (x * 10) + i , (y * 10) + j, 0x00FF0000);
			}
			else
			{
				mlx_pixel_put(info->sys.mlx_ptr, info->sys.win_ptr, (x * 10) + i , (y * 10) + j, 0x00FF0000);
			}
			i++;
		}
		j++;
	}
}

int draw_map(t_info *const info)
{
	int x;
	int y;

	y = 0;
	while (y<(int)info->game.map.height)
	{
		x = 0;
		while (x<(int)info->game.map.width)
		{
			if (info->game.map.pars[y][x] == '1')
				map_rectangle(info, x, y);
			x++;
		}
		y++;
	}
	map_circle(info, info->game.first_person.pos.x, info->game.first_person.pos.y);
	return (0);
}
























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
	printf("rgb_floor: [%d, %d, %d]\n", info->objects.rgb_floor.red, \
										info->objects.rgb_floor.green, \
										info->objects.rgb_floor.blue);
	printf("rgb_ceiling: [%d, %d, %d]\n", info->objects.rgb_ceiling.red, \
										info->objects.rgb_ceiling.green, \
										info->objects.rgb_ceiling.blue);
	printf("width: %zu,  height: %zu\n", info->game.map.width, \
										info->game.map.height);
	printf("view direct: %lf\n", info->game.first_person.pov);
	printf("pos_x: %lf,   pos_y: %lf\n", info->game.first_person.pos.x, \
										info->game.first_person.pos.y);
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
				printf("n");
			else
				printf("@");

		}
		printf("|\n");
	}
}










//MLX_TESTCODE	(order: {EVENT(hook) -> LOGIC} -> UPDATE -> {CLEAR -> PRINT})

# define PIXEL (64)

void	put_imgs(t_info *const info, int x, int y)
{
(void)x;
(void)y;
/*
	const int	x_coordinate = PIXEL * x;
	const int	y_coordinate = PIXEL * y;
	const void	*img_ptr = info->objects.north_wall.ptr;

	mlx_put_image_to_window(info->sys.mlx_ptr, info->sys.win_ptr, \
		(void *)img_ptr, x_coordinate, y_coordinate);
	
	//print_pixel_line
	for (int xline = 150; xline < 300; ++xline)
		mlx_pixel_put(info->sys.mlx_ptr, info->sys.win_ptr, xline, 150, ((200 << 16) + (10 << 8) + 100));
*/
	draw_map(info);
}

int	hook_click_x(t_info *const info)
{
	exit_process(NULL, EXIT_SUCCESS, info, 0);
	return (0);
}

int	key_press(int key, t_info *const info)
{
	if (key == key_w)
		info->game.first_person.pos.y -= 1;
	else if (key == key_s)
		info->game.first_person.pos.y += 1;
	else if (key == key_a)
		info->game.first_person.pos.x -= 1;
	else if (key == key_d)
		info->game.first_person.pos.x += 1;
	else if (key == key_esc)
		exit_process(NULL, EXIT_SUCCESS, info, 0);
	return (0);
}






int	loop_hook(t_info *const info)
{
	mlx_hook(info->sys.win_ptr, event_destroy_notify, 0L, hook_click_x, info);
	//key_release는 필요 없을지도..?
	mlx_hook(info->sys.win_ptr, event_key_press, 0L, &key_press, info);

	mlx_clear_window(info->sys.mlx_ptr, info->sys.win_ptr);
	put_imgs(info, info->game.first_person.pos.x, info->game.first_person.pos.y);
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
		64 * 20, 64 * 10, "TESTCODE");
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































