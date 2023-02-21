#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (!is_command_line_args_valid(argc))
		exit(EXIT_FAILURE);
	info.map = init_map(argv[1]);
	info.draw_map = copy_map(info.map);
	info.state = state_init();
	init_mlx(&info);
	exit(EXIT_SUCCESS);
}
// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fdf");
// }
