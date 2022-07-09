#include "../includes/fdf.h"

int	main(int argc, char *argv[])
{
	t_map	*map_info;

	map_info = init(argc, argv);
	exit(EXIT_SUCCESS);
}

//__attribute__((destructor)) static void destructor()
//{
//    system("leaks -q fdf");
//}
