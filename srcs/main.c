#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	*map;

	if (!is_command_line_args_valid(argc))
		exit(EXIT_FAILURE);
	map = init_map(argv[1]);
	deallocate_map(map);
	exit(EXIT_SUCCESS);
}
