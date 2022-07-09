#include "../includes/fdf.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	window_init(void)
{
	t_mlx	mlx;
	t_img	img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1200, 800, "fdf");
	mlx_hook(mlx.win, KEY_PRESS, 1L << 0, close_window_with_esc, &mlx);
	mlx_hook(mlx.win, DESTROY_NOTIFY, 1L << 17, close_window_with_button, &mlx);

	img.img = mlx_new_image(mlx.mlx, 1200, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
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
