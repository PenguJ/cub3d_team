typedef struct s_background
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_background;

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void    draw_background(t_background *background, int floor_color, int ceiling_color)
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
			dst = background->addr + (y * background->line_length + x * (background->bits_per_pixel / 8));
			if (y < 360)
	        	*(unsigned int*)dst = ceiling_color + (256 * 256 * 256 * ((y * 255) / 360));
			else
				*(unsigned int*)dst = floor_color + (256 * 256 * 256 * (((720 - y) * 255) / 360));
			x++;
		}
		y++;
	}
}

// void *get_background_img(t_info *info)
// {
// 	void *bg;
// 	char *addr;
// 	bg = mlx_new_image(info->sys.win_ptr, 1080, 720);
// 	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length, &background.endian);
// }

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_background	background;
    int floor_color;
    int ceiling_color;
    // floor_color = t_info->objects.rgb_floor.rgb;
    // ceiling_color = t_info->objects.rgb_ceiling.rgb;
    floor_color = 0x000DBFA2;
    ceiling_color = 0x00AAAAAA;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1080, 720,"tests");
	background.img = mlx_new_image(mlx_ptr, 1080, 720); // 이미지 객체 생성
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length, &background.endian); // 이미지 주소 할당
    draw_background(&background, floor_color, ceiling_color);
	mlx_put_image_to_window(mlx_ptr, win_ptr, background.img, 0, 0);
	free(background.addr);
	mlx_loop(mlx_ptr);
	system("leaks cub3D");
	return (0);
}