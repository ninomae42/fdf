#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (!is_command_line_args_valid(argc))
		exit(EXIT_FAILURE);
	info.map = init_map(argv[1]);
	init_mlx(&info);
	exit(EXIT_SUCCESS);
}
