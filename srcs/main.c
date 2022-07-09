#include "../includes/fdf.h"

void	window_init(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1200, 800, "fdf");
	mlx_hook(mlx.win, KEY_PRESS, 1L << 0, close_window_with_esc, &mlx);
	mlx_hook(mlx.win, DESTROY_NOTIFY, 1L << 17, close_window_with_button, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(void)
{
	window_init();
}

//int	main(int argc, char *argv[])
//{
//	t_map	*map_info;
//
//	map_info = init(argc, argv);
//	load_map(argv[1], map_info);
//	print_points(map_info);
//	exit(EXIT_SUCCESS);
//}

//__attribute__((destructor)) static void destructor()
//{
//    system("leaks -q fdf");
//}
