#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (!is_command_line_args_valid(argc))
		exit(EXIT_FAILURE);
	ft_memset(&map, 0, sizeof(t_map));
	set_map_width_height(argv[1], &map);
	printf("row: %zu, col: %zu\n", map.rows, map.cols);
	map.points = (t_point *)ft_malloc(sizeof(t_point) * (map.rows * map.cols));
	ft_memset(map.points, 0, (sizeof(t_point) * (map.rows * map.cols)));
	read_map(argv[1], &map);
	print_map(&map);
	free(map.points);
	exit(EXIT_SUCCESS);
}
