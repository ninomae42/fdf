#include "../includes/fdf.h"

int	main(int argc, char *argv[])
{
	t_map	*map_info;

	map_info = init(argc, argv);
	load_map(argv[1], map_info);
	print_points(map_info);
	exit(EXIT_SUCCESS);
}

//__attribute__((destructor)) static void destructor()
//{
//    system("leaks -q fdf");
//}
