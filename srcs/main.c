#include "fdf.h"

int	main(void)
{
	t_info	*info;

	info = (t_info *)ft_malloc_exit(sizeof(t_info));
	init_mlx(info);

	exit(EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	t_info	*info;

// 	if (!is_cmdline_argument_valid(argc, argv))
// 		exit(EXIT_FAILURE);
// 	info = ft_malloc_exit(sizeof(t_info));
// 	initialize_map(info, argv[1]);
// 	print_map(info->map);
// 	exit (EXIT_SUCCESS);
// }

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fdf");
// }
