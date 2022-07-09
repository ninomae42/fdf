#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	calc_color(double l, double d, int color1, int color2)
{
	double	ret;

	ret = (color2 - color1) * l / d;
	return (ret);
}

void	draw_line(t_img *img, t_point *p1, t_point *p2)
{
	double	dx;
	double	dy;
	double	theta;
	double	d;
	double	l;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	theta = atan2(dy, dx);
	d = sqrt(dx * dx + dy * dy);
	l = 0;
	while (l < d)
	{
		my_mlx_pixel_put(img,
			p1->x + l * cos(theta),
			p1->y + l * sin(theta),
			calc_color(l, d, p1->color, p2->color));
		l++;
	}
}

void	window_init(void)
{
	t_mlx	mlx;
	t_img	img;
	t_point	p1;
	t_point	p2;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1200, 800, "fdf");
	mlx_hook(mlx.win, KEY_PRESS, 1L << 0, close_window_with_esc, &mlx);
	mlx_hook(mlx.win, DESTROY_NOTIFY, 1L << 17, close_window_with_button, &mlx);

	img.img = mlx_new_image(mlx.mlx, 1200, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);

	p1.x = 100;
	p1.y = 100;
	p1.color = 0x00FFFFFF;
	p2.x = 200;
	p2.y = 100;
	p1.color = 0x0000FF00;
	draw_line(&img, &p1, &p2);

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
