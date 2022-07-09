#include "../includes/fdf.h"

int	calc_color(double l, double d, int color1, int color2)
{
	double	ret;

	ret = (color2 - color1) * l / d;
	return (ret);
}

double	calculate_scale(t_map *map_info)
{
	double	scale_x;
	double	scale_y;

	scale_x = 1000.0 / map_info->width;
	scale_y = 600.0 / map_info->height;
	if (scale_x < scale_y)
		return (scale_x);
	else
		return (scale_y);
}

void	draw_line(t_img *img, double scale, t_point *p1, t_point *p2)
{
	double	dx;
	double	dy;
	double	theta;
	double	d;
	double	l;

	dx = scale * (p2->x - p1->x);
	dy = scale * (p2->y - p1->y);
	theta = atan2(dy, dx);
	d = sqrt(dx * dx + dy * dy);
	l = 0;
	while (l < d)
	{
		my_mlx_pixel_put(img,
			p1->x * scale + l * cos(theta),
			p1->y * scale + l * sin(theta),
			0x00FFFFFF);
		l++;
	}
}

void	connect_other_points(
		t_img *img, t_map *map_info, size_t index_x, size_t index_y)
{
	t_point	**map;
	double	scale;

	map = map_info->map;
	scale = calculate_scale(map_info);
	if (index_y + 1 < map_info->height)
		draw_line(img, scale, &map[index_y][index_x],
			&map[index_y + 1][index_x]);
	if (index_x + 1 < map_info->width)
		draw_line(img, scale, &map[index_y][index_x],
			&map[index_y][index_x + 1]);
	if (0 < index_y)
		draw_line(img, scale, &map[index_y - 1][index_x],
			&map[index_y][index_x]);
	if (0 < index_x)
		draw_line(img, scale, &map[index_y][index_x - 1],
			&map[index_y][index_x]);
}

void	print_grid(t_map *map_info, t_mlx *mlx, t_img *img)
{
	size_t	y;
	size_t	x;
	t_point	**map;

	map = map_info->map;
	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			connect_other_points(img, map_info, x, y);
			x++;
		}
		y++;
	}
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = ft_malloc_or_exit(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1200, 800, "fdf");
	mlx_hook(mlx->win, KEY_PRESS, 1L << 0, close_window_with_esc, mlx);
	mlx_hook(mlx->win, DESTROY_NOTIFY, 1L << 17, close_window_with_button, mlx);
	return (mlx);
}

int	main(int argc, char *argv[])
{
	t_map	*map_info;
	t_mlx	*mlx;
	t_img	img;

	map_info = init(argc, argv);
	load_map(argv[1], map_info);
	mlx = init_mlx();
	img.img = mlx_new_image(mlx->mlx, 1000, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	print_grid(map_info, mlx, &img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 100, 100);
	mlx_loop(mlx->mlx);
	exit(EXIT_SUCCESS);
}

//int	main(void)
//{
//	window_init();
//}

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
