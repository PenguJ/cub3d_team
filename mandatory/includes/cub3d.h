/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegeonha <leegeonha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:03:31 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/26 08:03:45 by leegeonha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//includes HeaderFile
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

//define & typedef
# define VALID_ARGC_NUM (2)
# define FOV_HALF_SCALAR (0.66)
# define ANGLE_5 (M_PI / 36)

typedef enum e_obj_id
{
	id_floor,
	id_ceiling,
	id_north_wall,
	id_south_wall,
	id_east_wall,
	id_west_wall
}	t_obj_id;

typedef struct s_info
{
	struct s_game
	{
		struct s_map
		{
			size_t	width;
			size_t	height;
			char	**pars;				//is_allocated
		}	map;
		struct s_fp
		{
			struct s_pov
			{
				double	initial_dv_x;
				double	initial_dv_y;
				double	dv_x;
				double	dv_y;
				int		cnt;
			}		pov;
			struct s_fov
			{
				double	plain_x;
				double	plain_y;
				double	camera_coor_oper;
				double	ray_dv_x;
				double	ray_dv_y;
				double	pos_dist_x;
				double	pos_dist_y;
				double	side_dist_x;
				double	side_dist_y;
				double	delta_dist_x;
				double	delta_dist_y;
				double	perp_wall_dist;
				int		line_height;
			}		fov;
			struct s_pos
			{
				double	x;
				double	y;
			}		pos;
		}	fp;
	}	game;
	struct s_objects
	{
		struct s_rgb_floor
		{
			bool	is_init;
			int		red;
			int		green;
			int		blue;
			int		rgb;
		}	rgb_floor;
		struct s_rgb_ceiling
		{
			bool	is_init;
			int		red;
			int		green;
			int		blue;
			int		rgb;
		}	rgb_ceiling;
		struct s_north_wall
		{
			char	*file;				//is_allocated
			int		cols;
			int		rows;
			void	*ptr;				//will_be_destroyed
		}	north_wall;
		struct s_south_wall
		{
			char	*file;				//is_allocated
			int		cols;
			int		rows;
			void	*ptr;				//will_be_destroyed
		}	south_wall;
		struct s_east_wall
		{
			char	*file;				//is_allocated
			int		cols;
			int		rows;
			void	*ptr;				//will_be_destroyed
		}	east_wall;
		struct s_west_wall
		{
			char	*file;				//is_allocated
			int		cols;
			int		rows;
			void	*ptr;				//will_be_destroyed
		}	west_wall;
		struct s_minimap_wall
		{
			int		cols;
			int		rows;
			void	*ptr;				//will_be_destroyed
		}	minimap_wall;
		struct s_minimap_point			//just for visualizerTesting
		{
			int		cols;
			int		rows;
			void	*ptr;				//will_be_destroyed
		}	minimap_point;
	}	objects;
	struct s_sys
	{
		enum e_x11_event
		{
			event_key_press = 2,
			event_key_release = 3,
			event_destroy_notify = 17
		}	x11_event;
		enum e_x11_mask
		{
			mask_key_press = 1L<<0,
			mask_key_release = 1L<<1
		}	x11_mask;
		enum e_key_code
		{
			key_w = 13,
			key_a = 0,
			key_s = 1,
			key_d = 2,
			key_left = 123,
			key_right = 124,
			key_esc = 53
		}	key_code;
		enum e_window_size
		{
			win_width = 1080,
			win_height = 720
		}	window_size;
		void	*mlx_ptr;				//will_be_destroyed...?(can occur leaks)
		void	*win_ptr;				//will_be_destroyed
	}	sys;
	struct s_screen
	{
		void	*img;					//will_be_destroyed
		char	*addr;					//is_allocated..? maybe..
		int		bits_per_pixel;
		int		line_length;
		int		endian;
	}	screen;
}	t_info;

//declares Functions
//>>>>>>>>>>>>>>>>>>TESTCODE.c (must be deleted!)<<<<<<<<<<<<<<<<<<<
void	check_leaks(void);
void	printInfo(t_info *const info);
void	put_minimap(t_info *const info);

//		exit_process.c
void	exit_process(char *msg, int exit_code, t_info *const info, int fd);

//		init_s_info.c	(must be fixed! not complete!)
void	init_info(t_info *const info);

//		parse_info.c
int		skip_space(int fd, char *buf);
void	parse_info(t_info *const info, char *file_name);

//		parse_objs.c
void	parse_objs(t_info *const info, int fd, char *buf);

//		parse_objs__rgb.c
void	get_rgb(t_info *const info, int fd, char *buf, t_obj_id id);

//		parse_objs__texture.c
void	get_texfile(t_info *const info, int fd, char *buf, enum e_obj_id id);

//		parse_map.c
void	parse_map(t_info *const info, int fd, char *buf);

//		parse_map__check_map.c
void	check_map_validation(t_info *const in, size_t x, size_t y, \
							bool is_dir);

//		parse_map__get_map0.c
void	get_map(t_info *const info, int fd, char *buf);

//		parse_map__get_map1.c
void	flag_booleans(char c, bool *is_overlap_nl, bool *is_emptyline_sp);
t_state	check_continuable(bool *is, char c, char **map_line);
void	check_valid_eof(t_info *const info, int fd, bool *is, char **m);
void	get_joined_map(t_info *const info, int fd, char *buf, \
					char **out_map_line);

//		parse_utility.c
bool	is_direction(char c);
bool	is_valid_elem(char c);

//		create_mlx_win_imgs.c
void	create_mlx_win_imgs(t_info *const info);

//		create_screen_img.c
void	create_screen_img(t_info *const info);
void	draw_background(t_info *const info);
void	draw_black_background(t_info *const info);

//		game.c
void	game(t_info *const info);
void	draw_screen_img(t_info *const info);
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
//(filename).c
#endif