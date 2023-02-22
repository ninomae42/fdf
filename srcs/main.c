/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:47:56 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 17:21:33 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (!is_command_line_args_valid(argc, argv))
		exit(EXIT_FAILURE);
	info.map = init_map(argv[1]);
	if (info.map == NULL)
		exit(EXIT_FAILURE);
	info.draw_map = copy_map(info.map);
	info.state = state_init();
	init_mlx(&info);
	exit(EXIT_SUCCESS);
}
// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fdf");
// }
