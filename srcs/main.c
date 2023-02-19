#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_mlx	*mlx;

	if (!is_command_line_args_valid(argc))
		exit(EXIT_FAILURE);
	map = init_map(argv[1]);
	mlx = init_mlx(map);
	deallocate_mlx(mlx);
	deallocate_map(map);
	exit(EXIT_SUCCESS);
}
