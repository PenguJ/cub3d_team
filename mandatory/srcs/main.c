/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:28:57 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/22 16:03:22 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_arg_exception(int argc, char *argv[])
{
	char	*loc_of_last_dot;

	if (argc != VALID_ARGC_NUM)
	{
		exit_process("input one argument!", STDERR_FILENO, NULL, 0);
	}
	loc_of_last_dot = ft_strrchr(argv[1], '.');
	if (!loc_of_last_dot || \
		ft_strlen(loc_of_last_dot) != 4 || \
		ft_strncmp(loc_of_last_dot, ".cub", 4))
	{
		exit_process("wrong extention!", STDERR_FILENO, NULL, 0);
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;

	check_arg_exception(argc, argv);
	init_info(&info);
	parse_info(&info, argv[1]);

printInfo(&info);
mlxTest(&info);

	//game()
	exit_process(NULL, EXIT_SUCCESS, &info, 0);
}
