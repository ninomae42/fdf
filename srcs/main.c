#include "../includes/fdf.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

#define KEY_PRESS 2
#define ESC_KEY 65307
#define DESTROY_NOTIFY 17

int	close_window(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window_with_button(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	window_init(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1200, 800, "fdf");
	mlx_hook(mlx.win, KEY_PRESS, 1L << 0, close_window, &mlx);
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
