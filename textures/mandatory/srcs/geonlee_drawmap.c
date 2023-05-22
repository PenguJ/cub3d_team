#include "../includes/cub3d.h"

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
				mlx_pixel_put(info->sys.mlx_ptr, info->sys.win_ptr, (x * 10) + i , (y * 10) + j, 0x00FF0000);
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
	while (y<info->game.map.height)
	{
		x = 0;
		while (x<info->game.map.width)
		{
			if (info->game.map.pars[y][x] == '1')
				map_rectangle(info, x, y);
			x++;
		}
		y++;
	}
	map_circle(info, 5, 5);
}