#include "fdf.h"

void	print_map(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			printf("i: %zu, j:%zu, ", x, y);
			printf("x: %d, y: %d, z: %d, color: %d\n",
				map->coordinates[y][x].x,
				map->coordinates[y][x].y,
				map->coordinates[y][x].z,
				map->coordinates[y][x].color);
			x++;
		}
		y++;
	}
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)dest = color;
}

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
