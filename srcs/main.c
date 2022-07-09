#include "../includes/fdf.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

void	window_init(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 700, 500, "fdf");
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
