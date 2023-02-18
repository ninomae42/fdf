#include "fdf.h"

// int	main(void)
// {
// 	t_info	*info;

// 	info = (t_info *)ft_malloc_exit(sizeof(t_info));
// 	init_mlx(info);

// 	exit(EXIT_SUCCESS);
// }

void	scale_map(t_info *info, double scale);
void	translate_map(t_info *info, int trans_x, int trans_y);
void	convert_to_iso(t_info *info);

int	main(int argc, char **argv)
{
	t_info	*info;

	if (!is_cmdline_argument_valid(argc, argv))
		exit(EXIT_FAILURE);
	info = ft_malloc_exit(sizeof(t_info));
	initialize_map(info, argv[1]);
	print_map(info->map);
	scale_map(info, 10);
	puts("map scaled");
	convert_to_iso(info);
	puts("map converted to isometric");
	translate_map(info, 200, 200);
	puts("map translated");
	init_mlx(info);
	exit (EXIT_SUCCESS);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fdf");
// }
