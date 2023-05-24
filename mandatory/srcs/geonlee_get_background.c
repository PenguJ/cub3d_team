#include "../includes/cub3d.h"

void	draw_background(t_info *info)
{
	char	*dst;
	int		y;
	int		x;
	
	y = 0;
	while (y < 720)
	{
		x = 0;
		while (x < 1080)
		{
			dst = info->screen.addr + (y * info->screen.line_length + x * \
			(info->screen.bits_per_pixel / 8));
			if (y < 360)
				*(unsigned int*)dst = info->objects.rgb_ceiling.rgb + (256 * 256 * 256 * ((y * 255) / 360));
			else
				*(unsigned int*)dst = info->objects.rgb_floor.rgb + (256 * 256 * 256 * (((720 - y) * 255) / 360));
			x++;
		}
		y++;
	}
}

void	get_screen_img(t_info *info)
{
	info->screen.img = mlx_new_image(info->sys.mlx_ptr, 1080, 720);
	info->screen.addr = mlx_get_data_addr(info->screen.img, &info->screen.bits_per_pixel, \
	&info->screen.line_length, &info->screen.endian);
	draw_background(info);
}

//TEST

// int main()
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	t_screen	screen;
//     int floor_color;
//     int ceiling_color;
//     // floor_color = t_info->objects.rgb_floor.rgb;
//     // ceiling_color = t_info->objects.rgb_ceiling.rgb;
//     floor_color = 0x000DBFA2;
//     ceiling_color = 0x00AAAAAA;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 1080, 720,"tests");
// 	screen.img = mlx_new_image(mlx_ptr, 1080, 720); // 이미지 객체 생성
// 	screen.addr = mlx_get_data_addr(screen.img, &screen.bits_per_pixel, &screen.line_length, &screen.endian); // 이미지 주소 할당
//     draw_screen(&screen, floor_color, ceiling_color);
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, screen.img, 0, 0);
// 	free(screen.addr);
// 	mlx_loop(mlx_ptr);
// 	system("leaks cub3D");
// 	return (0);
// }